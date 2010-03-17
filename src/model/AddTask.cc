#include "AddTask.h"
#include <QtGui>
#include <QtSql>
#include <QItemSelectionModel>
#include <QModelIndex>
#include "CommitteeInformation.h"

QString committee;

AddTask::AddTask(QString toAddTo,QWidget *parent){
	setupUi(this);
	
	committee = toAddTo;
	connect(cancelOk,SIGNAL(rejected()), this, SLOT(close()));
	connect(cancelOk,SIGNAL(accepted()), this, SLOT(add()));
	connect(cancelOk,SIGNAL(accepted()), parent, SLOT(refreshTask()));
	connect(dueDateCheck,SIGNAL(clicked()), this, SLOT(dateClicked()));
	
	

}

//
void AddTask::dateClicked(){
	bool isCheck = dueDateCheck->isChecked();
	
	if(isCheck == true){
		dateBox->setEnabled(true);
	}
	else{
		dateBox->setEnabled(false);
	}
}

void AddTask::add(){

	QString title = titleLine->text();
	QTextDocument *descriptionDoc = description->document();
	QString descStr = descriptionDoc->toPlainText();
	if(title.length() == 0 || descStr.length() == 0){
	QMessageBox::critical(0, qApp->tr("Error:"),
			qApp->tr("Please both fields.\n"),
			QMessageBox::Cancel);
	}
	else{
		QString getCommitteeNum = "SELECT id FROM committees WHERE name = '" + committee +"'";
		QString CommitteeNum;
		QSqlQuery query(getCommitteeNum);
	
		while ( query.next() ) {
			CommitteeNum = query.value(0).toString();
		}
	
		QString date;
		if(dueDateCheck->isEnabled() == true){
			date = dateBox->date().toString();
		}
		else{
			date = "no";
		}

	
		char isAnnual = isTrue(annualCheck->isChecked());
		QString addQuery = "INSERT INTO tasks VALUES(NULL,'"+ title +"','" + descStr + "','" + CommitteeNum + "',0,'"+date+"'," + isAnnual +")";
		qDebug() << query.exec(addQuery) << endl;
		this->close();
	

	}
}
char AddTask::isTrue(bool toTest)
{
	if(toTest == true)
		return '1';
	else
		return '0';

}
