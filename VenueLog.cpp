#include "VenueLog.h"

VenueLog::VenueLog(std::string name, std::string location, int availability, float price, std::string description,
                   int rating) {
    this->name = std::move(name);
    this->location = std::move(location);
    this->availability = availability;
    this->price = price;
    this->description = std::move(description);
    this->rating = rating;
}

std::string VenueLog::getName() {
    return name;
}

std::string VenueLog::getLocation() {
    return location;
}

int VenueLog::getAvailability(){
    return availability;
}

float VenueLog::getPrice() {
    return price;
}

std::string VenueLog::getDescription() {
    return description;
}

int VenueLog::getRating() {
    return rating;
}



