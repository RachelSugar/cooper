#include "CoordPassword.h"
#include "Login.h"
#include <QtGui>
#include <QString>
#include <QSqlQuery>
//#include <qapplication>

CoordPassword::CoordPassword(QWidget *parent) {
	setupUi(this); // this sets up GUI

	// signals/slots mechanism in action
	connect( coordPassButtons, SIGNAL( rejected() ), this, SLOT( close() ) );
	connect( coordPassButtons, SIGNAL( accepted() ), this, SLOT( checkPassword() ) );
}

void CoordPassword::checkPassword(){
	QString password = coordPasswordBox->text();
	qDebug()<<password;
	if(password.length() > 0){
		QSqlQuery query2; 
		QString text = "INSERT INTO users VALUES(NULL,1,'coord','" + password + "','NULL','NULL',20,1,1,43,'NULL',0,0,'0')";
		qDebug()<< "true: " << query2.exec((text));
		
		 "INSERT INTO committees VALUES(NULL, Board, NULL,NULL)"
		CREATE TABLE committees (id INTEGER PRIMARY KEY, name TEXT, chair_id INTEGER, secretary_id INTEGER);
		
		QSqlQuery = query;
		qDebug() << query.exec("INSERT INTO committees VALUES(NULL, Board, NULL,NULL)");
		qDebug() << query.exec("INSERT INTO committees VALUES(NULL, Inspections, NULL,NULL)");
		qDebug() << query.exec("INSERT INTO committees VALUES(NULL, Membership, NULL,NULL)");
		qDebug() << query.exec("INSERT INTO committees VALUES(NULL, Education, NULL,NULL)");
		qDebug() << query.exec("INSERT INTO committees VALUES(NULL, MemberRelations, NULL,NULL)");
		
		this->close();
		Login *login = new Login();
		login->show();
	}
	else {
		QMessageBox::warning(0, qApp->tr("Error"),
			qApp->tr("Please enter a password.\n"),
			QMessageBox::Ok);
	}
}

