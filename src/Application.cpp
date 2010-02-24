#include "lib/Database.h"

#include <QApplication>
#include <iostream>

#ifndef DB_PATH
#define DB_PATH "db/cooperDB.sqlite3"
#endif

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	Database db(DB_PATH);
	db.close();

	return app.exec();
}
