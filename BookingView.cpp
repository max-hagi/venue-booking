#include "BookingView.h"
#include "ConfirmView.h"
#include "Call_ConfirmView.h"

const BookingView* BookingView::_instance = NULL;

const BookingView& BookingView::instance(std::string name, float price)
{
    if (_instance == NULL) {
        _instance = new BookingView(name, price);
    }
    return *_instance;
}

BookingView::BookingView(std::string name, float price)
{
    num_people = 1;
    total_cost = 0;
    venue_price = price;

    booking_view = new QWidget;
    booking_view->show();
    booking_view->resize(450, 450);
    booking_view->setWindowTitle(QApplication::translate("toplevel", "Booking View"));

    num_of_people = new QLabel;
    num_of_people->setText(QString::number(num_people));

    total_cost = new QLabel;
    cost = num_people * venue_price;
    total_cost->setText(QString::number(cost));

    increment = new QPushButton("+");
    decrement = new QPushButton("-");

    //Will increase the number of people for the booking by one and changes the cost at the same time
    QObject::connect(increment, &QPushButton::pressed, [=]() {
        num_people++;
        num_of_people->setText(QString::number(num_people));

        cost = num_people * venue_price;
        total_cost->setText(QString::number(cost));
    });

    //Will decrease the number of people for the booking by one and changes the cost at the same time
    QObject::connect(decrement, &QPushButton::pressed, [=]() {

        if (num_people > 1) {
            num_people--;
            num_of_people->setText(QString::number(num_people));
        }

        cost = num_people * venue_price;
        total_cost->setText(QString::number(cost));
    });

    email_input = new QLineEdit(booking_view);

    calendar = new QCalendarWidget(booking_view);
    calendar->setGridVisible(true);
    calendar->resize(150, 150);

    dateEdit = new QDateTimeEdit(booking_view);
    dateEdit->setDisplayFormat("h:m:s ap");
    dateEdit->setTime(QTime(8, 00, 00, 0));

    go_to_confirm = new QPushButton("View Summary", booking_view);

    //The button retrieves and formats (to string mainly) the information needed for the confirmation screen
    //to dispay a summary of the person's booking
    QObject::connect(go_to_confirm, &QPushButton::pressed, [=]() {
        std::string e = email_input->text().QString::toStdString();
        std::string sendDate = calendar->selectedDate().toString("dd/MM/yy").QString::toStdString();
        std::string sendTime = dateEdit->time().toString().QString::toStdString();
        Call_confirmation final(BookingView::_instance, num_people, cost, e, sendDate, sendTime, name);
        final.execute();
    });

    layout = new QFormLayout(booking_view);
    layout->addRow("Number of people: ", num_of_people);
    layout->addRow("Add people", increment);
    layout->addRow("Remove people", decrement);
    layout->addRow("Total cost: $", total_cost);
    layout->addRow("Enter your email: ", email_input);
    layout->addRow("Pick a day", calendar);
    layout->addRow("Pick a time", dateEdit);
    layout->addRow(go_to_confirm);
}

void BookingView::changePrice(float number)
{
    venue_price = number;
}

const ConfirmView& BookingView::call_confirmation(int ppl, float totalCost, std::string email, std::string date, std::string time, std::string vName)
{
    return ConfirmView::instance(ppl, totalCost, email, date, time, vName);
}

BookingView::~BookingView()
{
}

