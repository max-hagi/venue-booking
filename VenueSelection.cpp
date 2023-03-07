#include "VenueSelection.h"
#include "Logger.h"
#include "VenueLog.h"
#include "Call_MoreDetails.h"
#include <iostream>

const VenueSelection* VenueSelection::_instance = NULL;

const VenueSelection& VenueSelection::instance(std::string location)
{
    if (_instance == NULL) {
        _instance = new VenueSelection(location);
    }

    return *_instance;
}

VenueSelection::VenueSelection(std::string location)
{
    vlocation = location;

    venues_window = new QWidget;
    venues_window->show();
    venues_window->resize(400, 400);
    venues_window->setWindowTitle(QApplication::translate("toplevel", "Venue Selection"));

    layout = new QGridLayout(venues_window);

    Logger logger("database");

    std::vector<VenueLog> list_of_venues = logger.readVenues();

    /**
     * After getting the vector containing all the venues in the database, this loop will
     * go through each one and only display the jist of the venue, enough to maybe entice the user
     * to see "more details"
    */
    for (int i = 0; i < list_of_venues.size(); i++) {

        VenueLog currentVenue = list_of_venues.at(i);

        std::string name = currentVenue.getName();
        std::string venue_location = currentVenue.getLocation();

        if (venue_location != vlocation) {
            continue;
        }

        int availability = currentVenue.getAvailability();
        float price = currentVenue.getPrice();
        std::string description = currentVenue.getDescription();
        int rating = currentVenue.getRating();

        std::string text = "Venue Name: " + name + "\nSpots left: " + std::to_string(availability) + "\nRating (Out of 5): " + std::to_string(rating);
        QString qtext = QString::fromStdString(text);

        QPushButton *see_more = new QPushButton(qtext, venues_window);

        //Each venue gets its own button to display its on more details
        QObject::connect(see_more, &QPushButton::pressed, [=]() {
            Call_MoreDetails moreDetails(VenueSelection::_instance, name, venue_location, availability, price, description, rating);
            moreDetails.execute();
        });

        layout->addWidget(see_more, i, 0);

    }
}

const MoreDetails& VenueSelection::call_MoreDetails(std::string name, std::string location, int availability, float price, std::string description, int rating)
{
    return MoreDetails::instance(name, location, availability, price, description, rating);
}

VenueSelection::~VenueSelection()
{
    
}

