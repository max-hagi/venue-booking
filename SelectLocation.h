/**
 * @author Benjamin Oliveria
 * @brief This class will be responsible for showing and allowing the user to pick the location in which they are going to be looking for venues
 * @file SelectLocation.h
 * @file SelectLocation.cpp
 * **/

#ifndef SELECT_LOCATION
#define SELECT_LOCATION

#include <QtWidgets>
#include <QObject>
#include "VenueSelection.h"


class SelectLocation {

private:
    /**
     * @var Pointer to the instance of the SelectLocation class
     */
    static const SelectLocation* _instance;

    /**
     * @var Pointer to the
     */
    QWidget *location_window;

    /**
     * @var Pointer to the dropdown to select the location
     */
    QComboBox *dropdown;

    /**
     * @var Organizes the aspects of the GUI neatly
     */
    QFormLayout *layout;
    
protected:
    /**
     * enerates the view by initializing all the QT widgets and assigns the correct functions to their respective buttons
     */
    SelectLocation();

public:
    /**
     * @brief Destructor for the SelectLocation view
     */
    virtual ~SelectLocation();

    /**
     * @brief Function that gets the instance of the SelectLocation class
     * @return Returns the instance of the SelectLocation class
     */
    static const SelectLocation& instance();

    /**
     * @brief Function that get the instance of the VenueSelection class based on the chosen location
     * @param location Selected location
     * @return Returns instance of the VenueSelection class
     */
    static const VenueSelection& call_VenueSelection(std::string location);
};

#endif