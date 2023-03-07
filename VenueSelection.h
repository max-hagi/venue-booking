/**
 * @author Benjamin Oliveria
 * @brief Class that allows users to select a venue based on their location
 * @file VenueSelection.h
 * @file VenueSelection.cpp
 * **/

#ifndef VENUE_SELECTION
#define VENUE_SELECTION

#include <QtWidgets>
#include <QObject>
#include <iostream>
#include "MoreDetails.h"


class VenueSelection
{

private:
    /**
     * @var Pointer to the instance of VenueSelection class
     */
    static const VenueSelection* _instance;

    /**
     * @var Pointer to the window that displays the venues
     */
    QWidget *venues_window;

    /**
     * @var Organizes the aspects of the GUI neatly
     */
    QGridLayout *layout;

    /**
     * @var Location selected by the user
     */
    std::string vlocation;

protected:
    /**
     * @brief Generates the view by initializing all the QT widgets, assigns the correct functions to their respective buttons and presents relevant venues for the selected location
     * @param location Location of venues to show
     */
    VenueSelection(std::string location);
    
public:
    /**
     * @brief Function that gets the instance of the VenueSelection class
     * @param location Location of the venues to be displayed
     * @return Returns instance of the VenueSelection class
     */
    static const VenueSelection& instance(std::string location);

    /**
     * @brief Function the get the instance of the MoreDetails, that gives more information of the selected venue
     * @param name Venue name
     * @param location City in which venue is located
     * @param availability Capacity
     * @param price Price (per person)
     * @param description Description
     * @param rating Rating (out of 5)
     * @return Instance of the MoreDetails class for the selected Venue
     */
    static const MoreDetails& call_MoreDetails(std::string name, std::string location, int availability, float price, std::string description, int rating);

    /**
     * @brief Destructor for the VenueSelection view
     */
    virtual ~VenueSelection();
};



#endif