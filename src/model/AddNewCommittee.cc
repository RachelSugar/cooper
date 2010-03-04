/*
* Contains methods to add a new committee
* 04 Mar 10 - Displays main dialog, person selection not done yet, 
	no error checking done, no database accesses.
* 04 Mar 10, sometime later - database insertion done. also displays
		errors if input is empty. no checking for correctness
		of input.
  even later - have problem with storing a committee with no Chair, Secretary, or neither.
*
*/

#include "AddNewCommittee.h"
#include <QtGui>
#include <QSqlQuery>

const QString none = "";
const int noEntry = -1;

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
	// maybe check if committee name already in use

	// extract the chair and secretary names !! this string is not formatted in any way!!
	QString chair = chairEdit->text();
	QString secretary = secretaryEdit->text();

	int chairID = NULL;
	int secID = NULL;

	// if the name is not empty, check for conflicts and gets this name's key
	if(chair != none){
		// if the selected person is chairing or secretary of a different committee, 
		// ask for confirmation
		if(DEBUG == 1){
			qDebug() << chair;
		}

		// find the key associated with this name in the "users" table
		QString text = "SELECT id FROM users WHERE user_name = '" + chair + "'";
		QSqlQuery chairQuery(text);

		if(chairQuery.next()){
			chairID = chairQuery.value(0).toInt();
		}

		if(DEBUG == 1){
			qDebug() << chairID;
		}

	} 
	
	// if the name is not empty, check for conflicts and gets this name's key
	if(secretary != none){
		// if the selected person is chairing or secretary of a different committee, 
		// ask for confirmation
	
		if(DEBUG == 1){
			qDebug() << secretary;
		}

		// find the key associated with this name in the "users" table
		QString text = "SELECT id FROM users WHERE user_name = '" + secretary + "'";
		QSqlQuery secQuery(text);

		if(secQuery.next()){
			secID = secQuery.value(0).toInt();
		}

		if(DEBUG == 1){
			qDebug() << secID;
		}

	}

	// create a new entry in the database
	QSqlQuery query;
	query.prepare("INSERT INTO committees VALUES(NULL, :name, :chairID, :secID)");
	query.bindValue(":name", name);
	query.bindValue(":chairID", chairID);
	query.bindValue(":secID", secID);
	query.exec();

	// close the widget
	this->close();
	}
}
