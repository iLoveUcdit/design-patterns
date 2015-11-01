#include <iostream>

#ifndef _FLY_BEHAVIOR_HPP_
#define _FLY_BEHAVIOR_HPP_

class FlyBehavior {
public:
    FlyBehavior() {}
    virtual ~FlyBehavior() {}
    virtual void fly() = 0;
};

class FlyWithWings : public FlyBehavior {
public:
    FlyWithWings() {}
    virtual ~FlyWithWings() {}
    void fly() {
        std::cout << "I'm flying!!!" << std::endl;
    }
};

class FlyNoWay : public FlyBehavior {
public:
    FlyNoWay() {}
    virtual ~FlyNoWay() {}
    void fly() {
        std::cout << "I can't fly." << std::endl;
    }
};

class FlyRocketPowered : public FlyBehavior {
public:
    FlyRocketPowered() {}
    virtual ~FlyRocketPowered() {}
    void fly() {
        std::cout << "I'm flying with a rocket." << std::endl;
    }
};

#endif // _FLY_BEHAVIOR_HPP_
