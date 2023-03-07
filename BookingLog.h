/**
 * @author Maxime Savehilaghi
 * @brief Container that holds all the information associated with a booking
 * @file BookingLog.h
 * @file BookingLog.cpp
 */

#ifndef GROUP26_BOOKINGLOG_H
#define GROUP26_BOOKINGLOG_H

#include "headers.h"

class BookingLog {
private:
    /**
     * @var Date of the booking
     */
    std::string date;

    /**
     * @var Time of the booking
     */
    std::string time;

    /**
     * @var Number of people the booking is for
     */
    int number;

    /**
     * @var Email of the person that made the booking
     */
    std::string email;

    /**
     * @var Total price of the booking
     */
    float price;

public:
    /**
     * Constructor for BookingLog object
     * @param date Date of the booking
     * @param time Time of the booking
     * @param number Number of people being booked for
     * @param email Contact email address
     * @param price Total price of the booking
     */
    BookingLog(std::string date, std::string time, int number, std::string email, float price);

    /**
     * Function that gets the date of the booking
     * @return Date of the booking
     */
    std::string getDate();

    /**
     * Function that gets the time of the booking
     * @return Time of the booking
     */
    std::string getTime();

    /**
     * Function that gets the number of people for the booking
     * @return Number of people being booked for
     */
    int getNumber();

    /**
     * Function that gets the email of the person who made the booking
     * @return Email of the individual booking the reservation
     */
    std::string getEmail();

    /**
     * Function that gets the total cost of the booking
     * @return Total price of the booking
     */
    float getPrice();
};


#endif
