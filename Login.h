/**
 * @author Benjamin Oliveria
 * @brief Login window for the GUI
 * @file Login.h
 * @file Login.cpp
 */

#ifndef LOGIN
#define LOGIN

#include <QtWidgets>
#include <QObject>
#include <iostream>
#include "CreateAccount.h"
#include "SelectLocation.h"
#include "BusinessView.h"
#include "Business.h"

class Login
{

private:
        /**
         * @var Pointer to the instance of the Login class
         */
        static const Login* _instance;

        /**
         * @var Pointer to the login window
         */
        QWidget *login_window;

        /**
         * @var Pointer to the text field for the username
         */
        QLineEdit *username_input;

        /**
         * @var Pointer to the text field for the password
         */
        QLineEdit *password_input;

        /**
         * @var Pointer to the button for the user to attempt to login
         */
        QPushButton *login_button;

        /**
         * @var Pointer to the button for the business to attempt to login
         */
        QPushButton *blogin_button;

        /**
         * @var Pointer to the button that will call the view to create an account
         */
        QPushButton *create_account_button;

        /**
         * @var Organizes the aspects of the GUI neatly
         */
        QFormLayout *layout;
    
protected:
    /**
     * @brief Generates the view by initializing all the QT widgets and assigns the correct functions to their respective buttons
     */
     Login();

public:
    /**
     * @brief Destructor for the Login view
     */
    virtual ~Login();

    /**
     * @brief Function the get the instance of the login class
     * @return Returns the instance of the Login class
     */
    static const Login& instance();

    /**
     * @brief Function that gets the instance of the CreateAccount class
     * @return Returns the instance of the CreateAccount class
     */
    static const CreateAccount& call_CreateAccount();

    /**
     * @brief Function that gets the instance of the SelectLocation class
     * @return Returns the instance of the SelectLocation class
     */
    static const SelectLocation& call_SelectLocation();

    /**
     * @param Vector containing all the bookings for the venue
     * @brief Function that gets the instance of the BusinessView class
     * @return Returns the instance of the BusinessView class
     */
    static const BusinessView& call_BusinessView(std::vector<BookingLog> reference);
};
#endif