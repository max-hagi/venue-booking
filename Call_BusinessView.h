/**
 * @author Benjamin Oliveria
 * @brief Class that displays the BusinessView
 * @file Call_BusinessView.h
 * **/

#ifndef CALL_BUSINESS
#define CALL_BUSINESS

#include "Login.h"
#include "Command.h"

class Call_BusinessView : public Command
{

private:
    /**
     * @var Pointer the Login instance
     */
    const Login* _login;


    /**
     * @var Vector containing all the bookings for the given venue
     */
    std::vector<BookingLog> booking_reference;

public:
    /**
     * @brief Function that passes the necessary information to the BusinessView constructor
     * @param login Reference to the Login instance
     * @param b Reference to the bookings for a venue
     */
    Call_BusinessView(const Login* login, std::vector<BookingLog> b){
        _login = login;
        booking_reference = b;
    }

    /**
     * @brief Function that calls the BusinessView using the command design patter
     */
    void execute() {
        this->_login->call_BusinessView(booking_reference);
    }
};

#endif