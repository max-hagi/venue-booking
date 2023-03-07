/**
 * @author Maxime Savehilaghi
 * @brief Object that allows the program to interact with the database
 * @file Logger.h
 * @file Logger.cpp
 * **/

#ifndef GROUP26_LOGGER_H
#define GROUP26_LOGGER_H

#include "headers.h"
#include "VenueLog.h"
#include "BookingLog.h"
#include "User.h"
#include "Business.h"

class Logger {
private:
    /**
     * @var Name of the Logger
     */
    const char* name;

    /**
     * @var Pointer to the database the Logger manipulates
     */
    sqlite3* db;

public:
    /// \brief Accesses the database named newName, creates database of that name if one does not already exist
    /// \param newName Name of the database to be accessed
    explicit Logger(const char* newName);

    /**
     * \brief Destructor for the Logger
     */
    virtual ~Logger();


    /// \brief Function that gets the name of the database the Logger accesses
    /// \return Name of the database file
    std::string getName();

    /// \brief Function that adds a new venue to the venue table
    /// \param venue_name Name of the venue
    /// \param location City where the venue is located
    /// \param availability Capacity of venue
    /// \param price Price for customer to book reservation
    /// \param description Description of venue
    /// \param rating Rating out of 5
    void writeToVenues(const std::string &venue_name,
                       const std::string& location,
                       int availability,
                       float price,
                       const std::string& description,
                       int rating);

    ///
    /// \brief Function that adds a new booking to the booking table for the provided venue
    /// \param date Date of the booking
    /// \param time Time of the booking
    /// \param number Number of people being booked for
    /// \param email Email associated with the booking
    /// \param cost Total cost
    /// \param venueName Name of the venue being booked
    void writeToBookings(const std::string &date, const std::string &time,
                         int number,
                         const std::string& email,
                         float cost,
                         const std::string &venueName);

    /**
     * @brief Function to add new User entry to the users table
     * @param acc_name Username of the User
     * @param acc_password Password of the User
     * @param status Booking status of the User
     * @return 0 if successful
     * @return -1 if not successful
     */
    int writeToUsers(const std::string &acc_name, const std::string &acc_password, const std::string &status);

    /**
     * @brief Function to add new Business entry to the businesses table
     * @param acc_name Username of the Business
     * @param acc_password Password of the Business
     * @param venue Venue associated with the Business
     * @return 0 if successful
     * @return -1 if not successful
     */
    int writeToBusinesses(const std::string &acc_name, const std::string &acc_password, const std::string &venue);

    /**
     * @brief Function that gets every entry of the users table
     * @return Returns vector containing every User entry from the users table, each stored in a User object
     */
    std::vector<User> readUsers();

    /**
     * @brief Function that gets every entry of the businesses table
     * @return Returns vector containing every Business entry from the businesses table, each stored in a Business object
     */
    std::vector<Business> readBusinesses();

    /**
     * @brief Function that gets every entry of the venues table
     * @return Returns vector containing every venue entry from the venues table, each stored in a VenueLog object
     */
    std::vector<VenueLog> readVenues();

    /**
     * @brief Function that gets every booking for the provided venue
     * @param venueName Name of the venue
     * @return Returns vector containing every booking entry from the booking table for the provided venue, each stored in a BookingLog object
     */
    std::vector<BookingLog> readBookings(const std::string& venueName);
};
#endif
