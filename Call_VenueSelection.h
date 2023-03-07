/**
 * @author Benjamin Oliveria
 * @brief Class that displays the VenueSelection view
 * @file Call_VenueSelection.h
 * **/

#ifndef CALL_VENUESELECTION
#define CALL_VENUESELECTION

#include <iostream>
#include "SelectLocation.h"
#include "Command.h"


class Call_VenueSelection : public Command
{

private:
    /**
     * @var Refernce to the SelectLocation view
     */
    const SelectLocation* _selectLocation;

    /**
     * @var Venue location
     */
    std::string _vlocation;
    
public:
    /**
     * @brief Passes all the necessary information for the VenueSelection view to be created
     * @param location Reference to SelectLocation
     * @param vlocation Venue location
     */
    Call_VenueSelection(const SelectLocation* location, std::string vlocation) {
        _selectLocation = location;
        _vlocation = vlocation;
    }

    /**
     * @brief Function that calls VenueSelection using the command design patter
     */
    void execute(){
        this->_selectLocation->call_VenueSelection(_vlocation);
    }
};

#endif