#ifndef PROTOTYPEMAINSCREEN_H
#define PROTOTYPEMAINSCREEN_H

#include "ui_PrototypeMainScreen.h"


class PrototypeMainScreen : public QWidget, private Ui::PrototypeMainScreen
{
	Q_OBJECT

public:
	PrototypeMainScreen(QString username);

public slots:
	void addCommittee();
	void addMember();
	void printPrivate();
	void printPublic();
	void editCommit();
	void viewMembers();
};

#endif
