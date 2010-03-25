#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QMessageBox>

class Database
{
public:
	Database(QString dbFile);
	virtual ~Database();

	void loadSchema();
	void close();

private:
	QSqlDatabase db;
};
