#include "ViewPhone.h"
#include <QtGui>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QString>
#include <QSqlQuery>

ViewPhone::ViewPhone(QWidget *parent){
	setupUi(this);

	connect( pbPrint, SIGNAL( clicked()), this, SLOT ( printList()));
	connect( pbClose, SIGNAL( clicked()), this, SLOT ( close()));

	if(parent==0){}

/*
CREATE TABLE users (

0 id INTEGER PRIMARY KEY, 
1 is_coordinator INTEGER, 
2 user_name TEXT, 
3 password TEXT, 
4 last_name TEXT, 
5 first_name TEXT, 
6 age INTEGER, 
7 committee_id INTEGER, 
8 is_resident INTEGER, 
9 unit_id INTEGER, 
10 phone_number TEXT, 
11 phone_number_is_public INTEGER, 
12 in_arrears INTEGER, 
13 under_twenty TEXT);

*/

	bool isRegularUser = true;
	
	QSqlRelationalTableModel* model = new QSqlRelationalTableModel(this);
	model->setTable("users");

	//model->setRelation(9, QSqlRelation("units", "id", "number"));

	model->setHeaderData(4,Qt::Horizontal,tr("Surname"));
	model->setHeaderData(5,Qt::Horizontal,tr("First Name"));
	model->setHeaderData(9,Qt::Horizontal,tr("Unit"));
	model->setHeaderData(10,Qt::Horizontal,tr("Phone Number"));
	model->setHeaderData(13,Qt::Horizontal,tr("Cohabitants Under 21"));
	model->setSort(4, Qt::AscendingOrder);
	model->select();

	if(isRegularUser){
		label->setText("Public Member Phone List");
		for(int i=0;i<model->rowCount();i++){
			if(model->data(model->index(i,11)).toInt() == 0){
				model->setData(model->index(i,10), " ");
			}
		}
	}

	for(int i=0;i<model->rowCount();i++){

		int uid = model->data(model->index(i,9)).toInt();

		QString names="";

		QSqlQuery query;
		query.prepare("SELECT age,last_name,first_name,user_name FROM users WHERE unit_id = :uid");
		query.bindValue(":uid",uid);
		query.exec();
		
		while(query.next()){

			qDebug() << query.value(0).toString();
			qDebug() << query.value(1).toString();
			qDebug() << query.value(2).toString() << endl;

			if(query.value(0).toInt()<21 && query.value(3).toString()!=model->data(model->index(i,2)).toString() ){
				names=names+query.value(2).toString()+" "+query.value(1).toString()+"; ";
			}
		}

		qDebug() << names << endl;

		model->setData(model->index(i,13), names);

		if(model->data(model->index(i,8)).toInt() == 0){
			model->removeRows(i,1);
		}

	}

	
	model->setRelation(9, QSqlRelation("units", "id", "number"));
	//model->submitAll();

	view->setModel(model);
	view->resizeColumnsToContents();
	view->setColumnHidden(0,true);
	view->setColumnHidden(1,true);
	view->setColumnHidden(2,true);
	view->setColumnHidden(6,true);
	view->setColumnHidden(7,true);
	view->setColumnHidden(3,true);
	view->setColumnHidden(8,true);
	view->setColumnHidden(11,true);
	view->setColumnHidden(12,true);


	QHeaderView *header = view->horizontalHeader();
	header->setStretchLastSection(true);

}

void ViewPhone::printList() {

	update();
	repaint();

	qDebug() << "Printed";

}
