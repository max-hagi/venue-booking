/**
 * @author Benjamin Oliveria
 * @brief Window for the confirmation view
 * @file ConfirmationView.h
 * @file ConfirmationView.cpp
 * **/

#ifndef CONFIRM
#define CONFIRM

#include<QtWidgets>
#include<QObject>
#include<iostream>

/**
 * This class simply shows a summary of the user's booking and if they reviewed the info and are 
 * satisfies, they can confirm the booking in which the booking will be written to the database
*/
class ConfirmView {
private:

    static const ConfirmView* _instance;
    /**
     * @var Pointer to the instance of the ConfirmationView class
     */
    QWidget *confirmation_view;

    /**
     * Pointer to the label that displays the number of people for the confirmed booking
     */
    QLabel *_num_people;

    /**
     * Pointer to the label that displays the total cost for the confirmed booking
     */
    QLabel *_total_cost;

    /**
     * @var Pointer to the label that displays the email for the confirmed booking
     */
    QLabel *_email;

    /**
     * @var Pointer to the label that displays the date for the confirmed booking
     */
    QLabel *_date;

    /**
     * @var Pointer to the label that displays the time for the confirmed booking
     */
    QLabel *_time;

    /**
     * @var Pointer for the button that allows users to cancel the current booking
     */
    QPushButton *cancel;

    /**
     * @var Pointer to the button that allows users to confirm their booking
     */
    QPushButton *confirm;

    /**
     * @var Organizes the aspects of the GUI neatly
     */
    QFormLayout *layout;

    /**
     * @var True if the confirmation is finalized
     */
    bool confirmed;
    
protected:
    /**
     * @brief Generates the view by initializing all the QT widgets, assigns the correct functions to their respective buttons and displays the confirmation
     */
    ConfirmView(int, float, std::string, std::string, std::string, std::string);

public:
    /**
     * @brief Destructor for the ConfirmView
     */
    virtual ~ConfirmView();

    /**
     * @brief Function that gets the instance of the ConfirmView class
     * @return Returns the instance of the ConfirmView class
     */
    static const ConfirmView& instance(int, float, std::string, std::string, std::string, std::string);
};


#endif