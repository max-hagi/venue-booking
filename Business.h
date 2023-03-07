/**
 * @author Maxime Savehilaghi
 * @brief Class that contains information about a Business
 * @file Business.h
 * @file Business.cpp
 * **/

#ifndef GROUP26_BUSINESS_H
#define GROUP26_BUSINESS_H

#include "headers.h"
#include "BookingLog.h"

class Business {
private:
     /**
     * @var Username of the business trying to login
     */
    std::string username;

    /**
     * @var Password of the business trying to login
     */
    std::string password;

    /**
     * @var Venue that the business trying to login is associated with
     */
    std::string venue;

public:
    /**
     * @brief Constructor creates an object that holds the information for a Business
     * @param username Login username of the business
     * @param password Login password of the business
     * @param venue Venue that the business account is associated with
     */
    Business(std::string username, std::string password, std::string venue);

    /**
     * @brief Function that gets the login username of the business account
     * @return Username of the business account
     */
    std::string getUsername();

    /**
     * @brief Function that gets the password of the business account
     * @return Password of the business account
     */
    std::string getPassword();

    /**
     * @brief Function that gets the associated venue of a business account
     * @return Venue associated with the business account
     */
    std::string getVenue();

    /**
     * @brief Function that checks if the credentials of the business account are a valid combination
     * @param name Username for business login
     * @param password Password for business login
     * @return 0 if credentials are valid
     * @return -1 if credentials are invalid
     */
    static int verifyCredentials(const std::string& name, const std::string& password);

    /**
     * @brief Function that gets the bookings for the venue associated with the business account
     * @return Vector containing BookingLog objects for every booking for the venue the business is associated with
     */
    std::vector<BookingLog> getBookings();
};


#endif
