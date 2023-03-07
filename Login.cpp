#include "Login.h"
#include "Call_CreateAccount.h"
#include "Call_SelectLocation.h"
#include "Call_BusinessView.h"
#include "User.h"
#include "Logger.h"

const Login* Login::_instance = NULL;

//Creates the instance of the view 
const Login& Login::instance()
{
    if (_instance == NULL) {
        _instance = new Login();
    }
    return*_instance;
}

//The constructor for all the views is mainly responsible for initializing all the QtWidgets
//and assigning the buttons with functions to either connect with the database and/or create
//the next view
Login::Login()
{
    login_window = new QWidget;
    login_window->show();
    login_window->resize(350, 200);
    login_window->setWindowTitle(QApplication::translate("toplevel", "Login Screen"));

    username_input = new QLineEdit(login_window);
    password_input = new QLineEdit(login_window);
    password_input->setEchoMode(QLineEdit::Password);

    login_button = new QPushButton("Login as a user", login_window);
    blogin_button = new QPushButton("Login for a business");
    create_account_button = new QPushButton("Create Account", login_window);

    layout = new QFormLayout(login_window);
    layout->addRow("Username: ", username_input);
    layout->addRow("Password: ", password_input);
    layout->addRow(login_button);
    layout->addRow(blogin_button);
    layout->addRow("New to VenuesRus?", create_account_button);

    //This button will verify the user's loging and allow them into the program is valid, if not an 
    //error message is displayed for them
    QObject::connect(login_button, &QPushButton::pressed, [=]() {

        std::string username = username_input->text().QString::toStdString();
        std::string password = password_input->text().QString::toStdString();
        
        if (User::verifyCredentials(username, password) == 0) {
            Call_SelectLocation new_window(Login::_instance);
            new_window.execute();
            login_window->hide();
        } else {
            QLabel *error_message = new QLabel();
            error_message->setText("Invalid Credentails. Please try again.");
            layout->addRow(error_message);
            username_input->clear();
            password_input->clear();
        }
        
    });

    //This button is for business exclusively to login with and will allow them to see 
    //the business aspect of them program if the login in valid
    QObject::connect(blogin_button, &QPushButton::pressed, [=]() {

        std::string username = username_input->text().QString::toStdString();
        std::string password = password_input->text().QString::toStdString();

        if (Business::verifyCredentials(username, password) == 0) {

            Logger log("database");
            std::vector business_vector = log.readBusinesses();

            for (int i = 0; i < business_vector.size(); i++) {
                if (username == business_vector.at(i).getUsername()) {
                    Call_BusinessView new_window(Login::_instance, business_vector.at(i).getBookings());
                    new_window.execute();
                    login_window->hide();
                    break;
                }
            }
        } else {
            QLabel *error_message = new QLabel();
            error_message->setText("Invalid Credentails. Please try again.");
            layout->addRow(error_message);
            username_input->clear();
            password_input->clear();
        }
        

    });

    QObject::connect(create_account_button, &QPushButton::pressed, [=]() {
        Call_CreateAccount new_account(Login::_instance);
        new_account.execute();
    });

}

const CreateAccount& Login::call_CreateAccount()
{
    return CreateAccount::instance();
}

const SelectLocation& Login::call_SelectLocation() 
{
    return SelectLocation::instance();
}

const BusinessView& Login::call_BusinessView(std::vector<BookingLog> b)
{
    return BusinessView::instance(b);
}

Login::~Login()
{
    delete layout;
    delete create_account_button;
    delete login_button;
    delete password_input;
    delete username_input;
    delete login_window;
}
