CREATE TABLE Units (id int NOT NULL PRIMARY KEY, number varchar(255));
CREATE TABLE Users (id int NOT NULL PRIMARY KEY, is_coordinator boolean, user_name varchar(255), password varchar(255), first_name varchar(255), last_name varchar(255), committee_id int, is_resident boolean, unit_id int, phone_number varchar(255), phone_number_is_public boolean, in_arrears boolean);
CREATE TABLE Committees (id int NOT NULL PRIMARY KEY, name varchar(255), chair_id int, secretary_id int);
CREATE TABLE Tasks (id int NOT NULL PRIMARY KEY, description varchar(255), committee_id int, is_complete boolean, due_date date);
