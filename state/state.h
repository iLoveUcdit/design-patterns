#ifndef _STATE_H_
#define _STATE_H_

#include "gumball-machine.h"

#include <string>

class State {
public:
    State() {}
    virtual ~State() {}
    virtual void insertQuarter() = 0;
    virtual void ejectQuarter() = 0;
    virtual void turnCrank() = 0;
    virtual void dispense() = 0;
    virtual void refill() = 0;
    virtual std::string toString() = 0;
};

class HasQuarterState : public State {
public:
    HasQuarterState(GumballMachine* gumballMachine);
    virtual ~HasQuarterState();
    void insertQuarter();
    void ejectQuarter();
    void turnCrank();
    void dispense();
    void refill();
    std::string toString();

private:
    GumballMachine* m_gumballMachine;
};

class NoQuarterState : public State {
public:
    NoQuarterState(GumballMachine* gumballMachine);
    virtual ~NoQuarterState();
    void insertQuarter();
    void ejectQuarter();
    void turnCrank();
    void dispense();
    void refill();
    std::string toString();

private:
    GumballMachine* m_gumballMachine;
};

class SoldOutState : public State {
public:
    SoldOutState(GumballMachine* gumballMachine);
    virtual ~SoldOutState();
    void insertQuarter();
    void ejectQuarter();
    void turnCrank();
    void dispense();
    void refill();
    std::string toString();

private:
    GumballMachine* m_gumballMachine;
};

class SoldState : public State {
public:
    SoldState(GumballMachine* gumballMachine);
    virtual ~SoldState();
    void insertQuarter();
    void ejectQuarter();
    void turnCrank();
    void dispense();
    void refill();
    std::string toString();

private:
    GumballMachine* m_gumballMachine;
};


class WinnerState : public State {
public:
    WinnerState(GumballMachine* gumballMachine);
    virtual ~WinnerState();
    void insertQuarter();
    void ejectQuarter();
    void turnCrank();
    void dispense();
    void refill();
    std::string toString();

private:
    GumballMachine* m_gumballMachine;
};

#endif // _STATE_H_
