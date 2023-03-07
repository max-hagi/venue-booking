/**
 * @author Benjamin Oliveria
 * @brief Driver class that executes LoginView when the program is launched
 * @file main.cpp
 * **/

#include "Login.h"
#include "CreateAccount.h"
#include "SelectLocation.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    Login start = Login::instance();
    app.exec();
}