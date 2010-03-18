#include <QtGui> 
#include "EditUser.h"
#include <QSqlQuery>
// including <QtGui> saves us to include every class user, <QString>, <QFileDialog>,...
QString username;
EditUser::EditUser(QWidget *parent,QString usName)
{
	setupUi(this); // this sets up GUI

	// signals/slots mechanism in action
	connect( saveCancel, SIGNAL( rejected() ), this, SLOT( close() ));
	connect( saveCancel, SIGNAL( accepted() ), this, SLOT( getSave() ) ); 
	connect( deleteUser, SIGNAL(clicked() ), this, SLOT( deleteUse() ) );
	connect( getUser, SIGNAL(clicked() ), this, SLOT( getToEdit() ) ); 
	username = usName;
	
	// load the unit numbers into the combo box
	QString queer = "SELECT unit_number FROM units";
	QSqlQuery query(queer);
	while(query.next()){
		 queer=query.value(0).toString();
		 unitNum->addItem(queer);
	}
	
	// load the committee names into the combo box
	QString q = "SELECT name FROM committees";
	QSqlQuery query2(q);
	while(query2.next()){
		 q=query2.value(0).toString();
		 committee->addItem(q);
	}
	
	// disable features for non-admin users
	if(username != "coord"){
		getUser->setEnabled(false);
		deleteUser->setEnabled(false);
		movedOut->setEnabled(false);
		firstName->setEnabled(false);
	 	lastName->setEnabled(false);
	 	userName->setEnabled(false);
		userEdit->setEnabled(false);
	 	telephone->setEnabled(false);
		owing->setEnabled(false);
		pastAddress->setEnabled(false);
		over21->setEnabled(false);
		committee->setEnabled(false);
		unitNum->setEnabled(false);
		moveInDate->setEnabled(false);
		privateTele->setEnabled(false);
		fillMemberInfo(username);
	}
}

// save the info from the form into the users db
void EditUser::getSave()
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
	QString movDate = moveInDate->date().toString();
	bool hidden = privateTele->isChecked();
	bool ofAge = over21->isChecked();
	bool mvOut = movedOut->isChecked(); 
	
	QString unitx = unitNum->currentText();
	QString commit = committee->currentText();
	
	QString t = "SELECT id FROM units WHERE unit_number = '" + unitx + "'";
	QSqlQuery q(t);
	q.next();
	QString unit = q.value(0).toString();

        // If the user is the chair or secretary of a committe already, erase
        // entry in commmittees table
        t = "SELECT id, committee_id FROM users WHERE user_name= '" + uName + "'";
        q.clear();
        q.exec(t);
        q.next();
        QString uID = q.value(0).toString();
        QString uCommittee = q.value(1).toString();
        t = "SELECT chair_id, secretary_id FROM committees WHERE id= " + uCommittee;
        q.clear();
        q.exec(t);
        q.next();
        QString chair = q.value(0).toString();
        QString secretary = q.value(1).toString();
        if ( uID == chair ) {
                t = "UPDATE committees SET chair_id=NULL WHERE id= " + uCommittee;
                q.clear();
                q.exec(t);
        } else if ( uID == secretary ){
                t = "UPDATE committees SET secretary_id=NULL WHERE id=" + uCommittee;
                q.clear();
                q.exec(t);
        }

	QString s = "SELECT id FROM committees WHERE name = '" + commit + "'";
	QSqlQuery que(s);
	que.next();
	commit = que.value(0).toString();
	
	//cheap error detection for time being
	if((fName.length() == 0 || lName.length() == 0 || uName.length() == 0 \
			|| tele.length() < 10 || pastAdd.length() == 0) && uName != "coord"){
			QMessageBox::critical(0, qApp->tr("Error:"),	
			qApp->tr("Please fill in all fields.\n"),
			QMessageBox::Cancel);
	}
	else{
		char phonePublic;
		if(hidden == true) {
			phonePublic = '0';
		}
		else {
			phonePublic = '1';
		}
		char age;
		
		if(ofAge == true) {
			age = '1';
		}
		else {
			age = '0';
		}
		char live;	
		if(mvOut == true) {
			live = '0';
		}
		else {
			live = '1';
		}
		if(uName != "coord") {
			// put the info into the users db
			QString text = "UPDATE users \
				SET user_name = '" + uName +"', last_name = '" + lName + "', first_name = '" + fName + "', unit_id = '" + unit + "', phone_number = '" + tele +"', phone_number_is_public = '" + phonePublic + "', is_21 = '" + age + "', is_resident = '" + live + "', \
	 			in_arrears = '" + owe + "', committee_id = '" + commit + "', old_address = '" + pastAdd + "', move_in_date = '" + movDate + "', password = '" + pass + "' WHERE user_name = '" + userEdit->text() + "';";

			QSqlQuery query;
			query.exec(text);
		}
		else {
			// only change the password
			QString s = "UPDATE users SET password = '" + pass + "' WHERE user_name = 'coord';";
			qDebug() << s;
			QSqlQuery sql;
			sql.exec(s);
		}

	}
	this->close();
}

// remove a member who is no longer living in the coop from the db
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

// pass the user name in the edit slot to fill in the info
// used by admin only
void EditUser::getToEdit(){
	QString usrName = userEdit->text();
	
	// only allowed to edit the password for coord
	if(usrName == "coord") {
		QString text = "SELECT password FROM users WHERE user_name = '" + usrName + "'";
		QSqlQuery query(text);
		query.next();
		QString pass = query.value(0).toString();
		password->setText(pass);
		
		deleteUser->setEnabled(false);
		movedOut->setEnabled(false);
		firstName->setEnabled(false);
	 	lastName->setEnabled(false);
	 	userName->setEnabled(false);
	 	telephone->setEnabled(false);
		owing->setEnabled(false);
		pastAddress->setEnabled(false);
		over21->setEnabled(false);
		committee->setEnabled(false);
		unitNum->setEnabled(false);
		moveInDate->setEnabled(false);
		privateTele->setEnabled(false);
		
		committee->setCurrentIndex(0);
		unitNum->setCurrentIndex(-1);
		firstName->setText("");
	 	lastName->setText("");
	 	telephone->setText("");
		owing->setText("");
		pastAddress->setText("");
	}
	
	// can see everything else for everyone else
	else {
		if(username == "coord"){
			deleteUser->setEnabled(true);
			movedOut->setEnabled(true);
			firstName->setEnabled(true);
		 	lastName->setEnabled(true);
		 	userName->setEnabled(true);
		 	telephone->setEnabled(true);
			owing->setEnabled(true);
			pastAddress->setEnabled(true);
			over21->setEnabled(true);
			committee->setEnabled(true);
			unitNum->setEnabled(true);
			moveInDate->setEnabled(true);
			privateTele->setEnabled(true);
		}
		fillMemberInfo(usrName);
	}
}

// fill the information in the form from the users db
void EditUser::fillMemberInfo(QString userName) {
	QString answer[15];
	QString text = "SELECT * FROM users WHERE user_name = '" + userName + "'";
	QSqlQuery query(text);
	while(query.next()){
	 	for(int x = 0; x < 15; x++){
         	answer[x] = query.value(x).toString();
        }
    }
	
	QString text2 = "SELECT unit_number FROM units WHERE id = '" + answer[9] + "'";
	QSqlQuery q(text2);
	q.next();
	QString unitNumber = q.value(0).toString();
	int index = unitNum->findText(unitNumber);
	
	QString text3 = "SELECT name FROM committees WHERE id = '" + answer[7] + "'";
	QSqlQuery qu(text3);
	qu.next();
	QString comm = qu.value(0).toString();
	int i = committee->findText(comm);
	
	committee->setCurrentIndex(i);
	unitNum->setCurrentIndex(index);
	firstName->setText(answer[5]);
 	lastName->setText(answer[4]);
 	userEdit->setText(answer[2]);
 	telephone->setText(answer[10]);
	password->setText(answer[3]);
	owing->setText(answer[12]);
	pastAddress->setText(answer[13]);
	QDate date;
	date = date.fromString(answer[14]);
	moveInDate->setDate(date);
	
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
	if(answer[6] == "1") {
		over21->setChecked(true);
	}
	else {
		over21->setChecked(false);
	}
	
}