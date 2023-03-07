/**
 * @author Maxime Savehilaghi
 * @brief Class that contains the information for a venue
 * @file VenueLog.h
 * @file VenueLog.cpp
 * **/

#ifndef GROUP26_VENUELOG_H
#define GROUP26_VENUELOG_H

#include "headers.h"

class VenueLog {
private:
    /**
     * @var Name of the venue
     */
    std::string name;

    /**
     * @var City where venue is located
     */
    std::string location;

    /**
     * @var Capacity of venue
     */
    int availability;

    /**
     * @var Price per person for the venue
     */
    float price;

    /**
     * @var Description of the venue
     */
    std::string description;

    /**
     * @var Rating of the venue (out of 5)
     */
    int rating;

public:
    /**
     * @brief Constructor for a VenueLog object
     * @param name Name of the venue
     * @param location City where the venue is located
     * @param availability Capacity of the venue
     * @param price Price of the venue (per person)
     * @param description Description of the venue
     * @param rating Rating of the venue (out of 5)
     */
    VenueLog(std::string name, std::string location, int availability, float price, std::string description, int rating);

    /**
     * @brief Function that gets the name of the venue
     * @return Returns the name of the venue
     */
    std::string getName();

    /**
     * @brief Function that gets the city where the venue is located
     * @return Returns the city where the venue is located
     */
    std::string getLocation();

    /**
     * @brief Function that gets the capacity of the venue
     * @return Returns the capacity of the venue
     */
    int getAvailability();

    /**
     * @brief Function that gets the price to book the venue (per person)
     * @return Price to book the venue (per person)
     */
    float getPrice();

    /**
     * @brief Function that gets the description of the venue
     * @return Description of the venue
     */
    std::string getDescription();

    /**
     * @brief Function that gets the rating of the venue (out of 5)
     * @return Rating of the venue (out of 5)
     */
    int getRating();
};
#endif
