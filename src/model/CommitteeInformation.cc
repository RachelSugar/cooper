#include "CommitteeInformation.h"
#include "AddTask.h"
#include <QtGui>
#include <QtSql>
#include <QItemSelectionModel>
#include <QModelIndex>
// flag for QDebug() statements
const int DEBUG = 1;

QSqlTableModel *Tmodel;
QSqlTableModel *CLmodel;
QString committeeName;
QString userName;

CommitteeInformation::CommitteeInformation(QString committee, QString currentUser){
	committeeName = committee;
	userName = currentUser;

	qDebug() << "Current user is :" << userName;
	setupUi(this);

	Tmodel = new QSqlTableModel(this);
	Tmodel->setTable("tasks");

	QString getCommitteeNum = "SELECT id FROM committees WHERE name = '" + committeeName +"'";
	QString CommitteeNum;
	QSqlQuery query(getCommitteeNum);
	
	while ( query.next() ) {
		CommitteeNum = query.value(0).toString();
	}

	Tmodel->setFilter("committee_id = " + CommitteeNum);
	
	Tmodel->setHeaderData(1, Qt::Horizontal, tr("Name"));
	Tmodel->setHeaderData(4, Qt::Horizontal, tr("Complete?"));
	Tmodel->setHeaderData(5, Qt::Horizontal, tr("Due date"));
	Tmodel->setHeaderData(6, Qt::Horizontal, tr("Annual?"));
	
	Tmodel->select();
	
	taskView->setModel(Tmodel);
	
	// hide all columns except name
	taskView->setColumnHidden(0, true);
	taskView->setColumnHidden(2, true);
	taskView->setColumnHidden(3, true);
	
	QHeaderView *taskHeader = taskView->horizontalHeader();
	taskHeader->setStretchLastSection(true);

	// set up committee member table

	CLmodel = new QSqlTableModel(this);
	CLmodel->setTable("users");

	CLmodel->setFilter("committee_id = " + CommitteeNum);
	//CLmodel->setFilter("is_resident = 1");
	
	CLmodel->setHeaderData(1, Qt::Horizontal, tr("User name"));
	CLmodel->setHeaderData(4, Qt::Horizontal, tr("Last name"));
	CLmodel->setHeaderData(5, Qt::Horizontal, tr("First name"));
	
	CLmodel->select();
	
	constituentView->setModel(CLmodel);
	
	// hide all columns except username, last name, first name
	constituentView->setColumnHidden(0, true);
	constituentView->setColumnHidden(1, true);
	constituentView->setColumnHidden(3, true);
	constituentView->setColumnHidden(6, true);
	constituentView->setColumnHidden(7, true);
	constituentView->setColumnHidden(8, true);
	constituentView->setColumnHidden(9, true);
	constituentView->setColumnHidden(10, true);
	constituentView->setColumnHidden(11, true);
	constituentView->setColumnHidden(12, true);
	constituentView->setColumnHidden(13, true);
	constituentView->setColumnHidden(14, true);
	
	QHeaderView *constituentHeader = constituentView->horizontalHeader();
	constituentHeader->setStretchLastSection(true);

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

	// ask for confirmation first
	int ret = QMessageBox::question(this, qApp->tr("Confirm delete task"),
			qApp->tr("Are you sure you want to delete this task?.\n"),
			QMessageBox::Ok | QMessageBox::Cancel);
	
	if(ret == QMessageBox::Ok){
		QItemSelectionModel *selected = taskView->selectionModel();
		QModelIndex index = selected->currentIndex();

		Tmodel->removeRows(index.row(), 1, QModelIndex());
	}
}
void CommitteeInformation::markTaskCompleted(){
	QItemSelectionModel *selected = taskView->selectionModel();
	QModelIndex index = selected->currentIndex();

	QSqlRecord record = Tmodel->record(index.row());
	QString tID = record.value(0).toString();
	QString toChange = "UPDATE tasks\nSET is_complete=1\nWHERE id = "+tID; 
	QSqlQuery query;
	query.exec(toChange);
	Tmodel->select();
}
void CommitteeInformation::printCommittee(){
}
void CommitteeInformation::printTask(){
}
void CommitteeInformation::promoteChair(){
	// check user is coord or chair of current committee
	
}
void CommitteeInformation::promoteSecretary(){
}
