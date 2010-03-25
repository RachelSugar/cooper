#include "Task.h"

#ifndef FRESH_ID
#define FRESH_ID 0
#endif

#include "Committee.h"

Task::Task()
{
        _id          = FRESH_ID;
        _title       = "";
        _description = "";
        _committeeId = 0;
        _isComplete  = false;
        _dueDate     = QDate::currentDate();
        _isAnnual    = false;
}

Task::Task(QSqlQuery query)
{
        _id          = query.value(0).toInt();
        _title       = query.value(1).toString();
        _description = query.value(2).toString();
        _committeeId = query.value(3).toInt();
        _isComplete  = query.value(4).toBool();
        _dueDate     = query.value(5).toDate();
        _isAnnual    = query.value(6).toBool();
}

int Task::id()
{
        return _id;
}

QString Task::title()
{
        return _title;
}

void Task::setTitle(QString title)
{
        _title = title;
}

QString Task::description()
{
        return _description;
}

void Task::setDescription(QString description)
{
        _description = description;
}

Committee Task::committee()
{
        return Committee::find(_committeeId);
}

void Task::setCommittee(Committee committee)
{
        _committeeId = committee.id();
}

bool Task::isComplete()
{
        return _isComplete;
}

void Task::setIsComplete(bool isComplete)
{
        _isComplete = isComplete;
}

QDate Task::dueDate()
{
        return _dueDate;
}

void Task::setDueDate(QDate dueDate)
{
        _dueDate = dueDate;
}

bool Task::isAnnual()
{
        return _isAnnual;
}

void Task::setIsAnnual(bool isAnnual)
{
        _isAnnual = isAnnual;
}

bool Task::save()
{
	QSqlQuery query;
        // Use INSERT/UPDATE depending on if the task is new or not
	if ( _id != FRESH_ID ) {
	        query.prepare("UPDATE tasks SET title=:title, description=:description, committee_id=:committee_id, is_complete=:is_complete, due_date=:due_date, is_annual=:is_annual WHERE id=:id");
                query.bindValue(":id", _id);
	} else {
                query.prepare("INSERT INTO tasks VALUES (:id, :title, :description, :committee_id, :is_complete, :due_date, :is_annual)");
	}
        query.bindValue(":title", _title);
        query.bindValue(":description", _description);
        query.bindValue(":committeeId", _committeeId);
        query.bindValue(":isComplete", _isComplete);
        query.bindValue(":dueDate", _dueDate);
        query.bindValue(":isAnnual", _isAnnual);
        return query.exec();
}

Task Task::find(int id)
{
        QSqlQuery query;
        query.exec("SELECT id, title, description, committee_id, is_complete, due_date, is_annual FROM tasks WHERE id=" + QVariant(id).toString());
        query.next();
        Task t(query);
        return t;
}

QList<Task> Task::findWhere(QString conditions)
{
	QSqlQuery query;
        query.exec("SELECT id, title, description, committee_id, is_complete, due_date, is_annual FROM tasks WHERE " + conditions);
	Task *t;
	QList<Task> results;
	while(query.next()) {
		t = new Task(query);
		results << *t;
	}
	return results;
}

QList<Task> Task::all()
{
	QSqlQuery query;
        query.exec("SELECT id, title, description, committee_id, is_complete, due_date, is_annual FROM tasks");
	Task *t;
	QList<Task> results;
	while(query.next()) {
		t = new Task(query);
		results << *t;
	}
	return results;
}

Task::~Task()
{}

