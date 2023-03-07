
#include "ConfirmView.h"
#include "Logger.h"


const ConfirmView* ConfirmView::_instance = NULL;

const ConfirmView& ConfirmView::instance(int num_ppl, float cost, std::string email, std::string date, std::string time, std::string vName)
{
    if (_instance == NULL) {
        _instance = new ConfirmView(num_ppl, cost, email, date, time, vName);
    }

    /*
     This block of code is here to change and redisplay this instance if the user chooses to change
     any of the booking information
    */
    _instance->_num_people->setText(QString::number(num_ppl));
    _instance->_total_cost->setText(QString::number(cost));
    _instance->_email->setText(QString::fromStdString(email));
    _instance->_date->setText(QString::fromStdString(date));
    _instance->_time->setText(QString::fromStdString(time));
    _instance->confirmation_view->show();

    return *_instance;
}

ConfirmView::ConfirmView(int num_ppl, float cost, std::string email, std::string date, std::string time, std::string vName)
{
    confirmed = false;

    confirmation_view = new QWidget;
    confirmation_view->show();
    confirmation_view->resize(250, 250);
    confirmation_view->setWindowTitle(QApplication::translate("toplevel", "Confirmation View"));

    _num_people = new QLabel(confirmation_view);
    _num_people->setText(QString::number(num_ppl));

    _total_cost = new QLabel(confirmation_view);
    _total_cost->setText(QString::number(cost));

    _email = new QLabel(confirmation_view);
    _email->setText(QString::fromStdString(email));

    _date = new QLabel(confirmation_view);
    _date->setText(QString::fromStdString(date));

    _time = new QLabel(confirmation_view);
    _time->setText(QString::fromStdString(time));

    cancel = new QPushButton("Cancel/Edit", confirmation_view);
    confirm = new QPushButton("Confirm", confirmation_view);

    layout = new QFormLayout(confirmation_view);
    layout->addRow("Number of people: ", _num_people);
    layout->addRow("Total cost: $", _total_cost);
    layout->addRow("Your email: ", _email);
    layout->addRow("Date chosen: ", _date);
    layout->addRow("Time chosen: ", _time);
    layout->addRow(cancel);
    layout->addRow(confirm);

    //This button allows the user to go back to the booking view to make any changes if necessary
    QObject::connect(cancel, &QPushButton::pressed, [=]() {
        confirmation_view->hide();
    });

    //This button will confirm the booking and write it to the database as well as display a message for the user
    //that the booking was confirmed
    QObject::connect(confirm, &QPushButton::pressed, [=]() {

        if (!confirmed) {
            Logger log("database");
            log.writeToBookings(date, time, num_ppl, email, cost, vName);
            QLabel *tmp = new QLabel(confirmation_view);
            tmp->setText(QString("Your reservation has been confirmed! You may make another one once this one has finished."));
            QPushButton *terminate = new QPushButton("End Program", confirmation_view);
            QObject::connect(terminate, &QPushButton::pressed, [=]() {
                delete _instance;
            });
            layout->removeWidget(cancel);
            layout->removeWidget(confirm);
            delete cancel;
            delete confirm;
            layout->addRow(tmp);
            layout->addRow(terminate);
            confirmed = true;
        }


    });
}

ConfirmView::~ConfirmView()
{
}