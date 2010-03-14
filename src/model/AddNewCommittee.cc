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
	connect( chairSelectButton, SIGNAL(clicked()), this, SLOT (selectChair()));
	connect( secretarySelectButton, SIGNAL(clicked()), this, SLOT (selectSecretary()));
}

void AddNewCommittee::selectChair(){
	// display all the users, the user picks one. put into the chairEdit field
}

void AddNewCommittee::selectSecretary(){
	// display all the users, the user picks one. put into the secretaryEdit field
}

void AddNewCommittee::save() {
	bool chairValid = false;
	bool secretaryValid = false;

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
			QString committeeQueryText = "SELECT name FROM committees WHERE chair_id ='" + chairID + "'";
			QSqlQuery committeeQuery(committeeQueryText);

			if(committeeQuery.next()){
				QMessageBox::question(0, qApp->tr("Confirm reassigning chair or secretary"),
					qApp->tr("You are reassigning someone who is a already a committee chair or secretary to be this committee's chair.\n Are you sure you want to do this?"),
					QMessageBox::Yes | QMessageBox::No);
			}

			// get confirmation from box, delete chair from the other committee.

			// set valid to true for insertion later
			chairValid = true;

		} else {
			QMessageBox::warning(0, qApp->tr("Error"),
				qApp->tr("Chair username does not match any resident.\n"),
				QMessageBox::Ok);
			//chairID = NULL;
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
			secretaryID = secretaryQuery.value(0).toInt();
			// if the selected person is chairing or secretary of a different committee, 
			// ask for confirmation. then update the other committee to show the secretary is vacant.

			// not done yet....
	
			secretaryValid = true;
		} else {
			QMessageBox::warning(0, qApp->tr("Error"),
			qApp->tr("Secretary username does not match any resident.\n"),
			QMessageBox::Ok);
		}

		if(DEBUG == 1){
			qDebug() << secretaryID;
		}

		// everything okay, create a new entry in the database
		if(chairValid && secretaryValid){
			
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
