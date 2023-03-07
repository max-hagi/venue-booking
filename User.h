/**
 * @author Maxime Savehilaghi
 * @brief Class that contains all the information for a user
 * @file User.h
 * @file User.cpp
 **/

#ifndef GROUP26_USER_H
#define GROUP26_USER_H

#include "headers.h"


class User {
private:
    /**
     * @var Username of the User
     */
    std::string username;

    /**
     * @var Password of the User
     */
    std::string password;

    /**
     * @var Booking status of the User
     */
    std::string status;
public:
    /**
     * @brief Constructor creates an object that holds the information for a User
     * @param username Login username of the user
     * @param password Login password of the user
     * @param status Booking status of the user, set to -1 if no booking is currently made
     */
    User(std::string username, std::string password, std::string status);

    /**
     * @brief Function that gets the username of the User account
     * @return Username of the User account
     */
    std::string getUsername();

    /**
     * @brief Function that gets the password of the User account
     * @return Password of the User
     */
    std::string getPassword();

    /**
     * @brief Function that gets the status of the user's booking
     * @return The booking string of the user
     * @return -1 if the user has no current booking
     */
    std::string getStatus();

    /**
     * @brief Function that checks if the credentials of the user account are a valid combination
     * @param name Username for user login
     * @param password Password for user login
     * @return 0 if credentials are valid
     * @return -1 if credentials are invalid
     */
    static int verifyCredentials(const std::string& name, const std::string& password);

    /**
     * @brief Function that will add an entry to the user table in the database with the provided credentials
     * @param name Unique username for the new account
     * @param password Password for the new account
     * @return 0 if account was successfully created
     * @return -1 if username is already taken
     */
    static int createAccount(const std::string& name, const std::string& password);

};

#endif