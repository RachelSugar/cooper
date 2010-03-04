#include "ViewPhone.h"
#include <QtGui>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QString>
#include <QSqlQuery>

QSqlRelationalTableModel* model;

ViewPhone::ViewPhone(QWidget *parent, bool conf){
	setupUi(this);

	//Connect my slots with the ui
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
	
	//Setup my table model to interact with database table
	model = new QSqlRelationalTableModel(this);
	model->setTable("users");

	//Rename headers
	model->setHeaderData(4,Qt::Horizontal,tr("Surname"));
	model->setHeaderData(5,Qt::Horizontal,tr("First Name"));
	model->setHeaderData(9,Qt::Horizontal,tr("Unit"));
	model->setHeaderData(10,Qt::Horizontal,tr("Phone Number"));
	model->setHeaderData(13,Qt::Horizontal,tr("Cohabitants Under 21"));
	model->setSort(4, Qt::AscendingOrder);
	model->select();

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
		query.prepare("SELECT age,last_name,first_name,user_name FROM users WHERE unit_id = :uid");
		query.bindValue(":uid",uid);
		query.exec();
		
		while(query.next()){
			//If they are living with minors, make a list of all of them.
			if(query.value(0).toInt()<21 && query.value(3).toString()!=model->data(model->index(i,2)).toString() ){
				names=names+query.value(2).toString()+" "+query.value(1).toString()+"; ";
			}
		}
		model->setData(model->index(i,13), names);

		//Remove the user if they arent living in the coop
		if(model->data(model->index(i,8)).toInt() == 0){
			model->removeRows(i,1);
		}

	}

	//Relate the foreign keys in the table to the units database table
	model->setRelation(9, QSqlRelation("units", "id", "number"));
	//model->submitAll();

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

	QHeaderView *header = view->horizontalHeader();
	header->setStretchLastSection(true);

}

//Print function, currently paints the viewport of the table....

void ViewPhone::printList() {

	QPrinter printer(QPrinter::ScreenResolution);

	printer.setOrientation(QPrinter::Landscape);
	printer.setPaperSize(QPrinter::Letter);
	printer.setDocName("cooper/printPhone.pdf");

	QPrintDialog dlg(&printer, this);

	if (dlg.exec() == QDialog::Accepted){

		// calculate the total width/height table would need without scaling
		const int rows = model->rowCount();
		const int cols = model->columnCount();
	
		double totalWidth = 0.0;
		for (int c = 0; c < cols; ++c){
			totalWidth += view->columnWidth(c);
		}
	
		double totalHeight = 0.0;
		for (int r = 0; r < rows; ++r){
			totalHeight += view->rowHeight(r);
		}

		//totalWidth = totalWidth/cols;
		//totalHeight = totalHeight/rows;

		// width in pixels = paper width in inches * dpi horizontal/scaling horizontal 
		// height in pixels = paper height in inches * dpi vertical/scaling vertical 

		qDebug() << totalWidth;
		qDebug() << totalHeight;
	
		//totalWidth =8.5*
		
		// redirect table's painting on a pixmap
		QPixmap pixmap((int)totalWidth, (int)totalHeight);
		QPainter::setRedirected(view->viewport(), &pixmap);
		QPaintEvent event(QRect(0, 0, (int)totalWidth, (int)totalHeight));
		QApplication::sendEvent(view->viewport(), &event);
		QPainter::restoreRedirected(view->viewport());
		
		// print scaled pixmap
		QPainter painter(&printer);
		painter.drawPixmap(printer.pageRect(), pixmap, pixmap.rect());
	}
	update();
	repaint();
	qDebug() << "Printed";

}
