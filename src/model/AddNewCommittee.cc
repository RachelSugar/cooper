/*
* Contains methods to add a new committee
*/

#include "AddNewCommittee.h"
#include <QtGui>
#include <QSqlQuery>

const QString none = "";


// flag for extra printing
const int DEBUG = 1;

AddNewCommittee::AddNewCommittee(QWidget *parent){

	setupUi(this);

	if(DEBUG == 1){
		qDebug() << "Setting up box";
	}
	
	connect( acceptRejectButtons, SIGNAL( rejected()), this, SLOT ( close()));
	connect( acceptRejectButtons, SIGNAL( accepted()), this, SLOT ( save()));
}

void AddNewCommittee::save() {
	bool chairValid = false;
	bool secretaryValid = false;

	bool deleteChairIsChair = false;
	bool deleteChairIsSecretary = false;
	bool deleteSecretaryIsChair = false;
	bool deleteSecretaryIsSecretary = false;

	QString chairID = 0;
	QString secretaryID = 0;

	// extract the name of the committee
	QString name = nameEdit->text();

	if(DEBUG == 1){
		qDebug() << name;
	}

	// check if committee name is empty
	if(name == none){
		QMessageBox::warning(0, qApp->tr("Error"),
			qApp->tr("Committee name cannot be empty.\n"),
			QMessageBox::Ok);
	} else {

	// name not empty, check if committee name already in use  -- ignores case
	QString text = "SELECT id FROM committees WHERE name = '" + name + "' COLLATE NOCASE";
	QSqlQuery nameQuery(text);

	// name already in use, display error
	if(nameQuery.next()){
		QMessageBox::warning(0, qApp->tr("Error"),
			qApp->tr("This committee name is already in use.\n"),
			QMessageBox::Ok);
	} else {
	// otherwise, continue error checking

		// extract the chair and secretary names !! this string is not formatted in any way!!
		QString chair = chairEdit->text();
		QString secretary = secretaryEdit->text();

		if(DEBUG == 1){
			qDebug() << chair;
		}

		// find the key associated with this name in the "users" table -- ignores case
		QString chairQueryText = "SELECT id FROM users WHERE user_name = '" + chair + "' COLLATE NOCASE";
		QSqlQuery chairQuery(chairQueryText);

		if(chairQuery.next()){
			chairID = chairQuery.value(0).toString();
			// if the selected person is chairing or secretary of a different committee, 
			// ask for confirmation. then update the other committee to show the chair is vacant.
			QString chairIsChairText = "SELECT id FROM committees WHERE chair_id ='" + chairID + "'";
			QSqlQuery chairIsChairQuery(chairIsChairText);

			QString chairIsSecretaryText = "SELECT id FROM committees WHERE secretary_id ='" + chairID + "'";
			QSqlQuery chairIsSecretaryQuery(chairIsSecretaryText);

			// selected person is chairing a committee
			if(chairIsChairQuery.next()){
				int ret = QMessageBox::question(0, qApp->tr("Confirm reassigning chair"),
					qApp->tr("The person you selected to chair this new committee is chairing an existing committee.\nContinuing will leave the chair of that committee open. Continue?"),
					QMessageBox::Yes | QMessageBox::Cancel);

				deleteChairIsChair = (ret == QMessageBox::Yes);
				if(deleteChairIsChair)
					chairValid = true;
			} 
			// selected person is secretary of a committee
			else if(chairIsSecretaryQuery.next()){
				int ret = QMessageBox::question(0, qApp->tr("Confirm reassigning secretary to chair"),
					qApp->tr("The person you selected to chair this new committee is secretary of an existing committee.\nContinuing will leave the secretary of that committee open. Continue?"),
					QMessageBox::Yes | QMessageBox::Cancel);
				deleteChairIsSecretary = (ret == QMessageBox::Yes);
				if(deleteChairIsSecretary)
					chairValid = true;
			} else {
				chairValid = true;
			}

		} else {
			QMessageBox::warning(0, qApp->tr("Error"),
				qApp->tr("Chair username does not match any resident.\n"),
				QMessageBox::Ok);
		}

		if(DEBUG == 1){
			qDebug() << chairID;
		}

		if(DEBUG == 1){
			qDebug() << secretary;
		}

		// find the key associated with this name in the "users" table -- ignores case
		QString secretaryQueryText = "SELECT id FROM users WHERE user_name = '" + secretary + "' COLLATE NOCASE";
		QSqlQuery secretaryQuery(secretaryQueryText);

		if(secretaryQuery.next()){
			secretaryID = secretaryQuery.value(0).toString();
			// if the selected person is chairing or secretary of a different committee, 
			// ask for confirmation. then update the other committee to show the secretary is vacant.
			QString secretaryIsChairText = "SELECT id FROM committees WHERE chair_id ='" + secretaryID + "'";
			QSqlQuery secretaryIsChairQuery(secretaryIsChairText);

			QString secretaryIsSecretaryText = "SELECT id FROM committees WHERE secretary_id ='" + secretaryID + "'";
			QSqlQuery secretaryIsSecretaryQuery(secretaryIsSecretaryText);

			// selected person is chairing a committee
			if(secretaryIsChairQuery.next()){
				int ret = QMessageBox::question(0, qApp->tr("Confirm reassigning chair to secretary"),
					qApp->tr("The person you selected to be the secretary of this new committee is chairing an existing committee.\nContinuing will leave the chair of that committee open. Continue?"),
					QMessageBox::Yes | QMessageBox::Cancel);

				deleteSecretaryIsChair = (ret == QMessageBox::Yes);
				if(deleteSecretaryIsChair)
					secretaryValid = true;
			}
			// selected person is secretary of a committee
			else if(secretaryIsSecretaryQuery.next()){
				int ret = QMessageBox::question(0, qApp->tr("Confirm reassigning secretary"),
					qApp->tr("The person you selected to be the secretary of this new committee is secretary of an existing committee.\nContinuing will leave the secretary of that committee open. Continue?"),
					QMessageBox::Yes | QMessageBox::Cancel);
				deleteSecretaryIsSecretary = (ret == QMessageBox::Yes);
				if(deleteSecretaryIsSecretary)
					secretaryValid = true;
			} else {
				secretaryValid = true;
			}

		} else {
			QMessageBox::warning(0, qApp->tr("Error"),
			qApp->tr("Secretary username does not match any resident.\n"),
			QMessageBox::Ok);
		}

		if(DEBUG == 1){
			qDebug() << secretaryID;
		}

		// check if chair and secretary are the same person
		if(chairID == secretaryID && chairID != 0){
			QMessageBox::warning(0, qApp->tr("Error"),
			qApp->tr("The chair and secretary cannot be the same person.\n"),
			QMessageBox::Ok);

			chairValid = false;
			secretaryValid = false;
		}

		// everything okay, delete former secretaries/chairs, then insert new entry
		if(chairValid && secretaryValid){
			
			if(deleteChairIsChair){
				QString deleteOldText = "UPDATE committees SET chair_ID = 'EMPTY' WHERE chair_ID = '" + chairID + "'";
				QSqlQuery deleteOld(deleteOldText);
			} else if(deleteChairIsSecretary){
				QString deleteOldText = "UPDATE committees SET secretary_ID = 'EMPTY' WHERE secretary_ID = '" + chairID + "'";
				QSqlQuery deleteOld(deleteOldText);
			}
			
			if(deleteSecretaryIsChair){
				QString deleteOldText = "UPDATE committees SET chair_ID = 'EMPTY' WHERE chair_ID = '" + secretaryID + "'";
				QSqlQuery deleteOld(deleteOldText);
			} else if(deleteSecretaryIsSecretary) {
				QString deleteOldText = "UPDATE committees SET secretary_ID = 'EMPTY' WHERE secretary_ID = '" + secretaryID + "'";
				QSqlQuery deleteOld(deleteOldText);
			}

			// insert the new values
			QSqlQuery query;
			qDebug() << query.prepare("INSERT INTO committees VALUES(NULL, :name, :chairID, :secretaryID)");
			query.bindValue(":name", name);
			query.bindValue(":chairID", chairID);
			query.bindValue(":secretaryID", secretaryID);
			qDebug() << query.exec();

			// close the widget
			this->close();
			}
		}
	}
}
