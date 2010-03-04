/*
*	A prototype main screen
*/
#include <QtGui>
#include "PrototypeMainScreen.h"
#include "CreateUser.h"
#include "AddNewCommittee.h"

PrototypeMainScreen::PrototypeMainScreen(QWidget *parent){
	setupUi(this);

	connect(AddCommitteeButton,SIGNAL(clicked()),this,SLOT(addCommittee()));
	connect(AddMemberButton,SIGNAL(clicked()),this,SLOT(addMember()));
	connect(PrintPrivatePhoneButton,SIGNAL(clicked()),this,SLOT(printPrivate()));
	connect(PrintPublicPhoneButton,SIGNAL(clicked()),this,SLOT(printPublic()));
	connect(ViewCommitteesButton,SIGNAL(clicked()),this,SLOT(viewCommittees()));
	connect(ViewMemberInfoButton,SIGNAL(clicked()),this,SLOT(viewMembers()));
	connect(ExitButton,SIGNAL(clicked()),this,SLOT(close()));
}

void PrototypeMainScreen::addCommittee(){
	AddNewCommittee *commit = new AddNewCommittee(this);
	commit->show();
}

void PrototypeMainScreen::addMember(){
	CreateUser *create = new CreateUser(this);

    create->show();
}

void PrototypeMainScreen::printPrivate(){
}

void PrototypeMainScreen::printPublic(){
}

void PrototypeMainScreen::viewCommittees(){
}

void PrototypeMainScreen::viewMembers(){
}
