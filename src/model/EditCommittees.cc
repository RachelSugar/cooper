#include "EditCommittees.h"
#include <QtGui>
#include <QtSql>

EditCommittees::EditCommittees(QWidget *parent){
	setupUi(this);

/*

CREATE TABLE committees (id INTEGER PRIMARY KEY, name TEXT, chair_id INTEGER, secretary_id INTEGER);

*/
	connect(DeleteButton,SIGNAL(clicked()), this, SLOT(deleteCommittee()));
	connect(SaveButton,SIGNAL(clicked()), this, SLOT(saveCommittee()));
	connect(CancelButton,SIGNAL(clicked()), this, SLOT(close()));

	QSqlRelationalTableModel *model = new QSqlRelationalTableModel(this);
	model->setTable("committees");
	
	/* temporarily exclude until AddNewCommittee maps userid properly
	model->setRelation(2, QSqlRelation("users","id","user_name"));
	model->setRelation(3, QSqlRelation("users","id","user_name"));
	*/

	model->select();
	
	view->setModel(model);
	view->setColumnHidden(0, true);
	
	QHeaderView * header=view->horizontalHeader();
	header->setStretchLastSection(true);

}

void EditCommittees::saveCommittee(){

}

void EditCommittees::deleteCommittee(){

}
