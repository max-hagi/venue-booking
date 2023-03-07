#include "MoreDetails.h"
#include "Call_BookingView.h"

const MoreDetails* MoreDetails::_instance = NULL;

const MoreDetails& MoreDetails::instance(std::string name, std::string location, int availability, float price, std::string description, int rating)
{
    if (_instance == NULL) {
        _instance = new MoreDetails(name, location, availability, price, description, rating);
    } else {
        /**
         * Because this uses the singleton pattern, the block of code below is for changing
         * the information displayed if a user cancels one venue and wants to see a different one
        */
        std::string text = "Venue Name: " + name + "\n";
        text += "Rating (Out of 5): " + std::to_string(rating) + "\n";
        text += "Location: " + location + "\n";
        text += "Number of spots left: " + std::to_string(availability) + "\n";
        std::stringstream stream;
        stream << std::fixed << std::setprecision(2) << price;
        text += "Fee per person: $" + stream.str() + "\n";
        text += "**********************\n";
        text += description;

        QString qtext = QString::fromStdString(text);

        _instance->panel->setText(qtext);
        _instance->details_window->show();
    }

    return *_instance;
}

MoreDetails::MoreDetails(std::string name, std::string location, int availability, float price, std::string description, int rating)
{
    details_window = new QWidget;
    details_window->show();
    details_window->resize(300, 400);
    details_window->setMaximumWidth(300);
    details_window->setWindowTitle(QApplication::translate("toplevel", "More Details View"));

    std::string text = "Venue Name: " + name + "\n";
    text += "Rating (Out of 5): " + std::to_string(rating) + "\n";
    text += "Location: " + location + "\n";
    text += "Number of spots left: " + std::to_string(availability) + "\n";
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << price;
    text += "Fee per person: $" + stream.str() + "\n";
    text += "**********************\n";
    text += description;

    QString qtext = QString::fromStdString(text);

    panel = new QLabel(details_window);
    panel->show();
    panel->resize(300, 400);
    panel->setMaximumWidth(300);
    panel->setWordWrap(true);
    panel->setFrameStyle(QFrame::Box);
    panel->setLineWidth(1);
    panel->setText(qtext);

    book_now = new QPushButton("Book Now", details_window);
    cancel = new QPushButton("Cancel", details_window);

    //This will call the booking view and pass the name (for writing to the database) and price
    //the calculate the total cost in the next view
    QObject::connect(book_now, &QPushButton::pressed, [=]() {
        Call_BookingView bView(MoreDetails::_instance, name , price);
        bView.execute();
        details_window->hide();
    });

    //This button allows the user to go back to the venue selection in case they do not like 
    //what they see about a certain venue
    QObject::connect(cancel, &QPushButton::pressed, [=]() {
        details_window->hide();
    });

    layout = new QFormLayout(details_window);
    layout->addWidget(panel);
    layout->addWidget(book_now);
    layout->addWidget(cancel);
}

const BookingView& MoreDetails::call_BookingView(std::string name, float price)
{
    return BookingView::instance(name, price);
}

MoreDetails::~MoreDetails()
{
    delete book_now;
    delete layout;
    delete details_window;
}
