/*
*	A prototype main screen
*/
#include <QtGui>
#include "PrototypeMainScreen.h"
#include "CreateUser.h"
#include "AddNewCommittee.h"
#include "EditCommittees.h"
#include "EditUser.h"
#include "ViewPhone.h"
	QString user;
PrototypeMainScreen::PrototypeMainScreen(QString username){
	setupUi(this);
	user = username;
	connect(AddCommitteeButton,SIGNAL(clicked()),this,SLOT(addCommittee()));
	connect(AddMemberButton,SIGNAL(clicked()),this,SLOT(addMember()));
	connect(PrintPrivatePhoneButton,SIGNAL(clicked()),this,SLOT(printPrivate()));
	connect(PrintPublicPhoneButton,SIGNAL(clicked()),this,SLOT(printPublic()));
	connect(ViewCommitteesButton,SIGNAL(clicked()),this,SLOT(editCommit()));
	connect(ViewMemberInfoButton,SIGNAL(clicked()),this,SLOT(viewMembers()));
	connect(ExitButton,SIGNAL(clicked()),this,SLOT(close()));
	
	if(username != "coord"){
		AddMemberButton->setEnabled(false);
		PrintPrivatePhoneButton->setEnabled(false);
		ViewCommitteesButton->setEnabled(false);
		AddCommitteeButton->setEnabled(false);
	}
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
	ViewPhone *vp = new ViewPhone(this, true);
	vp->show();
}

void PrototypeMainScreen::printPublic(){
	ViewPhone *vp = new ViewPhone(this, false);
	vp->show();
}

void PrototypeMainScreen::editCommit(){
	EditCommittees *eCommit = new EditCommittees(this);
	eCommit->show();
}

void PrototypeMainScreen::viewMembers(){
	EditUser *edUsr = new EditUser(this, user);
	edUsr->show();
}
