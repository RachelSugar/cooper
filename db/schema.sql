CREATE TABLE units (id INTEGER PRIMARY KEY, number TEXT);
CREATE TABLE users (id INTEGER PRIMARY KEY, age INTEGER, is_coordinator INTEGER, user_name TEXT, password TEXT, first_name TEXT, last_name TEXT, committee_id INTEGER, is_resident INTEGER, unit_id INTEGER, phone_number TEXT, phone_number_is_public INTEGER, in_arrears INTEGER);
CREATE TABLE committees (id INTEGER PRIMARY KEY, name TEXT, chair_id INTEGER, secretary_id INTEGER);
CREATE TABLE tasks (id INTEGER PRIMARY KEY, description TEXT, committee_id INTEGER, is_complete INTEGER, due_date TEXT);

