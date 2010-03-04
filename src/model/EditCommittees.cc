#include "EditCommittees.h"
#include <QtGui>
#include <QtSql>
#include <QItemSelectionModel>
#include <QModelIndex>

QSqlRelationalTableModel *Cmodel;

EditCommittees::EditCommittees(QWidget *parent){
	setupUi(this);

/*

CREATE TABLE committees (id INTEGER PRIMARY KEY, name TEXT, chair_id INTEGER, secretary_id INTEGER);

*/

	Cmodel = new QSqlRelationalTableModel(this);
	Cmodel->setTable("committees");
	
	//temporarily exclude until AddNewCommittee maps userid properly
	Cmodel->setRelation(2, QSqlRelation("users","id","user_name"));
	Cmodel->setRelation(3, QSqlRelation("users","id","user_name"));
	
	Cmodel->setHeaderData(2, Qt::Horizontal, tr("Chair username"));
	Cmodel->setHeaderData(3, Qt::Horizontal, tr("Secretary username"));
	
	Cmodel->select();
	
	view->setModel(Cmodel);
	view->setColumnHidden(0, true);
	
	QHeaderView * header=view->horizontalHeader();
	header->setStretchLastSection(true);

	connect(DeleteButton,SIGNAL(clicked()), this, SLOT(deleteCommittee()));
	connect(SaveButton,SIGNAL(clicked()), Cmodel, SLOT(submitAll()));
	connect(SaveButton,SIGNAL(clicked()), this, SLOT(close()));
	connect(CancelButton,SIGNAL(clicked()), this, SLOT(close()));

}

void EditCommittees::saveCommittee(){
	// replaced by a submitAll() call on the model...
}

void EditCommittees::deleteCommittee(){
	// ask for confirmation first
	int ret = QMessageBox::question(this, qApp->tr("Confirm delete committee"),
			qApp->tr("Are you sure you want to delete this committee?.\n"),
			QMessageBox::Ok | QMessageBox::Cancel);
	
	if(ret == QMessageBox::Ok){
	QItemSelectionModel *selected = view->selectionModel();
	QModelIndex index = selected->currentIndex();
	Cmodel->removeRows(index.row(), 1, QModelIndex());
	}
	//this->close();
}
