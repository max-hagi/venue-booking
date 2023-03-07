/**
 * @author Benjamin Oliveria
 * @brief Class that displays ConfirmView
 * @file Call_ConfirmView.h
 * **/

#ifndef CALL_CONFIRMATION;
#define CALL_CONFIRMATION;

#include "BookingView.h"
#include "Command.h"

class Call_confirmation : public Command {


private:
    /**
     * @var Pointer to the BookingView instance
     */
    const BookingView* _booking;

    /**
     * @var Number of people the booking is for
     */
    int _num_ppl;

    /**
     * @var Cost of the booking
     */
    float _cost;

    /**
     * @var Email for the booking
     */
    std::string _email;

   /**
    * @var Date of the booking
    */
    std::string _date;

    /**
     * @var Time of the booking
     */
    std::string _time;

    /**
     * @var Name of the venue booking for
     */
    std::string _vname;
    
public:
    /**
     * @brief Passes all the necessary information for the confirmation view to be created
     * @param booking BookingView instance
     * @param num_ppl Number of people of the booking
     * @param cost Total cost of the booking
     * @param email Email of the booking
     * @param date Date of the booking
     * @param time Time of the booking
     * @param vname Venue name
     */
    Call_confirmation(const BookingView* booking, int num_ppl, float cost, std::string email, std::string date, std::string time, std::string vname) {
        _booking = booking;
        _num_ppl = num_ppl;
        _cost = cost;
        _email = email;
        _date = date;
        _time = time;
        _vname = vname;
    }

    void execute() {
        /**
         * @brief Function that calls the Confirmation View using the command design patter
         */
        this->_booking->call_confirmation(_num_ppl, _cost, _email, _date, _time, _vname);
    }
};

#endif