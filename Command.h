/**
 * @author Benjamin Oliveria
 * @brief Class that implements the command design pattern
 * @file Command.h
 * **/

#ifndef COMMAND
#define COMMAND

class Command
{
    public:
        virtual void execute() = 0;
        
};
#endif