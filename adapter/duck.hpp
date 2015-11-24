#ifndef _DUCK_HPP_
#define _DUCK_HPP_

#include <iostream>

class Duck {
public:
    Duck() {}
    virtual ~Duck() {}
    virtual void quack() = 0;
    virtual void fly() = 0;
};

class MallardDuck : public Duck {
public:
    MallardDuck() {}
    virtual ~MallardDuck() {}
    void quack() {
        std::cout << "Quack" << std::endl;
    }
    void fly() {
        std::cout << "I'm flying" << std::endl;
    }
};

#endif // _DUCK_HPP_
