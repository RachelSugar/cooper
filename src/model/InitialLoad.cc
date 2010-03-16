#include "InitialLoad.h"
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
InitialLoad::InitialLoad(QWidget *parent) {
	setupUi(this); // this sets up GUI

	// signals/slots mechanism in action
	connect( coordPassButtons, SIGNAL( rejected() ), this, SLOT( close() ) );
	connect( coordPassButtons, SIGNAL( accepted() ), this, SLOT( checkPassword() ) );
}

// Gets the Co-ordinators password and inserts the info into the db
void InitialLoad::checkPassword(){
	QString password = coordPasswordBox->text();
	if(password.length() > 0){

		this->close();
		if(bulkLoadFile()){
		
			QSqlQuery query;
			query.exec("INSERT INTO committees VALUES(NULL, 'Board', NULL,NULL)");
			query.exec("INSERT INTO committees VALUES(NULL, 'Inspections',NULL,NULL)");
			query.exec("INSERT INTO committees VALUES(NULL, 'Membership', NULL,NULL)");
			query.exec("INSERT INTO committees VALUES(NULL, 'Education', NULL,NULL)");
			query.exec("INSERT INTO committees VALUES(NULL, 'Member Relations', NULL,NULL)");
		
			QSqlQuery query2; 
			QString text = "INSERT INTO users VALUES(NULL,1,'coord','" + password + "','NULL','NULL',20,1,1,43,'NULL',0,0,'0','NULL')";
			query2.exec((text));
		
			Login *login = new Login();
			login->show();
		}
	}
	else {
		showError("Please enter a password. \n");
	}
}

// gets the bulk load file name
bool InitialLoad::bulkLoadFile() {
	int loaded = FALSE;
	while(loaded == FALSE){
		QString fileLoc = QFileDialog::getOpenFileName(this, tr("Select Bulk Load File"), QDir::currentPath());
		if(fileLoc != ""){
			if(fileLoc.endsWith ( ".txt")) {
				loaded = TRUE;
				loadInData(fileLoc);
			}
			else {
				showError("Please select a .txt file \n");
			}
		}
		else{
			showError("You must select a bulk load file to load \n the coord password entered will not be saved.");
			return false;
		}
	}
	return true;
}

// loads the file data into the db
void InitialLoad::loadInData(QString fileLoc) {
	QString line;
  	QFile bulkfile(fileLoc);
  	if (bulkfile.open( QIODevice::ReadOnly )) {
	// QTextStream ts( &bulkfile );
	//     	while (! ts.atEnd() ) {
	// 		line = ts.readLine();
	//       		qDebug() << line;
	// 		QStringList list = line.split(",");
	// 		for(int i = 0; i < list.length(); i++){
	// 			list[i] = list[i].trimmed();
	// 			qDebug() << list[i];
	// 		}
	// 		QSqlQuery q; 
	// 		QString text = "INSERT INTO units VALUES(NULL,'" + list[0] + "','" + list[1] + "','" + list[2] + "','" + list[3] + "')";
	// 		qDebug() << text;
	// 		q.exec((text));
			
    //	}
    	bulkfile.close();
  	}
  	else {
		showError("Unable to open file \n");
  	}
}

void InitialLoad::showError(char *message){
	QMessageBox::warning(0, qApp->tr("Error"),
		qApp->tr(message),
		QMessageBox::Ok);
}

