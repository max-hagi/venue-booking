/**
 * @author Benjamin Oliveria
 * @brief Class that displays the MoreDetails view
 * @file Call_SelectLocation.h
 * **/

#ifndef CALL_MOREDETAILS
#define CALL_MOREDETAILS

#include <iostream>
#include "VenueSelection.h"
#include "Command.h"

class Call_MoreDetails : public Command
{
private:
    /**
     * @var Pointer to VenueSelection instance
     */
    const VenueSelection* _venueSelection;

    /**
     * @var Venue name
     */
    std::string vname;

    /**
     * @var Venue location
     */
    std::string vlocation;

    /**
     * @var Venue capacity
     */
    int vavailability;

    /**
     * @var Venue price
     */
    float vprice;

    /**
     * @var Venue description
     */
    std::string vdescription;

    /**
     * @var Rating (out of 5)
     */
    int vrating;
    
public:
    /**
     * @brief Passes all the necessary information for the MoreDetails view to be created
     * @param venues Reference to VenueSelection
     * @param name Venue name
     * @param location Location of the venue
     * @param availability Venue capacity
     * @param price Venue price (per person)
     * @param description Venue description
     * @param rating Venue rating (out of 5)
     */
    Call_MoreDetails(const VenueSelection* venues, std::string name, std::string location, int availability, float price, std::string description, int rating) {
        _venueSelection = venues;
        vname = name;
        vlocation = location;
        vavailability = availability;
        vprice = price;
        vdescription = description;
        vrating = rating;
    }

    /**
     * @brief Function that calls MoreDetails using the command design patter
     */
    void execute() {
        this->_venueSelection->call_MoreDetails(vname, vlocation, vavailability, vprice, vdescription, vrating);
    }
};
#endif