#ifndef COMMITTEEINFORMATION_H
#define COMMITTEEINFORMATION_H

#include "ui_CommitteeInformation.h"

class CommitteeInformation : public QWidget, private Ui::CommitteeInformationObject
{
	Q_OBJECT
public:
	CommitteeInformation(QWidget *parent = 0);

public slots:

	void addTask();
	void deleteTask();
	void markTaskCompleted();
	void printCommitee();
	void printTask();
	void promoteChair();
	void promoteSecretary();
};

#endif
