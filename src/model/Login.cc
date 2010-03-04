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
}


// checks the entered information from the dialog with the db
void Login::checkUserInfo(){
	QString username = usernameBox->text();
	QString password = passwordBox->text();
	qDebug() << "username: " << username;
	qDebug() << "password: " << password;
	
	QSqlQuery q2;
	q2.prepare("SELECT password FROM users WHERE user_name = :username");
	q2.bindValue(":username",username);
	
	if(q2.next()){
		if(q2.value(0).toString() == password){
			qDebug() << "query worked! inside password check";
			PrototypeMainScreen *screen = new PrototypeMainScreen();
			screen->show();
			
		}
	}

}

// shows an error dialog if incorrect info is entered
// returns to login dialog
void Login::displayError(){
	
}




