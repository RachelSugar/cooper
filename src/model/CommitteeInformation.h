#ifndef COMMITTEEINFORMATION_H
#define COMMITTEEINFORMATION_H

#include "ui_CommitteeInformation.h"

class CommitteeInformation : public QWidget, private Ui::CommitteeInformationObject
{
	Q_OBJECT
public:
	CommitteeInformation(QString committee, QString user);

public slots:

	void addTask();
	void deleteTask();
	void markTaskCompleted();
	void printCommittee();
	void printTask();
	void promoteChair();
	void promoteSecretary();
	void refreshTask();
};

#endif
