#include "CommitteeInformation.h"
#include "AddTask.h"
#include <QtGui>
#include <QtSql>
#include <QItemSelectionModel>
#include <QModelIndex>
// flag for QDebug() statements
const int DEBUG = 1;

QSqlTableModel *Tmodel;
QString committeeName;

CommitteeInformation::CommitteeInformation(QString committee){
	committeeName = committee;
	setupUi(this);

	Tmodel = new QSqlTableModel(this);
	Tmodel->setTable("tasks");
	
	Tmodel->setHeaderData(1, Qt::Horizontal, tr("Name"));
	Tmodel->setHeaderData(2, Qt::Horizontal, tr("Complete?"));
	Tmodel->setHeaderData(3, Qt::Horizontal, tr("Annual?"));
	
	Tmodel->select();
	
	taskView->setModel(Tmodel);
	
	// hide all columns except name
	taskView->setColumnHidden(0, true);
	taskView->setColumnHidden(2, true);
	taskView->setColumnHidden(3, true);
	
	QHeaderView * header = taskView->horizontalHeader();
	header->setStretchLastSection(true);

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
	AddTask *at = new AddTask(committeeName,this);
	at->show();
}
void CommitteeInformation::refreshTask(){
	Tmodel->select();
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
