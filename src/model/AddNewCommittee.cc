/*
* Contains methods to add a new committee
* 04 Mar 10 - Displays main dialog, person selection not done yet, 
	no error checking done, no database accesses.
*
*
*/

#include "AddNewCommittee.h"
#include <QtGui>

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
	// extract the name of the committee
	QString name = nameEdit->text();

	if(DEBUG == 1){
		qDebug() << name;
	}

	// see if the committee name is already in use
	// if it is, reprompt.
	

	// extract the chair and secretary names
	QString chair = chairEdit->text();
	QString secretary = secretaryEdit->text();

	bool storeChair = false;
	bool storeSecretary = false;

	// if the name is not empty, and there are no conflicts, store
	if(chair != none){
		// if the selected person is chairing or secretary of a different committee, 
		// ask for confirmation
		if(DEBUG == 1){
			qDebug() << chair;
		}

		// everything okay
		storeChair = true;
	}
	if(secretary != none){
		// if the selected person is chairing or secretary of a different committee, 
		// ask for confirmation
	
		if(DEBUG == 1){
			qDebug() << secretary;
		}

		// everything okay
		storeSecretary = true;
	}

	// create a new entry in the database

	// close the widget
	this->close();
}
