#include "CommitteeInformation.h"
#include "AddTask.h"
#include <QtGui>
#include <QSqlQuery>

// flag for QDebug() statements
const int DEBUG = 1;

QString committeeName;

CommitteeInformation::CommitteeInformation(QString committee){
	committeeName = committee;
	setupUi(this);

	connect(addTaskButton, SIGNAL(clicked()), this, SLOT(addTask()));
	connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(deleteTaskButton, SIGNAL(clicked()), this, SLOT(deleteTask()));
	connect(markTaskCompletedButton, SIGNAL(clicked()), this, SLOT(markTaskCompleted()));
	connect(printCommitteeButton, SIGNAL(clicked()), this, SLOT(printCommittee()));
	connect(printTaskButton, SIGNAL(clicked()), this, SLOT(printTask()));
	connect(promoteChairButton, SIGNAL(clicked()), this, SLOT(promoteChair()));
	connect(promoteSecretaryButton, SIGNAL(clicked()), this, SLOT(promoteSecretary()));
	
	committeeNameLabel->setText(committeeName);
}
void CommitteeInformation::addTask(){
	AddTask *at = new AddTask(committeeName);
	at->show();
}
void CommitteeInformation::deleteTask(){
}
void CommitteeInformation::markTaskCompleted(){
}
void CommitteeInformation::printCommittee(){
}
void CommitteeInformation::printTask(){
}
void CommitteeInformation::promoteChair(){
}
void CommitteeInformation::promoteSecretary(){
}
