#ifndef COMMITTEE_H
#define COMMITTEE_H

#include <QObject>
#include <QString>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <QList>

// Forward declaration
class User;

class Committee
{
public:
        Committee();
        virtual ~Committee();
        int id();
        QString name();
        void setName(QString name);
        User chair();
        void setChair(User chair);
        User secretary();
        void setSecretary(User secretary);
	static Committee find(int id);
	static QList<Committee> findWhere(QString conditions);
	static QList<Committee> all();
private:
        Committee(QSqlQuery query);
        int _id;
        QString _name;
        int _chairId;
        int _secretaryId;
};

#endif // COMMITTEE_H
