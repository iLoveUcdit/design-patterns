#include "state.h"
#include "gumball-machine.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

HasQuarterState::HasQuarterState(GumballMachine* gumballMachine)
{
    m_gumballMachine = gumballMachine;
    srand(time(NULL));
}

HasQuarterState::~HasQuarterState() {}

void HasQuarterState::insertQuarter()
{
    std::cout << "You can't insert another quarter" << std::endl;
}

void HasQuarterState::ejectQuarter()
{
    std::cout << "Quarter returned" << std::endl;
    m_gumballMachine->setState(m_gumballMachine->getNoQuarterState());
}

void HasQuarterState::turnCrank()
{
    std::cout << "You turned..." << std::endl;
    int winner = rand() % 10;

    if ((winner == 0) && (m_gumballMachine->getCount() > 1)) {
        m_gumballMachine->setState(m_gumballMachine->getWinnerState());
    } else {
        m_gumballMachine->setState(m_gumballMachine->getSoldState());
    }
}

void HasQuarterState::dispense()
{
    std::cout << "No gumball dispensed" << std::endl;
}

void HasQuarterState::refill() {}

std::string HasQuarterState::toString()
{
    return std::string("waiting for turn of crank");
}

NoQuarterState::NoQuarterState(GumballMachine* gumballMachine)
{
    m_gumballMachine = gumballMachine;
}

NoQuarterState::~NoQuarterState() {}

void NoQuarterState::insertQuarter()
{
    std::cout << "You inserted a quarter" << std::endl;
    m_gumballMachine->setState(m_gumballMachine->getHasQuarterState());
}

void NoQuarterState::ejectQuarter()
{
    std::cout << "You haven't inserted a quarter" << std::endl;
}

void NoQuarterState::turnCrank()
{
    std::cout << "You turned, but there's no quarter" << std::endl;
}

void NoQuarterState::dispense()
{
    std::cout << "You need to pay first" << std::endl;
}

void NoQuarterState::refill() {}

std::string NoQuarterState::toString()
{
    return std::string("waiting for quarter");
}

SoldOutState::SoldOutState(GumballMachine* gumballMachine)
{
    m_gumballMachine = gumballMachine;
}

SoldOutState::~SoldOutState() {}

void SoldOutState::insertQuarter()
{
    std::cout << "You can't insert a quarter, the machine is sold out" << std::endl;
}

void SoldOutState::ejectQuarter()
{
    std::cout << "You can't eject, you haven't inserted a quarter yet" << std::endl;
}

void SoldOutState::turnCrank()
{
    std::cout << "You turned, but there are no gumballs" << std::endl;
}

void SoldOutState::dispense()
{
    std::cout << "No gumball dispensed" << std::endl;
}

void SoldOutState::refill()
{
    m_gumballMachine->setState(m_gumballMachine->getNoQuarterState());
}

std::string SoldOutState::toString()
{
    return std::string("sold out");
}

SoldState::SoldState(GumballMachine* gumballMachine)
{
    m_gumballMachine = gumballMachine;
}

SoldState::~SoldState() {}

void SoldState::insertQuarter()
{
    std::cout << "Please wait, we're already giving you a gumball" << std::endl;
}

void SoldState::ejectQuarter()
{
    std::cout << "Sorry, you already turned the crank" << std::endl;
}

void SoldState::turnCrank()
{
    std::cout << "Turning twice doesn't get you another gumball!" << std::endl;
}

void SoldState::dispense()
{
    m_gumballMachine->releaseBall();

    if (m_gumballMachine->getCount() > 0) {
        m_gumballMachine->setState(m_gumballMachine->getNoQuarterState());
    } else {
        std::cout << "Oops, out of gumballs!" << std::endl;
        m_gumballMachine->setState(m_gumballMachine->getSoldOutState());
    }
}

void SoldState::refill() {}

std::string SoldState::toString()
{
    return std::string("dispensing a gumball");
}

WinnerState::WinnerState(GumballMachine* gumballMachine)
{
    m_gumballMachine = gumballMachine;
}

WinnerState::~WinnerState() {}

void WinnerState::insertQuarter()
{
    std::cout << "Please wait, we're already giving you a Gumball" << std::endl;
}

void WinnerState::ejectQuarter()
{
    std::cout << "Please wait, we're already giving you a Gumball" << std::endl;
}

void WinnerState::turnCrank()
{
    std::cout << "Turning again doesn't get you another gumball!" << std::endl;
}

void WinnerState::dispense()
{
    m_gumballMachine->releaseBall();

    if (m_gumballMachine->getCount() == 0) {
        m_gumballMachine->setState(m_gumballMachine->getSoldOutState());
    } else {
        m_gumballMachine->releaseBall();
        std::cout << "YOU'RE A WINNER! You got two gumballs for your quarter" << std::endl;

        if (m_gumballMachine->getCount() > 0) {
            m_gumballMachine->setState(m_gumballMachine->getNoQuarterState());
        } else {
            std::cout << "Oops, out of gumballs!" << std::endl;
            m_gumballMachine->setState(m_gumballMachine->getSoldOutState());
        }
    }
}

void WinnerState::refill() {}

std::string WinnerState::toString()
{
    return std::string("despensing two gumballs for your quarter, because YOU'RE A WINNER!");
}
