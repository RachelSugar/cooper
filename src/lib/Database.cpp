#include "Database.h"

/**
 * constructor
 *
 * Connects to the SqLite database `dbFile` or creates a new database with
 * the file name `dbFile` if no such database exists
 */
Database::Database(QString dbFile)
{
	// Connect to database
	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName(dbFile);
	// Notify if we can't connect
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

/**
 * loadSchema
 *
 * Loads the application schema from the schema resource into the database.
 */
void Database::loadSchema()
{
	QFile schema(":schema");
	// Execute the SQL stored in the schema resource
	if (schema.open(QIODevice::ReadOnly | QFile::Truncate)) {
		QTextStream stream(&schema);
		QSqlQuery query;
		query.exec(stream.readAll());
	}
	schema.close();
}

/**
 * close
 *
 * Closes the connection to the database.
 */
void Database::close()
{
	db.close();
}

Database::~Database()
{}
