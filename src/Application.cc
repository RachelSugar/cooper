#include "lib/Database.h"
#include "model/Login.h"

#include <QApplication>
#include <iostream>
#include "model/PrototypeMainScreen.h"

#ifndef DB_PATH
#define DB_PATH "db/cooperDB.sqlite3"
#endif

void runGUI(){
	
	//PrototypeMainScreen *screen = new PrototypeMainScreen();
	//screen->show();
	Login *login = new Login();
	login->show();
}

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	Database db(DB_PATH);
	//db.close();
	
	runGUI();
	

	return app.exec();
}
