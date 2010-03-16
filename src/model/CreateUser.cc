#include <QtGui>
#include "CreateUser.h"
#include <QSqlQuery>
// including <QtGui> saves us to include every class user, <QString>, <QFileDialog>,...

CreateUser::CreateUser(QWidget *parent)
{
	setupUi(this); // this sets up GUI

	// signals/slots mechanism in action
	connect( saveCancel, SIGNAL( rejected() ), this, SLOT( close() ) );
	connect( saveCancel, SIGNAL( accepted() ), this, SLOT( getSave() ) );

	if(parent==0){} //fuck you warning

	QString queer = "SELECT unit_number FROM units";
	QSqlQuery query(queer);
	while(query.next()){
		 queer=query.value(0).toString();
		 unitNumberBox->addItem(queer);
	}

}

void CreateUser::getSave()
{
	//get values of fields in GUI
	QString fName = firstName->text();
	QString lName = lastName->text();
	QString uName = userName->text();
	QString pass = password->text();
	QString tele = telephone->text();
	QString pastAdd = pastAddress->text();
	QString unit = unitNumberBox->currentText();
	QString movDate = moveInDate->date().toString();
	bool hidden = privateTele->isChecked();
	bool ofAge = over21->isChecked();
	bool taken =false;
	
	QString findKey = "SELECT id FROM units WHERE unit_number = '" + unit +"'";
	QSqlQuery query3(findKey);
	int unitID;
	while(query3.next()){
		unitID=query3.value(0).toInt();
	}
	qDebug() << "this is unid id ? " << unitID;

	QString checkID = "SELECT user_name FROM users WHERE user_name = '" + uName +"'";
	
	QSqlQuery query(checkID);
	while(query.next()){
		taken = true;
	}
	
	//cheap error detection for time being
	if ( fName.length() == 0
	     || lName.length() == 0
	     || uName.length() == 0
	     || pass.length() == 0
	     || tele.length() < 10
	     || pastAdd.length() == 0) {
		QMessageBox::critical(0, qApp->tr("Error:"),
			qApp->tr("Please fill in all fields.\n"),
			QMessageBox::Cancel);
			
			
		
	}

	else if(taken == true){
	QMessageBox::critical(0, qApp->tr("Error:"),
			qApp->tr("Username taken!\n"),
			QMessageBox::Cancel);
			userName->clear();
	
	}
	else{

	char hiddenInt = isTrue2(hidden);
	char ofAgeInt = isTrue(ofAge);
	qDebug() << hiddenInt;
	QSqlQuery query2;
	QString test ="INSERT INTO users VALUES(NULL,0,'" + uName + "','" + pass + "','" + lName + 
	"','" + fName + "','"+ ofAgeInt +"',0,1,'"+ unitID + "','" + tele +"','" + hiddenInt +"',0,'"+ pastAdd+ "','"+movDate+"')";
	qDebug() << "Insert user success: " << query2.exec((test));
	this->close();
	}

}

char CreateUser::isTrue(bool toTest)
{
	if(toTest == true)
		return '1';
	else
		return '0';

}

char CreateUser::isTrue2(bool toTest)
{
	if(toTest == true)
		return '0';
	else
		return '1';

}