#include "state.h"
#include "gumball-machine.h"

#include <string>
#include <sstream>
#include <iostream>

GumballMachine::GumballMachine(int numberGumballs)
{
    m_soldOutState = new SoldOutState(this);
    m_noQuarterState = new NoQuarterState(this);
    m_hasQuarterState = new HasQuarterState(this);
    m_soldState = new SoldState(this);
    m_winnerState = new WinnerState(this);
    m_count = numberGumballs;

    if (numberGumballs > 0) {
        m_state = m_noQuarterState;
    } else {
        m_state = m_soldOutState;
    }
}

GumballMachine::~GumballMachine()
{
    delete m_soldOutState;
    delete m_noQuarterState;
    delete m_hasQuarterState;
    delete m_soldState;
    delete m_winnerState;
}

void GumballMachine::insertQuarter()
{
    m_state->insertQuarter();
}

void GumballMachine::ejectQuarter()
{
    m_state->ejectQuarter();
}

void GumballMachine::turnCrank()
{
    m_state->turnCrank();
    m_state->dispense();
}

void GumballMachine::setState(State* state)
{
    m_state = state;
}

void GumballMachine::releaseBall()
{
    std::cout << "A gumball comes rolling out the slot..." << std::endl;

    if (m_count != 0) {
        m_count = m_count - 1;
    }
}

int GumballMachine::getCount()
{
    return m_count;
}

void GumballMachine::refill(int count)
{
    m_count += count;
    std::cout << "The gumball machine was just refilled; it's new count is: " << m_count << std::endl;
    m_state->refill();
}

State* GumballMachine::getState()
{
    return m_state;
}

State* GumballMachine::getSoldOutState()
{
    return m_soldOutState;
}

State* GumballMachine::getNoQuarterState()
{
    return m_noQuarterState;
}

State* GumballMachine::getHasQuarterState()
{
    return m_hasQuarterState;
}

State* GumballMachine::getSoldState()
{
    return m_soldState;
}

State* GumballMachine::getWinnerState()
{
    return m_winnerState;
}

std::string GumballMachine::toString()
{
    std::stringstream out;
    out << "\nMighty Gumball, Inc.";
    out << "\nJava-enabled Standing Gumball Model #2004";
    out << "\nInventory: " << m_count << " gumball";
    if (m_count != 1) {
        out << "s";
    }
    out << "\n";
    out << "Machine is " << m_state << "\n";
    return out.str();
}
