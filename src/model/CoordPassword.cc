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

