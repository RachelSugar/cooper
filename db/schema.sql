CREATE TABLE units (id INTEGER PRIMARY KEY, number TEXT);
CREATE TABLE users (id INTEGER PRIMARY KEY, is_coordinator INTEGER, user_name TEXT, password TEXT, last_name TEXT, first_name TEXT, age INTEGER, committee_id INTEGER, is_resident INTEGER, unit_id INTEGER, phone_number TEXT, phone_number_is_public INTEGER, in_arrears INTEGER, under_twenty TEXT);
CREATE TABLE committees (id INTEGER PRIMARY KEY, name TEXT, chair_id INTEGER, secretary_id INTEGER);
CREATE TABLE tasks (id INTEGER PRIMARY KEY, description TEXT, committee_id INTEGER, is_complete INTEGER, due_date TEXT);
INSERT INTO users VALUES (NULL, 0, 'kfucker', 'sex', 'Fielding', 'Kevin', 9, 2, 1, 223, '519-886-1111', 1, 0, 'yes');
INSERT INTO users VALUES (NULL, 0, 'ahardgay', 'sex', 'Gray', 'Dick', 22, 2, 1, 223, '519-886-0000', 1, 0, 'yes');
INSERT INTO units VALUES (223, '50A');
