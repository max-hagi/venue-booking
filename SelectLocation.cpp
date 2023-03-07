#include "SelectLocation.h"
#include "Call_VenueSelection.h"
#include <iostream>

const SelectLocation* SelectLocation::_instance = NULL;

const SelectLocation& SelectLocation::instance()
{
    if (_instance == NULL) {
        _instance = new SelectLocation();
    }
    return *_instance;
}

SelectLocation::SelectLocation()
{
    location_window = new QWidget;
    location_window->show();
    location_window->resize(350, 200);
    location_window->setWindowTitle(QApplication::translate("toplevel", "Select Your Location"));

    dropdown = new QComboBox(location_window);
    dropdown->addItem("Toronto", "Toronto");
    dropdown->addItem("London", "London");
    dropdown->addItem("Waterloo", "Waterloo");

    layout = new QFormLayout(location_window);
    layout->addRow("Select where you live: ", dropdown);

    //This button will be able to call the next view (selecting a venue) the moment the user clicks
    //on the location of interest
    QObject::connect(dropdown, &QComboBox::textActivated, [=]() {
        std::string location_name = dropdown->currentText().QString::toStdString();
        Call_VenueSelection venue_select(SelectLocation::_instance, location_name);
        venue_select.execute();
        location_window->hide();
    });
}

const VenueSelection& SelectLocation::call_VenueSelection(std::string vlocation)
{
    return VenueSelection::instance(vlocation);
}

SelectLocation::~SelectLocation()
{
    delete layout;
    delete dropdown;
    delete location_window;
}