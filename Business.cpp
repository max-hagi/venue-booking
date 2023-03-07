#include "Logger.h"
#include "Business.h"


Business::Business(std::string username, std::string password, std::string venue) {
    this->username = username;
    this->password = password;
    this->venue = venue;
}

std::string Business::getUsername() {
    return username;
}

std::string Business::getPassword() {
    return password;
}

std::string Business::getVenue() {
    return venue;
}


int Business::verifyCredentials(const std::string &name, const std::string &password) {
//    Logger log = Logger::getInstance();
    Logger log("database");
    std::vector<Business> businesses = log.readBusinesses();

    for (auto &business: businesses) {
        if (business.getUsername() == name && business.getPassword() == password) {
            return 0;
        }
    }
    return -1;
}

/**
 * Function will check the database for a table with the same name as the venue name the business is associated with
 */
std::vector<BookingLog> Business::getBookings() {
    Logger log = Logger("database");
    std::vector<BookingLog> bookings = log.readBookings(venue);
    return bookings;
}