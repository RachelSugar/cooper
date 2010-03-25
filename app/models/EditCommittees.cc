/*
*	Displays committees and allows user to edit and delete
*	Problem with displaying table; will not display a committee unless its
*	foreign keys("id", "user_name") are mapped and defined.
*/
#include "EditCommittees.h"
#include "AddTask.h"
#include "CommitteeInformation.h"
#include <QtGui>
#include <QtSql>
#include <QItemSelectionModel>
#include <QModelIndex>

QSqlTableModel *Cmodel;
QString userCurrent;

EditCommittees::EditCommittees(QWidget *parent, QString user){
	userCurrent = user;
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
	connect(MoreButton,SIGNAL(clicked()), this, SLOT(moreInformation()));
	connect(CancelButton,SIGNAL(clicked()), this, SLOT(close()));
	if(userCurrent != "coord"){
		DeleteButton->setEnabled(false);
	}

}

void EditCommittees::moreInformation(){
	// open up a new window with more information and the ability to edit
	QItemSelectionModel *selected = view->selectionModel();
	QModelIndex index = selected->currentIndex();	
	QSqlRecord record = Cmodel->record(index.row());
	QString name = record.value(1).toString();
	CommitteeInformation *c = new CommitteeInformation(name, userCurrent);
	c->show();
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
			|| name == "Education" || name == "Member Relations" || name == "None"){
			QMessageBox::critical(this, qApp->tr("Invalid delete"),
			qApp->tr("You cannot delete this committee.\n"),
			QMessageBox::Ok);
		} else {
		Cmodel->removeRows(index.row(), 1, QModelIndex());

		// update all users
		QString noneQueryText = "SELECT id FROM committees WHERE name = 'None' COLLATE NOCASE";
		QSqlQuery noneQuery(noneQueryText);
		QString noneID = 0;
		if(noneQuery.next()){
			qDebug() << (noneID = noneQuery.value(0).toString());
		}

		QString thisID = record.value(0).toString();

		QSqlQuery userQuery;
		userQuery.prepare("UPDATE users SET committee_id = :noneID WHERE committee_id = :thisID");
		userQuery.bindValue(":noneID", noneID);
		userQuery.bindValue(":thisID", thisID);
		qDebug() << userQuery.exec();
		}
	}
	//this->close();
}

