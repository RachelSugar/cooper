#include "Login.h"
#include <QtGui>
//#include <qapplication>

Login::Login(QWidget *parent) {
	setupUi(this); // this sets up GUI

	// signals/slots mechanism in action
	connect( loginButtons, SIGNAL( rejected() ), this, SLOT( close() ) );
	connect( loginButtons, SIGNAL( accepted() ), this, SLOT( checkUserInfo() ) );
}


// checks the entered information from the dialog with the db
void Login::checkUserInfo(){
	
}

// shows an error dialog if incorrect info is entered
// returns to login dialog
void Login::displayError(){
	
}




