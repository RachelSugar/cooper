/*
* Contains methods to add a new committee
* 04 Mar 10 - Displays main dialog, person selection not done yet, 
	no error checking done, no database accesses.
*
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

	// see if the committee name is already in use
	// if it is, reprompt.
	if(name == none){
		QMessageBox::critical(0, qApp->tr("Error"),
			qApp->tr("Committee name cannot be empty.\n"),
			QMessageBox::Cancel);
	}
	

	// extract the chair and secretary names
	QString chair = chairEdit->text();
	QString secretary = secretaryEdit->text();

	int chairID;
	int secID;

	// if the name is not empty, check for conflicts
	if(chair != none){
		// if the selected person is chairing or secretary of a different committee, 
		// ask for confirmation
		if(DEBUG == 1){
			qDebug() << chair;
		}

	} else {
		chairID = noEntry;
	}

	if(secretary != none){
		// if the selected person is chairing or secretary of a different committee, 
		// ask for confirmation
	
		if(DEBUG == 1){
			qDebug() << secretary;
		}

	} else {
		secID = noEntry;
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
