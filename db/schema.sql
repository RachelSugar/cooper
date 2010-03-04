CREATE TABLE Units (id INTEGER PRIMARY KEY, number TEXT);
CREATE TABLE Users (id INTEGER PRIMARY KEY, is_coordinator INTEGER, user_name TEXT, password TEXT, first_name TEXT, last_name TEXT, committee_id INTEGER, is_resident INTEGER, unit_id INTEGER, phone_number TEXT, phone_number_is_public INTEGER, in_arrears INTEGER);
CREATE TABLE Committees (id INTEGER PRIMARY KEY, name TEXT, chair_id INTEGER, secretary_id INTEGER);
CREATE TABLE Tasks (id INTEGER PRIMARY KEY, description TEXT, committee_id INTEGER, is_complete INTEGER, due_date TEXT);
