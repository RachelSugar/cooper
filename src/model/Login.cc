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
	QString text = "SELECT password FROM users WHERE user_name = '" + username + "'";
	QSqlQuery query(text);
	if(query.next()){
		QString rightPass = query.value(0).toString();
		if(rightPass == password ){
			PrototypeMainScreen *screen = new PrototypeMainScreen(username);
			this->close();
			screen->show();
		}
		else {
			displayError();
		}
	}
	else {
		displayError();
	}
}

// shows an error dialog if incorrect info is entered
// returns to login dialog
void Login::displayError(){
	QMessageBox::warning(0, qApp->tr("Error"),
		qApp->tr("Username and Password Incorrect.\n"),
		QMessageBox::Ok);
}




