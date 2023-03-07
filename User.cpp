#include "User.h"
#include "Logger.h"

User::User(std::string username, std::string password, std::string status) {
    this->username = std::move(username);
    this->password = std::move(password);
    this->status = std::move(status);
}

std::string User::getUsername() {
    return username;
}

std::string User::getPassword() {
    return password;
}

std::string User::getStatus() {
    return status;
}

//Returns -1 on fail, 0 on success
int User::verifyCredentials(const std::string& name, const std::string& pass) {
    Logger log("database");
    std::vector<User> users = log.readUsers();

    for (auto &user: users) {
        if (user.getUsername() == name && user.getPassword() == pass) {
            return 0;
        }
    }
    return -1;
}

int User::createAccount(const std::string &name, const std::string &password) {
    Logger log("database");
    return log.writeToUsers(name, password, "-1");
}

