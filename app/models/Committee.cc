#include "Committee.h"

#ifndef FRESH_ID
#define FRESH_ID 0
#endif

#include "User.h"

Committee::Committee()
{
        _id          = FRESH_ID;
        _name        = "";
        _chairId     = 0;
        _secretaryId = 0;
}

Committee::Committee(QSqlQuery query)
{
        _id          = query.value(0).toInt();
        _name        = query.value(1).toString();
        _chairId     = query.value(2).toInt();
        _secretaryId = query.value(3).toInt();
}

int Committee::id()
{
        return _id;
}

QString Committee::name()
{
        return _name;
}

void Committee::setName(QString name)
{
        _name = name;
}

User Committee::chair()
{
        return User::find(_chairId);
}

void Committee::setChair(User chair)
{
        _chairId = chair.id();
}

User Committee::secretary()
{
        return User::find(_secretaryId);
}

void Committee::setSecretary(User secretary)
{
        _secretaryId = secretary.id();
}

Committee Committee::find(int id)
{
        QSqlQuery query;
        query.exec("SELECT id, name, chair_id, secretary_id FROM committees WHERE id=" + QVariant(id).toString());
        query.next();
        Committee c(query);
        return c;
}

QList<Committee> Committee::findWhere(QString conditions)
{
	QSqlQuery query;
        query.exec("SELECT id, name, chair_id, secretary_id FROM committees WHERE " + conditions);
	Committee *c;
	QList<Committee> results;
	while(query.next()) {
		c = new Committee(query);
		results << *c;
	}
	return results;
}

QList<Committee> Committee::all()
{
	QSqlQuery query;
	query.exec("SELECT id, name, chair_id, secretary_id FROM committees");
	Committee *c;
	QList<Committee> results;
	while(query.next()) {
		c = new Committee(query);
		results << *c;
	}
	return results;
}

Committee::~Committee()
{}
