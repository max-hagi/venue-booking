#include "headers.h"
#include "Logger.h"

char* error_message;
int return_code;
std::string query;



// --- Constructor ---
Logger::Logger(const char *newName) {
    //--- Creating Database ---
    return_code = sqlite3_open(newName, &db);
    if (return_code != SQLITE_OK){ //If database was unable to be created
        fprintf(stderr, "Unable to open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
    } else{
        std::cout << "Connected to database \"" << newName << "\"" << std::endl;
    }

    //--- Creating table for venues ---
    query = "CREATE TABLE IF NOT EXISTS venues (name VARCHAR(255) UNIQUE, location VARCHAR(255), availability INT(255), price FLOAT(255,2), description VARCHAR(255), rating INT(255));";
    return_code = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &error_message);

    if (return_code != SQLITE_OK){
        std::cerr << "Error creating venues table: " << return_code << std::endl;
        sqlite3_free(error_message);
        sqlite3_close(db);
        exit(1);
    }
    else{
        std::cout << "Connected to venues table" << std::endl;
    }


    //--- Creating table for users ---
    query = "CREATE TABLE IF NOT EXISTS users (username VARCHAR(255) UNIQUE, password VARCHAR(255), status VARCHAR(225));";
    return_code = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &error_message);

    if (return_code != SQLITE_OK){
        std::cerr << "Error creating users table: " << return_code << std::endl;
        sqlite3_free(error_message);
        sqlite3_close(db);
        exit(1);
    }
    else{
        std::cout << "Connected to users table" << std::endl;
    }

    //--- Creating table for businesses ---
    query = "CREATE TABLE IF NOT EXISTS businesses (username VARCHAR(255) UNIQUE, password VARCHAR(255), venue VARCHAR(225));";
    return_code = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &error_message);

    if (return_code != SQLITE_OK){
        std::cerr << "Error creating businesses table: " << return_code << std::endl;
        sqlite3_free(error_message);
        sqlite3_close(db);
        exit(1);
    }
    else{
        std::cout << "Connected to businesses table" << std::endl;
    }


    //--- Creating booking tables for every venue ---
    std::vector<VenueLog> venues = readVenues();
    for (auto &venue : venues){
        std::string venueName = venue.getName();

        query = "CREATE TABLE IF NOT EXISTS " + venueName + " (date VARCHAR(255), time VARCHAR(255), number INT(255), email VARCHAR(255), price FLOAT(255,2));";

        return_code = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &error_message);

        if (return_code != SQLITE_OK){
            std::cerr << "Error creating bookings table for: " << venueName << " Error Code: " << return_code << std::endl;
            sqlite3_free(error_message);
            sqlite3_close(db);
            exit(1);
        }
        else{
            std::cout << "Connected to bookings table for " << venueName << std::endl;
        }
    }

}

Logger::~Logger() {
    sqlite3_close(db);
}

//Write to venues
void Logger::writeToVenues(const std::string &venue_name, const std::string& location, int availability, float price,
                           const std::string& description, int rating) {

    query = "INSERT INTO venues VALUES (\""+ venue_name +"\", \"" + location +"\", \""+ std::to_string(availability) +"\", \""+
            std::to_string(price)+"\", \""+description+"\", \""+ std::to_string(rating)+"\");";

    return_code = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &error_message);

    if (return_code != SQLITE_OK){
        std::cerr << "Error inserting into venues: " << return_code << std::endl;
        sqlite3_free(error_message);
    }
    else{
        std::cout << "Inserted into venues" << std::endl;
    }
}

//Write to bookings
void Logger::writeToBookings(const std::string &date, const std::string &time, int availability, const std::string &email,
                             float cost, const std::string &venueName) {

    query = "INSERT INTO " + venueName + " VALUES (\"" + date + "\", \""+ time + "\", \"" + std::to_string(availability) + "\", \"" + email + "\", \"" +
            std::to_string(cost) + "\");";

    return_code = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &error_message);

    if (return_code != SQLITE_OK){
        std::cerr << "Error inserting into bookings for " << venueName << return_code << std::endl;
        sqlite3_free(error_message);
    }
    else{
        std::cout << "Inserted into bookings for " << venueName << std::endl;
    }
}


//Write to users
int Logger::writeToUsers(const std::string &acc_name, const std::string &acc_password, const std::string &status) {
    query = "INSERT INTO users VALUES (\""+ acc_name +"\", \"" + acc_password +"\", \""+ status +"\");";

    return_code = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &error_message);

    if (return_code != SQLITE_OK){
        std::cerr << "Error inserting into users: " << return_code << std::endl;
        sqlite3_free(error_message);
        return -1;
    }
    else{
        std::cout << "Inserted into users" << std::endl;
        return 0;
    }
}

//Write to businesses
int Logger::writeToBusinesses(const std::string &acc_name, const std::string &acc_password, const std::string &venue) {
    query = "INSERT INTO businesses VALUES (\""+ acc_name +"\", \"" + acc_password +"\", \""+ venue + "\");";

    return_code = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &error_message);

    if (return_code != SQLITE_OK){
        std::cerr << "Error inserting into businesses: " << return_code << std::endl;
        sqlite3_free(error_message);
        return -1;
    }
    else{
        std::cout << "Inserted into businesses" << std::endl;
        return 0;
    }
}

std::string Logger::getName() {
    return name;
}

//Reading from users
std::vector<User> Logger::readUsers(){
    sqlite3_stmt* statement;
    std::vector<User> logs;

    query = "Select * from users;";
    return_code = sqlite3_prepare_v2(db, query.c_str(), strlen(query.c_str()), &statement,nullptr);

    if(return_code!= SQLITE_OK) {
        std::cout << "Error reading from users" << return_code << std::endl;
    }

    while (sqlite3_step(statement) == SQLITE_ROW) {
        std::string username = (char *) sqlite3_column_text(statement, 0);
        std::string password = (char *) sqlite3_column_text(statement, 1);
        std::string status = (char *) sqlite3_column_text(statement, 2);
        User log (username, password, status);
        logs.push_back(log);
    }

    return_code = sqlite3_finalize(statement);
    if(return_code!= SQLITE_OK) {
        std::cout << "Error reading from users" << std::endl;
    }
    return logs;
}

//Reading from businesses
std::vector<Business> Logger::readBusinesses() {
    sqlite3_stmt* statement;
    std::vector<Business> logs;

    query = "Select * from businesses;";
    return_code = sqlite3_prepare_v2(db, query.c_str(), strlen(query.c_str()), &statement,nullptr);

    if(return_code!= SQLITE_OK) {
        std::cout << "Error reading from businesses" << return_code << std::endl;
    }

    while (sqlite3_step(statement) == SQLITE_ROW) {
        std::string username = (char *) sqlite3_column_text(statement, 0);
        std::string password = (char *) sqlite3_column_text(statement, 1);
        std::string venue = (char *) sqlite3_column_text(statement, 2);
        Business log(username, password, venue);
        logs.push_back(log);
    }

    return_code = sqlite3_finalize(statement);
    return logs;
}


std::vector<VenueLog> Logger::readVenues(){
    sqlite3_stmt* statement;
    std::vector<VenueLog> logs;

    query = "Select * from venues;";
    return_code = sqlite3_prepare_v2(db, query.c_str(), strlen(query.c_str()), &statement,nullptr); //FIXME

    if(return_code!= SQLITE_OK) {
        std::cout << "Error reading from venues" << std::endl;
    }

    while (sqlite3_step(statement) == SQLITE_ROW) {
        std::string venueName = (char *) sqlite3_column_text(statement, 0);
        std::string location = (char *) sqlite3_column_text(statement, 1);
        int availability =  std::stoi((char *)sqlite3_column_text(statement, 2));
        float price = std::stof((char *) sqlite3_column_text(statement, 3));
        std::string description = (char *) sqlite3_column_text(statement, 4);
        int rating = std::stoi((char *) sqlite3_column_text(statement, 5));

        VenueLog log(venueName,location, availability, price, description, rating);
        logs.push_back(log);
    }

    return_code = sqlite3_finalize(statement);
    return logs;
}

std::vector<BookingLog> Logger::readBookings(const std::string& venueName) {
    sqlite3_stmt* statement;
    std::vector<BookingLog> logs;

    query = "Select * from " + venueName + ";";
    return_code = sqlite3_prepare_v2(db, query.c_str(), strlen(query.c_str()), &statement,nullptr); //FIXME

    if(return_code!= SQLITE_OK) {
        std::cout << "Error reading bookings from " << venueName << std::endl;
    }

    while (sqlite3_step(statement) == SQLITE_ROW) {
        std::string date = (char *) sqlite3_column_text(statement, 0);
        std::string time = (char *) sqlite3_column_text(statement, 1);
        int number =  std::stoi((char *)sqlite3_column_text(statement, 2));
        std::string email = (char *) sqlite3_column_text(statement, 3);
        float price = std::stof((char *) sqlite3_column_text(statement, 4));

        BookingLog log(date, time, number, email, price);
        logs.push_back(log);
    }

    return_code = sqlite3_finalize(statement);
    return logs;
}




