#include "Login.h"
#include "PrototypeMainScreen.h"
#include <QtGui>
#include <QSqlQuery>
//#include <qapplication>

Login::Login(QWidget *parent) {
	setupUi(this); // this sets up GUI

	// signals/slots mechanism in action
	connect( loginButtons, SIGNAL( rejected() ), this, SLOT( close() ) );
	connect( loginButtons, SIGNAL( accepted() ), this, SLOT( checkUserInfo() ) );
	connect( loginButtons, SIGNAL( accepted() ), this, SLOT( close() ) );
	
}


// checks the entered information from the dialog with the db
void Login::checkUserInfo(){
	QString username = usernameBox->text();
	QString password = passwordBox->text();
	qDebug() << "username: " << username;
	qDebug() << "password: " << password;
	if(username == "coord" && password == "pass"){
		PrototypeMainScreen *screen = new PrototypeMainScreen();
		screen->show();
	}
	else {
		QString text = "SELECT password FROM users WHERE user_name = '" + username + "'";
		qDebug() << text;
		QSqlQuery query(text);
		if(query.next()){
			qDebug() << "query has results!!!";
			QString rightPass = query.value(0).toString();
			if(rightPass == password){
				qDebug() << "query worked! inside password check";
				PrototypeMainScreen *screen = new PrototypeMainScreen();
				screen->show();
			}
		}
		else {
			qDebug() <<"User name and password not found in query";
		}
	}

}

// shows an error dialog if incorrect info is entered
// returns to login dialog
void Login::displayError(){
	
}




