/**
 * @author Benjamin Oliveria
 * @brief Class that displays the BookingView view
 * @file Call_BookingView.h
 * **/

#ifndef CALL_BOOKINGVIEW
#define CALL_BOOKINGVIEW

#include "MoreDetails.h"
#include "Command.h"

class Call_BookingView : public Command
{
private:
    /**
     * @var Pointer to the object that contains the details of the venue
     */
    const MoreDetails* _details;

    /**
     * @var Name of the venue
     */
    std::string _name;

    /**
     * @var Cost of the venue
     */
    float _price;
    
public:
    /**
     * @brief Function that passes the necessary information to the BookingView constructor
     * @param details Details of the venue being booked
     * @param name Name of the venue being booked
     * @param price Price for one person
     */
    Call_BookingView(const MoreDetails* details, std::string name, float price){
        _details = details;
        _name = name;
        _price = price;
    }

    /**
     * @brief Function that calls the BookingView using the command design patter
     */
    void execute(){
        this->_details->call_BookingView(_name, _price);
    }
};
#endif