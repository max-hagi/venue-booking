#include "BookingLog.h"

BookingLog::BookingLog(std::string date, std::string time, int number, std::string email, float price) {
    this->date = date;
    this->time = time;
    this->email = email;
    this->number = number;
    this->price = price;
}

std::string BookingLog::getDate() {
    return this->date;
}

std::string BookingLog::getEmail() {
    return this->email;
}

float BookingLog::getPrice() {
    return this->price;
}

int BookingLog::getNumber() {
    return this->number;
}


std::string BookingLog::getTime() {
    return this->time;
}
