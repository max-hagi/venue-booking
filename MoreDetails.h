/**
 * @author Benjamin Oliveria
 * @brief Window that shows more information for a selected Venue
 * @file MoreDetails.h
 * @file MoreDetails.cpp
 * **/

#ifndef MORE_DETAILS
#define MORE_DETAILS

#include <QtWidgets>
#include <QObject>
#include <iostream>
#include <VenueLog.h>
#include <sstream>
#include "BookingView.h"

/**
 * This class simply takes the venue the user is interested in seeing more details for and will 
 * display all of it's information to the screen as well as provide a button to make a booking for that 
 * venue
*/
class MoreDetails
{

private:
    /**
     * @var Pointer to the instance of the MoreDetails class
     */
    static const MoreDetails* _instance;

    /**
     * @var Pointer to the MoreDetails window
     */
    QWidget *details_window;

    /**
     * @var Pointer to the button to book the venue
     */
    QPushButton *book_now;

    /**
     * @var Pointer to the button to leave the MoreDetails view
     */
    QPushButton *cancel;

    /**
     * @var Pointer to the panel that holds the information for the venue in the MoreDetails view
     */
    QLabel *panel;

    /**
     * @var Organizes the aspects of the GUI neatly
     */
    QFormLayout *layout;
    
protected:
    /**
     * @brief Generates the view by initializing all the QT widgets, assigns the correct functions to their respective buttons and provides more information for the selected venue
     * @param name Venue name
     * @param location Venue location
     * @param availability Venue capacity
     * @param price Venue price (per person)
     * @param description Venue description
     * @param rating Venue rating (out of 5)
     */
    MoreDetails(std::string name, std::string location, int availability, float price, std::string description, int rating);

public:
    /**
     * @brief Function that get the instance of the MoreDetails class
    * @param name Venue name
     * @param location Venue location
     * @param availability Venue capacity
     * @param price Venue price (per person)
     * @param description Venue description
     * @param rating Venue rating (out of 5)
     * @return Returns instance of the MoreDetails class
     */
    static const MoreDetails& instance(std::string name, std::string location, int availability, float price, std::string description, int rating);

    /**
     * @brief Function that gets the instance of the BookingView class
     * @param name Venue name
     * @param price Venue price (per person)
     * @return Returns instance of the BookingView class
     */
    static const BookingView& call_BookingView(std::string name, float price);

    /**
     * @brief Destructor for the MoreDetails view
     */
    virtual ~MoreDetails();
};

#endif