#include "ViewPhone.h"
#include <QtGui>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>

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
	
	QSqlRelationalTableModel* model = new QSqlRelationalTableModel(this);
	model->setTable("users");


// GET USER NAME FROM       ########################################        PARENT WIDGET :: HOW? I DUNNOs
//	string username = "coord";	

//	if(username=="coord"){}

	model->setHeaderData(4,Qt::Horizontal,tr("Surname"));
	model->setHeaderData(5,Qt::Horizontal,tr("First Name"));
	model->setHeaderData(9,Qt::Horizontal,tr("Unit"));
	model->setHeaderData(10,Qt::Horizontal,tr("Phone Number"));
	model->setHeaderData(13,Qt::Horizontal,tr("Cohabitants Under 21"));
	model->setSort(5, Qt::DescendingOrder);
	model->select();

	view->setModel(model);
	view->resizeColumnsToContents();
	//view->columnMoved(5,5,4);
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

	qDebug() << "Columns: "<<model->columnCount();
	qDebug() << "DB Driver Name: "<<model->database().driverName();
	qDebug() << "DB Validity: "<<model->database().isValid()<<endl;


}

void ViewPhone::printList() {

	update();
	repaint();

	qDebug() << "Printed";

}
