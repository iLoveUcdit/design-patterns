#include "fly-behavior.hpp"
#include "quack-behavior.hpp"

#include <iostream>

#ifndef _DUCK_HPP_
#define _DUCK_HPP_

class Duck {
public:
    Duck() {
        m_flyBehavior = NULL;
        m_quackBehavior = NULL;
    }
    virtual ~Duck() {
        if (m_flyBehavior != NULL) {
            delete m_flyBehavior;
        }
        if (m_quackBehavior != NULL) {
            delete m_quackBehavior;
        }
    }
    void setFlyBehavior(FlyBehavior *fb) {
        if (m_flyBehavior != NULL) {
            delete m_flyBehavior;
        }
        m_flyBehavior = fb;
    }
    void setQuackBehavior(QuackBehavior *qb) {
        if (m_quackBehavior != NULL) {
            delete m_quackBehavior;
        }
        m_quackBehavior = qb;
    }
    virtual void display() = 0;
    void performFly() {
        if (m_flyBehavior != NULL) {
            m_flyBehavior->fly();
        }
    }
    void performQuack() {
        if (m_quackBehavior != NULL) {
            m_quackBehavior->quack();
        }
    }
    void swim() {
        std::cout << "All ducks float, even decoys!" << std::endl;
    }

private:
    FlyBehavior *m_flyBehavior;
    QuackBehavior *m_quackBehavior;
};

class DecoyDuck : public Duck {
public:
    DecoyDuck() {
        setFlyBehavior(new FlyNoWay());
        setQuackBehavior(new MuteQuack());
    }
    virtual ~DecoyDuck() {}
    void display() {
        std::cout << "I'm a duck Decoy." << std::endl;
    }
};

class MallardDuck : public Duck {
public:
    MallardDuck() {
        setFlyBehavior(new FlyWithWings());
        setQuackBehavior(new Quack());
    }
    virtual ~MallardDuck() {}
    void display() {
        std::cout << "I'm a real Mallard duck." << std::endl;
    }
};

class RedHeadDuck : public Duck {
public:
    RedHeadDuck() {
        setFlyBehavior(new FlyWithWings());
        setQuackBehavior(new Quack());
    }
    virtual ~RedHeadDuck() {}
    void display() {
        std::cout << "I'm a real Read Headed duck." << std::endl;
    }
};

class ModelDuck : public Duck {
public:
    ModelDuck() {
        setFlyBehavior(new FlyNoWay());
        setQuackBehavior(new Quack());
    }
    virtual ~ModelDuck() {}
    void display() {
        std::cout << "I'm a model duck." << std::endl;
    }
};

class RubberDuck : public Duck {
public:
    RubberDuck() {
        setFlyBehavior(new FlyNoWay());
        setQuackBehavior(new Squeak());
    }
    virtual ~RubberDuck() {}
    void display() {
        std::cout << "I'm a rubber duckie." << std::endl;
    }
};

#endif // _DUCK_HPP_
