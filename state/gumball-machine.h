#ifndef _GUMBALL_MACHINE_H_
#define _GUMBALL_MACHINE_H_

#include <string>

class State;

class GumballMachine {
public:
    GumballMachine(int numberGumballs);
    virtual ~GumballMachine();
    void insertQuarter();
    void ejectQuarter();
    void turnCrank();
    void setState(State* state);
    void releaseBall();
    int getCount();
    void refill(int count);
    State* getState();
    State* getSoldOutState();
    State* getNoQuarterState();
    State* getHasQuarterState();
    State* getSoldState();
    State* getWinnerState();
    std::string toString();

private:
    State* m_soldOutState;
    State* m_noQuarterState;
    State* m_hasQuarterState;
    State* m_soldState;
    State* m_winnerState;
    State* m_state;
    int m_count;
};

#endif // _GUMBALL_MACHINE_H_
