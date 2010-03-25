CREATE TABLE units (id INTEGER PRIMARY KEY, unit_number TEXT, street_address TEXT, num_bedrooms INTEGER);
CREATE TABLE users (id INTEGER PRIMARY KEY, is_coordinator INTEGER, user_name TEXT, password TEXT, last_name TEXT, first_name TEXT, is_21 INTEGER, committee_id INTEGER, is_resident INTEGER, unit_id INTEGER, phone_number TEXT, phone_number_is_public INTEGER, in_arrears INTEGER, old_address TEXT, move_in_date TEXT);
CREATE TABLE committees (id INTEGER PRIMARY KEY, name TEXT, chair_id INTEGER, secretary_id INTEGER);
CREATE TABLE tasks (id INTEGER PRIMARY KEY, title TEXT, description TEXT, committee_id INTEGER, is_complete INTEGER, due_date TEXT, is_annual INTEGER);
