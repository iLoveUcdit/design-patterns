#include <iostream>

#ifndef _QUACK_BEHAVIOR_HPP_
#define _QUACK_BEHAVIOR_HPP_

class QuackBehavior {
public:
    QuackBehavior() {}
    virtual ~QuackBehavior() {}
    virtual void quack() = 0;
};

class Quack : public QuackBehavior {
public:
    Quack() {}
    virtual ~Quack() {}
    void quack() {
        std::cout << "Quack." << std::endl;
    }
};

class Squeak : public QuackBehavior {
public:
    Squeak() {}
    virtual ~Squeak() {}
    void quack() {
        std::cout << "Squeak." << std::endl;
    }
};

class MuteQuack : public QuackBehavior {
public:
    MuteQuack() {}
    virtual ~MuteQuack() {}
    void quack() {
        std::cout << "<< Silence >>." << std::endl;
    }
};

class FackQuack : public QuackBehavior {
public:
    FackQuack() {}
    virtual ~FackQuack() {}
    void quack() {
        std::cout << "Qwak." << std::endl;
    }
};

#endif // _QUACK_BEHAVIOR_HPP_
