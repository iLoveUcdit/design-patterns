#ifndef _TURKEY_HPP_
#define _TURKEY_HPP_

#include <iostream>

class Turkey {
public:
    Turkey() {}
    virtual ~Turkey() {}
    virtual void gobble() = 0;
    virtual void fly() = 0;
};

class WildTurkey : public Turkey {
public:
    WildTurkey() {}
    virtual ~WildTurkey() {}
    void gobble() {
        std::cout << "Gobble gobble" << std::endl;
    }
    void fly() {
        std::cout << "I'm flying a short distance" << std::endl;
    }
};

#endif // _TURKEY_HPP_
