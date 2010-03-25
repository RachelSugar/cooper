#include "Unit.h"

#ifndef FRESH_ID
#define FRESH_ID 0
#endif

Unit::Unit()
{
	_id            = FRESH_ID;
	_number        = "";
        _streetAddress = "";
        _numBedrooms   = 0;
}

Unit::Unit(QSqlQuery query)
{
	_id            = query.value(0).toInt();
	_number        = query.value(1).toString();
        _streetAddress = query.value(2).toString();
        _numBedrooms   = query.value(3).toInt();	
}

int Unit::id()
{
	return _id;
}

QString Unit::number()
{
	return _number;
}

void Unit::setNumber(QString number)
{
	_number = number;
}

QString Unit::streetAddress()
{
        return _streetAddress;
}

void Unit::setStreetAddress(QString streetAddress)
{
        _streetAddress = streetAddress;
}

int Unit::numBedrooms()
{
        return _numBedrooms;
}

void Unit::setNumBedrooms(int numBedrooms)
{
        _numBedrooms = numBedrooms;
}

bool Unit::save()
{
	QSqlQuery query;
	QString queryString;
	if ( _id != FRESH_ID ) {
                query.prepare("UPDATE units SET unit_number=:number, street_address=:street_address, num_bedrooms=:num_bedrooms WHERE id=:id");
                query.bindValue(":id", _id);
	} else {
                query.prepare("INSERT INTO units VALUES (:id, :number, :street_address, :num_bedrooms)");
	}
        query.bindValue(":number", _number);
        query.bindValue(":street_address", _streetAddress);
        query.bindValue(":num_bedrooms", _numBedrooms);
        return query.exec();
}

Unit Unit::find(int id)
{
	QSqlQuery query;
	query.exec("SELECT * FROM units WHERE id="
			+ QVariant(id).toString()
			+ " LIMIT 1");
	query.next();
	Unit u(query);		
	return u;
}

QList<Unit> Unit::findWhere(QString conditions)
{
	QSqlQuery query;
	query.exec("SELECT id, unit_number, street_address, num_bedrooms FROM units WHERE " + conditions);
	Unit *u;
	QList<Unit> results;
	while(query.next()) {
		u = new Unit(query);
		results << *u;
	}
	return results;
}

QList<Unit> Unit::all()
{
	QSqlQuery query;
	query.exec("SELECT id, unit_number, street_address, num_bedrooms FROM units");
	Unit *u;
	QList<Unit> results;
	while(query.next()) {
		u = new Unit(query);
		results << *u;
	}
	return results;
}
