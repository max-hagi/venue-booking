#include "BusinessView.h"
#include "Logger.h"

const BusinessView* BusinessView::_instance = NULL;

const BusinessView& BusinessView::instance(std::vector<BookingLog> reference)
{
    if (_instance == NULL) {
        _instance = new BusinessView(reference);
    }

    return *_instance;
}

BusinessView::BusinessView(std::vector<BookingLog> reference)
{
    bookings = reference;
    
    business_window = new QWidget;
    business_window->show();
    business_window->resize(600, 400);
    business_window->setWindowTitle(QApplication::translate("toplevel", "Business View"));

    increment = new QPushButton("Add to availability", business_window);
    decrement = new QPushButton("Remove from availablity", business_window);

    availability = bookings.size();

    availability_count = new QLabel(business_window);
    availability_count->setText(QString::number(availability));

    QObject::connect(increment, &QPushButton::pressed, [=]() {

        availability++;
        availability_count->setText(QString::number(availability));

    });

    QObject::connect(decrement, &QPushButton::pressed, [=]() {
        if (availability > bookings.size()) {
            availability--;
            availability_count->setText(QString::number(availability));
        }
    });

    layout = new QFormLayout(business_window);

    for (int i = 0; i < bookings.size(); i++) {
        QLabel *booking_info = new QLabel(business_window);
        BookingLog tmp = bookings.at(i);

        std::string text = "User: " + tmp.getEmail();
        text += " || Booked: " + tmp.getDate() + " at " + tmp.getTime();
        text += " || People attending: " + std::to_string(tmp.getNumber());
        std::stringstream stream;
        stream << std::fixed << std::setprecision(2) << tmp.getPrice();
        text += " || Total cost: $" + stream.str();
        QString qtext = QString::fromStdString(text);

        booking_info->setText(qtext);
        booking_info->setFrameStyle(QFrame::Box);
        booking_info->setLineWidth(1);

        layout->addWidget(booking_info);
    }

    layout->addRow("Availability: ", availability_count);
    layout->addRow(increment);
    layout->addRow(decrement);

}

BusinessView::~BusinessView()
{
    delete layout;
    delete availability_count;
    delete decrement;
    delete increment;
    delete business_window;
}