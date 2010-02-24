#include "Database.h"

Database::Database(QString dbFile)
{
	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName(dbFile);
	if (!db.open()) {
		QMessageBox::critical(0, qApp->tr("Cannot open database:"),
			qApp->tr("Unable to open database connection.\n"),
			QMessageBox::Cancel);
	}
	// Load the schema if it is a new database
	if (db.tables().size() < 2) {
		loadSchema();
	}
}

void Database::loadSchema()
{
	QFile schema(":schema");
	if (schema.open(QIODevice::ReadOnly | QFile::Truncate)) {
		QTextStream stream(&schema);
		QSqlQuery query;
		query.exec(stream.readAll());
	}
	schema.close();
}

void Database::close()
{
	db.close();
}

Database::~Database()
{}
