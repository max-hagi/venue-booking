/**
 * @author Benjamin Oliveria
 * @brief Window for the account creation window
 * @file CreateAccount.h
 * @file CreateAccount.cpp
 * **/

#ifndef CREATE_ACCOUNT
#define CREATE_ACCOUNT

#include <QtWidgets>
#include <QObject>
#include <iostream>


class CreateAccount
{

private:
    /**
     * @var Pointer to the instance of the CreateAccount class
     */
    static const CreateAccount* _instance;

    /**
     * @var Pointer to the account creation window
     */
    QWidget *create_account_window;

    /**
     * @var Pointer to the input field for the username
     */
    QLineEdit *username_input;

    /**
     * @var Pointer to the input field for the password
     */
    QLineEdit *password_input;

    /**
     * @var Pointer to the button to confirm the account creation
     */
    QPushButton *create_button;

    /**
     * @var Pointer to the button to cancel account creation
     */
    QPushButton *cancel_button;

    /**
     * @var Organizes aspects of the GUI neatly
     */
    QFormLayout *layout;
    
protected:
    /**
     * @brief Generates the view by initializing all the QT widgets and assigns the correct functions to their respective buttons
     */
    CreateAccount();
    
public:
    /**
     * @brief Destructor for the CreateAccount view
     */
    virtual ~CreateAccount();

    /**
     * @brief Function the gets the instance of the CreateAccount class
     * @return Returns the instance of the CreateAccount class
     */
    static const CreateAccount& instance();

};

#endif