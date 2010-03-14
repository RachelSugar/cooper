#include "lib/Database.h"
#include "model/Login.h"
#include "model/CoordPassword.h"

#include <QApplication>
#include <iostream>

#ifndef DB_PATH
#define DB_PATH "db/cooperDB.sqlite3"
#endif

void runGUI(){

	QString text = "SELECT user_name FROM users WHERE user_name = 'coord'";
	QSqlQuery query(text);
	if(query.next()){
		Login *login = new Login();
		login->show();
	}
	else {
		CoordPassword *coordPass = new CoordPassword();
		coordPass->show();
	}
}

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	Database db(DB_PATH);
	//db.close();
	
	runGUI();
	
	return app.exec();
}
