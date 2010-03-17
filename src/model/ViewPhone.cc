#include "ViewPhone.h"
#include <QtGui>
#include <QSqlTableModel>
#include <QSqlRelation>
#include <QSqlRelationalTableModel>
#include <QString>
#include <QSqlQuery>
#include <QTextDocument>

QSqlTableModel* model;

ViewPhone::ViewPhone(QWidget *parent, bool conf){
	setupUi(this);

	//Connect my slots with the ui
	connect( pbPrint, SIGNAL( clicked()), this, SLOT ( printList()));
	connect( pbClose, SIGNAL( clicked()), this, SLOT ( close()));

/*
CREATE TABLE users (
0	id INTEGER PRIMARY KEY, 
1	is_coordinator INTEGER, 
2	user_name TEXT, 
3	password TEXT, 
4	last_name TEXT, 
5	first_name TEXT, 
6	is_21 INTEGER, 
7	committee_id INTEGER, 
8	is_resident INTEGER, 
9	unit_id INTEGER, 
0	phone_number TEXT, 
1	phone_number_is_public INTEGER, 
2	in_arrears INTEGER, 
3	old_address TEXT, 
4	move_in_date TEXT);
*/

	if(parent==0){}

	//Setup my table model to interact with database table
	model = new QSqlTableModel(this);
	model->setTable("users");
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);
	model->select();

	//Rename headers
	model->setHeaderData(4,Qt::Horizontal,tr("Surname"));
	model->setHeaderData(5,Qt::Horizontal,tr("First Name"));
	model->setHeaderData(9,Qt::Horizontal,tr("Unit"));
	model->setHeaderData(10,Qt::Horizontal,tr("Phone Number"));
	model->setHeaderData(13,Qt::Horizontal,tr("Cohabitants Under 21"));
	
	//Are we printing a confidential list? If so remove confidential numbers
	if(!conf){
		label->setText("Public Member Phone List");
		for(int i=0;i<model->rowCount();i++){
			if(model->data(model->index(i,11)).toInt() == 0){
				model->setData(model->index(i,10), " ");
			}
		}
	}

	//Loop through each user
	for(int i=0;i<model->rowCount();i++){

		//Check if they are cohabitants with minors
		int uid = model->data(model->index(i,9)).toInt();

		QString names="";

		QSqlQuery query;
		query.prepare("SELECT is_21,last_name,first_name,user_name FROM users WHERE unit_id = :uid");
		query.bindValue(":uid",uid);
		query.exec();
		
		while(query.next()){
			//If they are living with minors, make a list of all of them.
			if(query.value(0).toInt()==0 && query.value(3).toString()!=model->data(model->index(i,2)).toString() ){
				names=names+query.value(2).toString()+" "+query.value(1).toString()+"; ";
			}
		}
		model->setData(model->index(i,13), names);

		//Remove the user if they arent living in the coop, this takes care of coord
		if(model->data(model->index(i,8)).toInt() == 0){
			model->removeRows(i,1);
		}

	}
/*
	//Relate the foreign keys in the table to the units database table
	model->setRelation(9, QSqlRelation("units", "id", "unit_number"));
	model->select();
	model->submitAll();
*/
	//Format the tableview to look good.
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
	view->setColumnHidden(14,true);

	QHeaderView *header = view->horizontalHeader();
	header->setStretchLastSection(true);

	model->setSort(4, Qt::AscendingOrder);
	model->select();

}

//Print function, currently paints the viewport of the table....

void ViewPhone::printList() {
/*
	//Setup my output string (later to be printed).

	QString toPrint =label->text()+"\n-------------------------------------------------------------------------------------------------------------------------\n\n",unitSt="",t;

	//Fill the string with a list of phone numbers.
	for(int i=0;i<model->rowCount();i++){

		int uid = model->data(model->index(i,9)).toInt();
		QSqlQuery query;
		query.prepare("SELECT number FROM units WHERE id = :uid");
		query.bindValue(":uid",uid);
		query.exec();
		
		if(query.next()){
			unitSt = query.value(0).toString();
		}

		toPrint=toPrint+"+ "+model->data(model->index(i,4)).toString()+", "+model->data(model->index(i,5)).toString()+"; Unit: "+unitSt+"; Phone Number: "+model->data(model->index(i,10)).toString()+"\n\n";

	}
	
	//Convert to a document and print.
	QTextDocument *doc = new QTextDocument();
	doc->setPlainText(toPrint);

	QPrinter printer(QPrinter::ScreenResolution);
	printer.setPaperSize(QPrinter::Letter);
	printer.setDocName("cooper/printPhone.pdf");
	printer.setColorMode(QPrinter::GrayScale);
	printer.setOutputFormat(QPrinter::PdfFormat);

	QPrintDialog dlg(&printer, this);

	if (dlg.exec() == QDialog::Accepted){
		doc->print(&printer);
	}
	qDebug() << "Printed";
*/
}
