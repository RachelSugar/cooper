#ifndef TASK_H
#define TASK_H

#include <QObject>
#include <QString>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <QList>
#include <QDate>

// Forward declaration
class Committee;

class Task
{
public:
        Task();
        virtual ~Task();
        int id();
        QString title();
        void setTitle(QString title);
        QString description();
        void setDescription(QString description);
        bool isComplete();
        void setIsComplete(bool isComplete);
        QDate dueDate();
        void setDueDate(QDate dueDate);
        Committee committee();
        void setCommittee(Committee committee);
        bool isAnnual();
        void setIsAnnual(bool isAnnual);
        bool save();
	static Task find(int id);
	static QList<Task> findWhere(QString conditions);
	static QList<Task> all();
private:
        Task(QSqlQuery query);
        int _id;
        QString _title;
        QString _description;
        int _committeeId;
        bool _isComplete;
        QDate _dueDate;
        bool _isAnnual;
};

#endif // TASK_H
