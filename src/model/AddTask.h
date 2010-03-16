#ifndef ADDTASK_H
#define ADDTASK_H
 
#include "ui_AddTask.h"
 
 
class AddTask : public QWidget, private Ui::AddTask
{
	Q_OBJECT
 
public:
	AddTask(QString toAddTo);
 
public slots:

	void dateClicked();
	void add();
	static char isTrue(bool toTest);
	
};
 
#endif

