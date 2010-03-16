/*
*	Displays committees and allows user to edit and delete
*	Problem with displaying table; will not display a committee unless its
*	foreign keys("id", "user_name") are mapped and defined.
*/
#include "EditCommittees.h"
#include "AddTask.h"
#include <QtGui>
#include <QtSql>
#include <QItemSelectionModel>
#include <QModelIndex>

QSqlTableModel *Cmodel;

EditCommittees::EditCommittees(QWidget *parent){
	setupUi(this);

/*

CREATE TABLE committees (id INTEGER PRIMARY KEY, name TEXT, chair_id INTEGER, secretary_id INTEGER);

*/

	Cmodel = new QSqlTableModel(this);
	Cmodel->setTable("committees");
	
	Cmodel->setHeaderData(1, Qt::Horizontal, tr("Committee name"));
	Cmodel->select();
	
	view->setModel(Cmodel);
	
	// hide all columns except name
	view->setColumnHidden(0, true);
	view->setColumnHidden(2, true);
	view->setColumnHidden(3, true);
	
	QHeaderView * header=view->horizontalHeader();
	header->setStretchLastSection(true);

	connect(DeleteButton,SIGNAL(clicked()), this, SLOT(deleteCommittee()));
	connect(SaveButton,SIGNAL(clicked()), this, SLOT(saveCommittee()));
	connect(CancelButton,SIGNAL(clicked()), this, SLOT(close()));
	connect(addTask,SIGNAL(clicked()),this,SLOT(addTaskToCommittee()));

}

void EditCommittees::saveCommittee(){
	Cmodel->submitAll();
	this->close();
}

void EditCommittees::deleteCommittee(){
		
	// ask for confirmation first
	int ret = QMessageBox::question(this, qApp->tr("Confirm delete committee"),
			qApp->tr("Are you sure you want to delete this committee?.\n"),
			QMessageBox::Ok | QMessageBox::Cancel);
	
	if(ret == QMessageBox::Ok){
		QItemSelectionModel *selected = view->selectionModel();
		QModelIndex index = selected->currentIndex();

		// test to see that selected is not one of the main committees
		QSqlRecord record = Cmodel->record(index.row());
		QString name = record.value(1).toString();

		if(name == "Board" || name == "Inspections" || name == "Membership"
			|| name == "Education" || name == "Member Relations"){
			QMessageBox::critical(this, qApp->tr("Invalid delete"),
			qApp->tr("You cannot delete this committee.\n"),
			QMessageBox::Ok);
		} else {
		Cmodel->removeRows(index.row(), 1, QModelIndex());
		}
	}
	//this->close();
}

void EditCommittees::addTaskToCommittee(){

	QItemSelectionModel *selected = view->selectionModel();
	QModelIndex index = selected->currentIndex();	
	QSqlRecord record = Cmodel->record(index.row());
	QString name = record.value(1).toString();
	AddTask *aTask = new AddTask(name);
	aTask->show();
	
	qDebug() << name << endl;
	//call gui to add the new class
	
	

}
