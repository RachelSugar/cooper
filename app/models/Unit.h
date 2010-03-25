#ifndef UNIT_H
#define UNIT_H

#include <QObject>
#include <QString>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <QVector>

class Unit
{
public:
	Unit();
	int id();
	QString number();
	void setNumber(QString number);
        QString streetAddress();
        void setStreetAddress(QString streetAddress);
        int numBedrooms();
        void setNumBedrooms(int numBedrooms);
	bool save();
	static Unit find(int id);
	static QList<Unit> findWhere(QString conditions);
	static QList<Unit> all();
private:
	Unit(QSqlQuery query);
	int _id;
	QString _number;
        QString _streetAddress;
        int _numBedrooms;
};

#endif // UNIT_H
