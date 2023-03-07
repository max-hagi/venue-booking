/**
 * @author Benjamin Oliveria
 * @brief Impleme
 * @file BookingLog.cpp
 * **/

#ifndef BUSINESS_VIEW
#define BUSINESS_VIEW

#include <QtWidgets>
#include <QObject>
#include <sstream>
#include "BookingLog.h"

class BusinessView
{
    private:
    /**
     * @var Pointer to the instance of the BusinessView class
     */
    static const BusinessView* _instance;

    /**
     * @var Pointer to the Business window
     */
    QWidget *business_window;

    /**
     * @var Pointer to the button that increments the number of current clients (for walk-ins)
     */
    QPushButton *increment;

    /**
     * @var Pointer to the button that decrements the number of current clients (for walk-ins)
     */
    QPushButton *decrement;

    /**
     * @var Pointer to the label that displays the number of current clients
     */
    QLabel *availability_count;

    /**
     * @var Organizes aspects of the GUI neatly
     */
    QFormLayout *layout;

    /**
     * @var Vector containing all current bookings for the venue
     */
    std::vector<BookingLog> bookings;

    /**
     * @var Number of current clients
     */
    int availability;

protected:
    /**
     * @brief Generates the view by initializing all the QT widgets, assigns the correct functions to their respective buttons and displays current bookings
     * @param _reference Vector containing all the current bookings
     */
    BusinessView(std::vector<BookingLog> _reference);
    

public:
    /**
     * @brief Destructor for the BusinessView view
     */
    virtual ~BusinessView();

    /**
     * @brief Function that gets the instance of the BusinessView class
     * @param reference Vector containing all the curent bookings
     * @return Returns the instance of the BusinessView class
     */
    static const BusinessView& instance(std::vector<BookingLog> reference);
};

#endif