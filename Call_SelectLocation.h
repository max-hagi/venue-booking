/**
 * @author Benjamin Oliveria
 * @brief Class that displays the SelectLocation view
 * @file Call_SelectLocation.h
 * **/

#ifndef CALL_LOCATION
#define CALL_LOCATION

#include "Login.h"
#include "Command.h"


class Call_SelectLocation : public Command
{
private:
    /**
     * @brief Reference to the Login instance
     */
    const Login* _login;

public:
    /**
     * @brief Passes all the necessary information for the SelectLocation view to be created
     * @param login Reference to the Login instance
     */
    Call_SelectLocation(const Login* login) : _login(login){}

    /**
     * @brief Function that calls SelectLocation using the command design patter
     */
    void execute()
    {
        this->_login->call_SelectLocation();
    }
};

#endif