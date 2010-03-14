#include "CoordPassword.h"
#include "Login.h"
#include <QString>
#include <QtGui>
#include <QSqlQuery>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>
#include <iostream>
//#include <qapplication>

// Sets up the GUI
CoordPassword::CoordPassword(QWidget *parent) {
	setupUi(this); // this sets up GUI

	// signals/slots mechanism in action
	connect( coordPassButtons, SIGNAL( rejected() ), this, SLOT( close() ) );
	connect( coordPassButtons, SIGNAL( accepted() ), this, SLOT( checkPassword() ) );
}

// Gets the Co-ordinators password and inserts the info into the db
void CoordPassword::checkPassword(){
	QString password = coordPasswordBox->text();
	if(password.length() > 0){
		QSqlQuery query2; 
		QString text = "INSERT INTO users VALUES(NULL,1,'coord','" + password + "','NULL','NULL',20,1,1,43,'NULL',0,0,'0')";
		query2.exec((text));
		
		QSqlQuery query;
		query.exec("INSERT INTO committees VALUES(NULL, 'Board', NULL,NULL)");
		query.exec("INSERT INTO committees VALUES(NULL, 'Inspections',NULL,NULL)");
		query.exec("INSERT INTO committees VALUES(NULL, 'Membership', NULL,NULL)");
		query.exec("INSERT INTO committees VALUES(NULL, 'Education', NULL,NULL)");
		query.exec("INSERT INTO committees VALUES(NULL, 'Member Relations', NULL,NULL)");
		
		this->close();
		bulkLoadFile();
		Login *login = new Login();
		login->show();
	}
	else {
		QMessageBox::warning(0, qApp->tr("Error"),
			qApp->tr("Please enter a password.\n"),
			QMessageBox::Ok);
	}
}

// gets the bulk load file name
void CoordPassword::bulkLoadFile() {
	int loaded = FALSE;
	while(loaded == FALSE){
		QString fileLoc = QFileDialog::getOpenFileName(this, tr("Select Bulk Load File"), QDir::currentPath());
		if(fileLoc != ""){
			qDebug()<<"File name is: " << fileLoc << endl;
			if(fileLoc.endsWith ( ".txt")) {
				loaded = TRUE;
				loadInData(fileLoc);
			}
			else {
				qDebug() << "Incorrect File Type"<< endl;
			}
		}
		else{
			qDebug()<<"No File Choosen" << endl;
		}
	}
}

// loads the file data into the db
void CoordPassword::loadInData(QString fileLoc) {
	QString line;
  	QFile bulkfile(fileLoc);
  	if (bulkfile.open( QIODevice::ReadOnly )) {
	QTextStream ts( &bulkfile );
    	while (! ts.atEnd() ) {
			ts >> line;
      		qDebug() << line << endl;
    	}
    	bulkfile.close();
  	}
  	else {
	  qDebug()<< "Unable to open file"<< endl; 
  	}
}

