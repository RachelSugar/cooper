#include "EditCommittees.h"
#include <QtGui>
#include <QtSql>

EditCommittees::EditCommittees(QWidget *parent){
	setupUi(this);

/*

CREATE TABLE committees (id INTEGER PRIMARY KEY, name TEXT, chair_id INTEGER, secretary_id INTEGER);

*/

	QSqlRelationalTableModel *model = new QSqlRelationalTableModel(this);
	model->setTable("committees");
	
	//temporarily exclude until AddNewCommittee maps userid properly
	model->setRelation(2, QSqlRelation("users","id","user_name"));
	model->setRelation(3, QSqlRelation("users","id","user_name"));
	
	model->setHeaderData(2, Qt::Horizontal, tr("Chair username"));
	model->setHeaderData(3, Qt::Horizontal, tr("Secretary username"));
	
	model->select();
	
	view->setModel(model);
	view->setColumnHidden(0, true);
	
	QHeaderView * header=view->horizontalHeader();
	header->setStretchLastSection(true);

	connect(DeleteButton,SIGNAL(clicked()), this, SLOT(deleteCommittee()));
	connect(SaveButton,SIGNAL(clicked()), model, SLOT(submitAll()));
	connect(SaveButton,SIGNAL(clicked()), this, SLOT(close()));
	connect(CancelButton,SIGNAL(clicked()), this, SLOT(close()));

}

void EditCommittees::saveCommittee(){
	// replaced by a submitAll() call on the model...
}

void EditCommittees::deleteCommittee(){

}
