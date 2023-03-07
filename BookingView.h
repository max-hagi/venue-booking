/**
 * @author Benjamin Oliveria
 * @brief Window for users to make bookings
 * @file BookingView.h
 * @file BookingView.cpp
 * **/

#ifndef BOOKING_VIEW
#define BOOKING_VIEW

#include <QtWidgets>
#include <QObject>
#include <iostream>
#include "ConfirmView.h"

/**
 * This class will create an interface that allows a user to edit all the information they want 
 * when creating a booking for a certain venue
*/

class BookingView
{
    private:
    /**
     * @var Pointer to the instance of the BookingView class
     */
    static const BookingView* _instance;

    /**
     * @var Pointer to the BookingView window
     */
    QWidget *booking_view;

   /**
    * @var Pointer to the label that indicates the current number of people being booked for
    */
    QLabel *num_of_people;

    /**
     * @var Pointer the button that increments the number of people being booked for
     */
    QPushButton *increment;

    /**
     * @var Pointer to the button that decrements the number of people being booked for
     */
    QPushButton *decrement;

    /**
     * @var Pointer to the label that shows the total cost of booking
     */
    QLabel *total_cost;

    /**
     * @var Pointer to the input field for the user's email during booking
     */
    QLineEdit *email_input;

    /**
     * @var Pointer to the calendar widget for users to select a booking date
     */
    QCalendarWidget *calendar;

    /**
     * @var Pointer to the widget to select the time
     */
    QDateTimeEdit *dateEdit;

    /**
     * @var Pointer to the button for users to confirm their booking
     */
    QPushButton *go_to_confirm;

    /**
     * @var Organizes the aspects of the GUI neatly
     */
    QFormLayout *layout;

    /**
     * @var Number of people being booked for, based on user input
     */
    int num_people;

    /**
     * @var Cost for booking the venue
     */
    float venue_price;

    /**
     * @var Total cost for making the booking, based on the number of people being booked for
     */
    float cost;

    protected:
    /**
     * @brief Generates the view by initializing all the QT widgets, assigns the correct functions to their respective buttons and displays the booking information
     * @param name Name of the venue that is being booked
     * @param price Price for one booking
     */
    BookingView(std::string name, float price);
    
    public:
    /**
     * @brief Destructor for the BookingView
     */
    virtual ~BookingView();

    /**
     * @brief Function that gets the the instance of the BookingView class
     * @param name Name of the venue that the booking view is being opened for
     * @param price Price of the venue that the booking view is being opened for
     * @return Returns the instance of the BookingView
     */
    static const BookingView& instance(std::string name, float price);

    /**
     * @brief Function that gets the instance of the Confirmation class
     * @return Returns the instance of the Confirmation class
     */
    static const ConfirmView& call_confirmation(int, float, std::string, std::string, std::string, std::string);

    /**
     * @brief Function that changes the current total cost
     * @param number New total cost
     */
    void changePrice(float number);
};

#endif