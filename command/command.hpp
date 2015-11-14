#ifndef _COMMAND_HPP_
#define _COMMAND_HPP_

#include <string>

class Command {
public:
    Command() {}
    virtual ~Command() {}
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual std::string getName() = 0;
};

class NoCommand : public Command {
public:
    NoCommand() {}
    virtual ~NoCommand() {}
    void execute() {}
    void undo() {}
    std::string getName() {
        return "NoCommand";
    }
};

#endif // _COMMAND_HPP_
