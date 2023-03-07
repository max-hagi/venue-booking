/**
 * @author Benjamin Oliveria
 * @brief Class that displays the CreateAccount view
 * @file Call_CreateAccount.h
 * **/

#ifndef CALL_CREATEACCOUNT
#define CALL_CREATEACCOUNT

#include "Login.h"
#include "Command.h"

class Call_CreateAccount : public Command
{
private:
    /**
     * Pointer to the Login instance
     */
    const Login* _login;
    
public:
    /**
     * @brief Passes all the necessary information for the CreateAccount view to be created
     * @param  Reference to the login instance
     */
    Call_CreateAccount(const Login* login) : _login(login) {}

    /**
     * @brief Function that calls CreateAccount using the command design patter
     */
    void execute() {
        this->_login->call_CreateAccount();
    }
};
#endif