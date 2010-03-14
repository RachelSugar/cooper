CREATE TABLE units (id INTEGER PRIMARY KEY, unit_number TEXT, street_address TEXT, num_bedrooms INTEGER, member TEXT);
CREATE TABLE users (id INTEGER PRIMARY KEY, is_coordinator INTEGER, user_name TEXT, password TEXT, last_name TEXT, first_name TEXT, age INTEGER, committee_id INTEGER, is_resident INTEGER, unit_id INTEGER, phone_number TEXT, phone_number_is_public INTEGER, in_arrears INTEGER, under_twenty TEXT);
CREATE TABLE committees (id INTEGER PRIMARY KEY, name TEXT, chair_id INTEGER, secretary_id INTEGER);
CREATE TABLE tasks (id INTEGER PRIMARY KEY, description TEXT, committee_id INTEGER, is_complete INTEGER, due_date TEXT);
INSERT INTO users VALUES (NULL, 0, 'kpucker', 'xxx', 'Fielding', 'Kevin', 9, 2, 1, 223, '519-886-1111', 1, 0, '');
INSERT INTO users VALUES (NULL, 0, 'ahardgay', 'xxx', 'Gray', 'Mick', 22, 2, 1, 223, '519-886-0000', 1, 0, '');
INSERT INTO users VALUES (NULL, 0, 'shimaymay', 'xxx', 'Wray', 'Shick', 22, 2, 1, 1, '519-886-XXXX', 0, 0, '');
