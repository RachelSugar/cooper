#include "CommitteeInformation.h"
#include "AddTask.h"
#include <QtGui>
#include <QtSql>
#include <QItemSelectionModel>
#include <QModelIndex>
// flag for QDebug() statements
const int DEBUG = 1;

QSqlTableModel *Tmodel;
QSqlTableModel *CLmodel;
QString committeeName;
QString CommitteeNum;
QString userName;
QString userID;

CommitteeInformation::CommitteeInformation(QString committee, QString currentUser){
	committeeName = committee;
	userName = currentUser;

	qDebug() << "Current user is :" << userName;
	setupUi(this);

	Tmodel = new QSqlTableModel(this);
	Tmodel->setTable("tasks");

	QString getCommitteeNum = "SELECT id FROM committees WHERE name = '" + committeeName +"'";
	QSqlQuery query(getCommitteeNum);
	
	while ( query.next() ) {
		CommitteeNum = query.value(0).toString();
	}

	Tmodel->setFilter("committee_id = " + CommitteeNum);
	
	Tmodel->setHeaderData(1, Qt::Horizontal, tr("Name"));
	Tmodel->setHeaderData(4, Qt::Horizontal, tr("Complete?"));
	Tmodel->setHeaderData(5, Qt::Horizontal, tr("Due date"));
	Tmodel->setHeaderData(6, Qt::Horizontal, tr("Annual?"));
	
	Tmodel->select();
	
	taskView->setModel(Tmodel);
	
	// hide all columns except name
	taskView->setColumnHidden(0, true);
	taskView->setColumnHidden(2, true);
	taskView->setColumnHidden(3, true);
	
	QHeaderView *taskHeader = taskView->horizontalHeader();
	taskHeader->setStretchLastSection(true);

	// set up committee member table

	CLmodel = new QSqlTableModel(this);
	CLmodel->setTable("users");

	CLmodel->setFilter("committee_id = " + CommitteeNum + " and is_resident = 1");
	//CLmodel->setFilter("is_resident = 1");
	
	CLmodel->setHeaderData(1, Qt::Horizontal, tr("User name"));
	CLmodel->setHeaderData(4, Qt::Horizontal, tr("Last name"));
	CLmodel->setHeaderData(5, Qt::Horizontal, tr("First name"));
	
	CLmodel->select();
	
	constituentView->setModel(CLmodel);

	// display chair and secretary names
	QString getChairInt  = "SELECT chair_id FROM committees WHERE id = " + CommitteeNum;
	
	
	QSqlQuery query1(getChairInt);
	
	while ( query1.next() ) {
		getChairInt = query1.value(0).toString();
	}
	if(getChairInt != NULL){

		QString getChairName = "SELECT first_name, last_name FROM users WHERE id = " + getChairInt;
	
		QSqlQuery query2(getChairName);
	
		while ( query2.next() ) {
			getChairName = query2.value(0).toString();
			getChairName += " " + query2.value(1).toString();
		}
		cNameLabel->setText(getChairName);
	} else {
		cNameLabel->setText("None");
	}

	QString getSecretaryInt  = "SELECT secretary_id FROM committees WHERE id = " + CommitteeNum;
	
	QSqlQuery query3(getSecretaryInt);
	
	while ( query3.next() ) {
		getSecretaryInt = query3.value(0).toString();
	}
	if(getSecretaryInt != NULL){

		QString getSecretaryName = "SELECT first_name, last_name FROM users WHERE id = " + getSecretaryInt;
	
		QSqlQuery query4(getSecretaryName);
	
		while ( query4.next() ) {
			getSecretaryName = query4.value(0).toString();
			getSecretaryName += " " + query4.value(1).toString();
		}
		sNameLabel->setText(getSecretaryName);
	} else {
		sNameLabel->setText("None");
	}

	// store user's id
	QString text = "SELECT id FROM users WHERE user_name = '" + userName +"'";
	QSqlQuery query5(text);
	while(query5.next()){
		userID = query5.value(0).toString();
	}

	// hide all columns except username, last name, first name
	constituentView->setColumnHidden(0, true);
	constituentView->setColumnHidden(1, true);
	constituentView->setColumnHidden(3, true);
	constituentView->setColumnHidden(6, true);
	constituentView->setColumnHidden(7, true);
	constituentView->setColumnHidden(8, true);
	constituentView->setColumnHidden(9, true);
	constituentView->setColumnHidden(10, true);
	constituentView->setColumnHidden(11, true);
	constituentView->setColumnHidden(12, true);
	constituentView->setColumnHidden(13, true);
	constituentView->setColumnHidden(14, true);
	
	QHeaderView *constituentHeader = constituentView->horizontalHeader();
	constituentHeader->setStretchLastSection(true);

	connect(addTaskButton, SIGNAL(clicked()), this, SLOT(addTask()));
	connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(deleteTaskButton, SIGNAL(clicked()), this, SLOT(deleteTask()));
	connect(markTaskCompletedButton, SIGNAL(clicked()), this, SLOT(markTaskCompleted()));
	connect(printCommitteeButton, SIGNAL(clicked()), this, SLOT(printCommittee()));
	connect(printTaskButton, SIGNAL(clicked()), this, SLOT(printTask()));
	connect(promoteChairButton, SIGNAL(clicked()), this, SLOT(promoteChair()));
	connect(promoteSecretaryButton, SIGNAL(clicked()), this, SLOT(promoteSecretary()));
	connect(moreButton, SIGNAL(clicked()), this, SLOT(displayDescription()));
	
	committeeNameLabel->setText(committeeName);
}
void CommitteeInformation::addTask(){
	
	QString text = "SELECT chair_id FROM committees WHERE name = '" + committeeName + "'";
	QSqlQuery query(text);
	QString chairID;
	while(query.next()){
		chairID = query.value(0).toString();
	}

	if(chairID == userID || userName == "coord"){
	AddTask *at = new AddTask(committeeName,this);
	at->show();
	}
	else {
		QMessageBox::warning(this, qApp->tr("AAAAAAAAAAAA!"),
			qApp->tr("YOU CAN'T DO THAT!!!!.\n"),
			QMessageBox::Ok);
	}
}
void CommitteeInformation::refreshTask(){
	Tmodel->select();
}
void CommitteeInformation::deleteTask(){
	QString text = "SELECT chair_id FROM committees WHERE name = '" + committeeName+"'";
	QSqlQuery query(text);
	QString chairID;
	while(query.next()){
		chairID = query.value(0).toString();
	}

	if(chairID == userID || userName == "coord"){
	// ask for confirmation first
	int ret = QMessageBox::question(this, qApp->tr("Confirm delete task"),
			qApp->tr("Are you sure you want to delete this task?.\n"),
			QMessageBox::Ok | QMessageBox::Cancel);
	
	if(ret == QMessageBox::Ok){
		QItemSelectionModel *selected = taskView->selectionModel();
		QModelIndex index = selected->currentIndex();

		Tmodel->removeRows(index.row(), 1, QModelIndex());
		}
	}
	else {
		QMessageBox::warning(this, qApp->tr("AAAAAAAAAAAA!"),
			qApp->tr("YOU CAN'T DO THAT!!!!.\n"),
			QMessageBox::Ok);
	}

}
void CommitteeInformation::markTaskCompleted(){
	QString text = "SELECT chair_id FROM committees WHERE name = '" + committeeName+"'";
	QSqlQuery query(text);
	QString chairID;
	while(query.next()){
		chairID = query.value(0).toString();
	}

	if(chairID == userID || userName == "coord"){
	QItemSelectionModel *selected = taskView->selectionModel();
	QModelIndex index = selected->currentIndex();

	QSqlRecord record = Tmodel->record(index.row());
	QString tID = record.value(0).toString();
	QString toChange = "UPDATE tasks\nSET is_complete=1\nWHERE id = "+tID; 
	QSqlQuery query;
	query.exec(toChange);
	Tmodel->select();
	}
	else {
		QMessageBox::warning(this, qApp->tr("AAAAAAAAAAAA!"),
			qApp->tr("YOU CAN'T DO THAT!!!!.\n"),
			QMessageBox::Ok);
	}
}

void CommitteeInformation::promoteChair(){
	QString text = "SELECT chair_id FROM committees WHERE name = '" + committeeName + "'";
	QSqlQuery query(text);
	QString chairID;
	while(query.next()){
		chairID = query.value(0).toString();
	}

	if(chairID == userID || userName == "coord"){
		QItemSelectionModel *selected = constituentView->selectionModel();
		QModelIndex index = selected->currentIndex();

		QSqlRecord record = CLmodel->record(index.row());
		QString newChairID = record.value(0).toString();
		
		int ret = QMessageBox::question(this, qApp->tr("Confirm promoting to chair"),
			qApp->tr("Are you sure you want to make this person a chair?.\n"),
			QMessageBox::Ok | QMessageBox::Cancel);
	
		if(ret == QMessageBox::Ok){
			QString texty = "UPDATE committees SET chair_id = " + newChairID +" WHERE name = '" + committeeName+"'";
			QSqlQuery query1;
			query1.exec(texty);
			QString getChairName = "SELECT first_name, last_name FROM users WHERE id = " + newChairID;
	
		QSqlQuery query2(getChairName);
	
		while ( query2.next() ) {
			getChairName = query2.value(0).toString();
			getChairName += " " + query2.value(1).toString();
		}
			if(getChairName != "SELECT first_name, last_name FROM users WHERE id = " + newChairID){
		cNameLabel->setText(getChairName);
		}
		}
		
	} else {
		QMessageBox::warning(this, qApp->tr("AAAAAAAAAAAA!"),
			qApp->tr("YOU CAN'T DO THAT!!!!.\n"),
			QMessageBox::Ok);
	}
}
void CommitteeInformation::promoteSecretary(){
	QString text = "SELECT chair_id FROM committees WHERE name = '" + committeeName +"'";
	QSqlQuery query(text);
	QString chairID;
	while(query.next()){
		chairID = query.value(0).toString();
	}

	if(chairID == userID || userName == "coord"){
		QItemSelectionModel *selected = constituentView->selectionModel();
		QModelIndex index = selected->currentIndex();

		QSqlRecord record = CLmodel->record(index.row());
		
		QString newSecretaryID = record.value(0).toString();
		qDebug() << newSecretaryID << endl;
		
		int ret = QMessageBox::question(this, qApp->tr("Confirm promoting to secretary"),
			qApp->tr("Are you sure you want to make this person a secretary?.\n"),
			QMessageBox::Ok | QMessageBox::Cancel);
	
		if(ret == QMessageBox::Ok){
			QString texty = "UPDATE committees SET secretary_id = '" + newSecretaryID +"' WHERE name = '" + committeeName+"'";
			QSqlQuery query1;
			qDebug() << query1.exec(texty) << endl;
			QString getSecretaryName = "SELECT first_name, last_name FROM users WHERE id = " + newSecretaryID;
	
		QSqlQuery query2(getSecretaryName);
	
		while ( query2.next() ) {
			getSecretaryName = query2.value(0).toString();
			getSecretaryName += " " + query2.value(1).toString();
		}
		if(getSecretaryName != "SELECT first_name, last_name FROM users WHERE id = " + newSecretaryID){
		sNameLabel->setText(getSecretaryName);
			}
		}
		
	} else {
		QMessageBox::warning(this, qApp->tr("AAAAAAAAAAAA!"),
			qApp->tr("YOU CAN'T DO THAT!!!!.\n"),
			QMessageBox::Ok);
	}
	
}

void CommitteeInformation::displayDescription(){
		QItemSelectionModel *selected = taskView->selectionModel();
		QModelIndex index = selected->currentIndex();
		QSqlRecord record = Tmodel->record(index.row());
		QString tID = record.value(2).toString();

		
QMessageBox::information(this, qApp->tr("Description"),
			qApp->tr(tID.toStdString().c_str()),
			QMessageBox::Ok);
}

void CommitteeInformation::printCommittee(){

/*
CREATE TABLE committees (

0	id INTEGER PRIMARY KEY, 
1	name TEXT, 
2	chair_id INTEGER, 
3	secretary_id INTEGER);
*/

	//Setup my table model to interact with database table
	QSqlTableModel* model = new QSqlTableModel(this);
	model->setTable("committees");
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);
	model->select();

	//Setup my output string (later to be printed).

	QString toPrint ="Committee Information\n-------------------------------------------------------------------------------------------------------------------------\n\n",unitSt="",t;

	//Fill the string with a list of Committees.
	for(int i=0;i<model->rowCount();i++){

		qDebug() << "Committee Name: " << model->data(model->index(i,1)).toString();
		toPrint=toPrint+"+  "+model->data(model->index(i,1)).toString()+":\n";
		
		QString getMembers = "SELECT last_name,first_name,id FROM users WHERE committee_id = '" + model->data(model->index(i,0)).toString() +"' AND is_resident = 1";
	
		QSqlQuery query(getMembers);
		while(query.next()){

			toPrint=toPrint+"\n\t"+query.value(0).toString()+", "+query.value(1).toString();

			//Is member a chair?
			if(model->data(model->index(i,2)).toInt()==query.value(2).toInt()){
				toPrint=toPrint+" :: Committee Chair";
			//Is they a secretary?
			}else if(model->data(model->index(i,3)).toInt()==query.value(2).toInt()){
				toPrint=toPrint+" :: Committee Secretary";
			}

		}

		toPrint=toPrint+"\n\n\n";

	}
	
	//Convert to a document and print.
	QTextDocument *doc = new QTextDocument();
	doc->setPlainText(toPrint);

	QPrinter printer(QPrinter::ScreenResolution);
	printer.setPaperSize(QPrinter::Letter);
	printer.setDocName("cooper/printCommittees.pdf");
	printer.setColorMode(QPrinter::GrayScale);
	printer.setOutputFormat(QPrinter::PdfFormat);

	QPrintDialog dlg(&printer, this);

	if (dlg.exec() == QDialog::Accepted){
		doc->print(&printer);
	}
	qDebug() << "Printed";

}
void CommitteeInformation::printTask(){

/*
CREATE TABLE tasks (

0	id INTEGER PRIMARY KEY,
1	title TEXT, 
2	description TEXT, 
3	committee_id INTEGER, 
4	is_complete INTEGER, 
5	due_date TEXT, 
6	is_annual INTEGER);

*/

	//Setup my table model to interact with database table
	QSqlTableModel* model = new QSqlTableModel(this);
	model->setTable("tasks");
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);
	model->setFilter("committee_id = '" + CommitteeNum + "'");
	model->select();

	//Setup my output string (later to be printed).

	QString toPrint =committeeName+" Committee Task List\n-------------------------------------------------------------------------------------------------------------------------\n\n",unitSt="",t;

	QDate date;
	QString cTask;

	//Fill the string with a list of tasks.
	for(int i=0;i<model->rowCount();i++){

		toPrint=toPrint+"[  ] ";
		cTask=model->data(model->index(i,1)).toString();
		//Past due?
		if(QDate::currentDate() > date.fromString(model->data(model->index(i,5)).toString())){
			cTask.toUpper();
			cTask=cTask+" - OVERDUE ";
		}

		toPrint=toPrint+cTask+":\n\n\t"+model->data(model->index(i,2)).toString()+"\n\n";

	}
	
	//Convert to a document and print.
	QTextDocument *doc = new QTextDocument();
	doc->setPlainText(toPrint);

	QPrinter printer(QPrinter::ScreenResolution);
	printer.setPaperSize(QPrinter::Letter);
	printer.setDocName("cooper/print"+committeeName+"CommitteeTasks.pdf");
	printer.setColorMode(QPrinter::GrayScale);
	printer.setOutputFormat(QPrinter::PdfFormat);

	QPrintDialog dlg(&printer, this);

	if (dlg.exec() == QDialog::Accepted){
		doc->print(&printer);
	}
	qDebug() << "Printed";

}
