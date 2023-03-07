#include "CreateAccount.h"
#include "Call_SelectLocation.h"
#include "Logger.h"
#include "User.h"

const CreateAccount* CreateAccount::_instance = NULL;

const CreateAccount& CreateAccount::instance()
{
    if (_instance == NULL) {
        _instance = new CreateAccount();
    }
    _instance->create_account_window->show();
    return *_instance;
}

CreateAccount::CreateAccount()
{
    create_account_window = new QWidget;
    create_account_window->show();
    create_account_window->resize(350, 200);
    create_account_window->setWindowTitle(QApplication::translate("toplevel", "Create an Account"));

    username_input = new QLineEdit(create_account_window);
    password_input = new QLineEdit(create_account_window);
    password_input->setEchoMode(QLineEdit::Password);

    create_button = new QPushButton("Create", create_account_window);
    cancel_button = new QPushButton("Cancel", create_account_window);

    layout = new QFormLayout(create_account_window);
    layout->addRow("Enter a username: ", username_input);
    layout->addRow("Enter a password: ", password_input);
    layout->addRow(create_button);
    layout->addRow(cancel_button);

    //This button will write the users account information that they inputted to the database for
    //later use if the username they selected does not already exist
    QObject::connect(create_button, &QPushButton::pressed, [=]() {

        std::string username = username_input->text().QString::toStdString();
        std::string password = password_input->text().QString::toStdString();

        if (User::createAccount(username, password) == 0) {
            Call_SelectLocation location_screen(&Login::instance());
            location_screen.execute();
        } else {
            QLabel *error_message = new QLabel();
            error_message->setText("That username already exists.");
            layout->addRow(error_message);
            username_input->clear();
            password_input->clear();
        }
        
    });

    //This button is here in case a user chooses to cancel the account creation and will simply show
    //the login window again
    QObject::connect(cancel_button, &QPushButton::pressed, [=]() {
        CreateAccount::create_account_window->hide();
    });
}

CreateAccount::~CreateAccount()
{
    delete layout;
    delete cancel_button;
    delete create_button;
    delete password_input;
    delete username_input;
    delete create_account_window;
}