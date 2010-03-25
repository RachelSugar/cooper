#include "lib/Database.h"
#include "models/Login.h"
#include "models/InitialLoad.h"

#include <QApplication>

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
		InitialLoad *initLoad = new InitialLoad();
		initLoad->show();
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
