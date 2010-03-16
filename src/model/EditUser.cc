#include <QtGui> 
#include "EditUser.h"
#include <QSqlQuery>
// including <QtGui> saves us to include every class user, <QString>, <QFileDialog>,...

EditUser::EditUser(QWidget *parent,QString username)
{
	setupUi(this); // this sets up GUI

	// signals/slots mechanism in action
	
	connect( saveCancel, SIGNAL( rejected() ), this, SLOT( close() ));
	connect( saveCancel, SIGNAL( accepted() ), this, SLOT( getSave(username) ) ); 
	connect( deleteUser, SIGNAL(clicked() ), this, SLOT( deleteUse() ) );
	connect( getUser, SIGNAL(clicked() ), this, SLOT( getToEdit() ) ); 
	
	if(username != "coord"){
		//saveCancel->setEnabled(false);
		getUser->setEnabled(false);
		deleteUser->setEnabled(false);
		movedOut->setEnabled(false);
		firstName->setEnabled(false);
	 	lastName->setEnabled(false);
	 	userName->setEnabled(false);
		userEdit->setEnabled(false);
	 	telephone->setEnabled(false);
	 	//unit->setText(answer[9]);
		owing->setEnabled(false);
		pastAddress->setEnabled(false);
		over21->setEnabled(false);
		committee->setEnabled(false);
		position->setEnabled(false);
		unitNum->setEnabled(false);
		moveInDate->setEnabled(false);
		privateTele->setEnabled(false);
		fillMemberInfo(username);
	}
}


void EditUser::getSave(QString username)
{
	//get values of fields in GUI
	QString uName;
	if(username != "coord"){
		uName = userEdit->text();
	}
	else {
		if(userName->text() != ""){
			uName = userName->text();
		}
		else {
			uName = userEdit->text();
		}
	}
	QString fName = firstName->text();
	QString lName = lastName->text();
	QString tele = telephone->text();
	QString pastAdd = pastAddress->text();
	QString pass = password->text();
	QString owe = owing->text();
	//QString unitx = unit->text();
	QDate movDate = moveInDate->date();
	bool hidden = privateTele->isChecked();
	bool ofAge = over21->isChecked();
	bool mvOut = movedOut->isChecked(); 
	
	//cheap error detection for time being
	if(fName.length() == 0 || lName.length() == 0 || uName.length() == 0 \
		|| tele.length() < 10 || pastAdd.length() == 0){
	QMessageBox::critical(0, qApp->tr("Error:"),
			qApp->tr("Please fill in all feilds.\n"),
			QMessageBox::Cancel);
	}
	else{
	
	char phonePublic;
	
	if(hidden == true)
		phonePublic = '0';
	else
		phonePublic = '1';
	
	char age;
		
		if(ofAge == true)
		age = '0';
	else
		age = '1';
	
	char live;	
		if(mvOut == true)
		live = '0';
	else
		live = '1';
	QString text = "UPDATE users \
	SET user_name = '" + uName +"', last_name = '" + lName + "', first_name = '" + fName + "', unit_id = '111', phone_number = '" + tele +"', phone_number_is_public = '" + phonePublic + "', is_21 = '" + age + "', is_resident = '" + live + "', \
	 in_arrears = '" + owe + "', old_address = '" + pastAdd + "', password = '" + pass + "'  WHERE user_name = '" + uName +"';";
	//test data
	QSqlQuery query;
	
	qDebug() << "true?" << query.exec(text);
	qDebug() << "first Name = " << fName;
	qDebug() << "last Name = " << lName;
	qDebug() << "username = " << uName;
	
	qDebug() << "tele# = " << tele;
	qDebug() << "pastAddress = " << pastAdd;
//	qDebug() << "unit = " << unitx;
	qDebug() << "date = " << movDate;	
	qDebug() << "private? = " << hidden;
	qDebug() << "ofAge? = " << ofAge;
	qDebug() << "mvout? = " << mvOut;
	this->close();
	}
  
}

void EditUser::deleteUse(){

	if(movedOut->isChecked() == true){
		QString temp = "DELETE \
		FROM users \
		WHERE user_name = '" + userEdit->text()+ "';";
		QSqlQuery query;
		query.exec(temp);
		this->close();
	}
	else{
		QMessageBox::critical(0, qApp->tr("Error:"),
			qApp->tr("Cannot delete user that\nis not moved out.\n"),
			QMessageBox::Cancel);
	
	}
	
	

}

void EditUser::getToEdit(){
	QString usrName= userEdit->text();
	fillMemberInfo(usrName);
}

void EditUser::fillMemberInfo(QString username) {
	QString answer[15];
	QString text = "SELECT * FROM users WHERE user_name = '" + username + "'";
	QSqlQuery query(text);
	while(query.next()){
	 	for(int x = 0; x < 15; x++){
         	answer[x] = query.value(x).toString();
        }
    }
	firstName->setText(answer[5]);
 	lastName->setText(answer[4]);
 	userEdit->setText(answer[2]);
 	telephone->setText(answer[10]);
 	//unit->setText(answer[9]);
	password->setText(answer[3]);
	owing->setText(answer[12]);
	pastAddress->setText(answer[13]);
	
	if(answer[8] == "0") {
		movedOut->setChecked(true);
	}
	else {
		movedOut->setChecked(false);
	}	
	if(answer[11] == "0") {
		privateTele->setChecked(true);
	}
	else { 
		privateTele->setChecked(false);
	}	
	if(answer[13] == "0") {
		over21->setChecked(true);
	}
	else {
		over21->setChecked(false);
	}
}