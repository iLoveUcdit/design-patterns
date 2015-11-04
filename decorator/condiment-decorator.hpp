#include "beverage.hpp"

#ifndef _CONDIMENT_DECORATOR_H_
#define _CONDIMENT_DECORATOR_H_

class CondimentDecorator : public Beverage {
public:
    CondimentDecorator(Beverage *beverage) {
        m_beverage = beverage;
    }
    virtual ~CondimentDecorator() {
        if (m_beverage != NULL) {
            delete m_beverage;
        }
    }
protected:
    Beverage *m_beverage;
};

class Whip : public CondimentDecorator {
public:
    Whip(Beverage *beverage) : CondimentDecorator(beverage) {}
    virtual ~Whip() {}
    std::string getDescription() {
        return m_beverage->getDescription() + ", Whip";
    }
    double getCost() {
        return m_beverage->getCost() + 0.10;
    }
};

class Soy : public CondimentDecorator {
public:
    Soy(Beverage *beverage) : CondimentDecorator(beverage) {}
    virtual ~Soy() {}
    std::string getDescription() {
        return m_beverage->getDescription() + ", Soy";
    }
    double getCost() {
        return m_beverage->getCost() + 0.15;
    }
};

class Mocha : public CondimentDecorator {
public:
    Mocha(Beverage *beverage) : CondimentDecorator(beverage) {}
    virtual ~Mocha() {}
    std::string getDescription() {
        return m_beverage->getDescription() + ", Mocha";
    }
    double getCost() {
        return m_beverage->getCost() + 0.20;
    }
};

class Milk : public CondimentDecorator {
public:
    Milk(Beverage *beverage) : CondimentDecorator(beverage) {}
    virtual ~Milk() {}
    std::string getDescription() {
        return m_beverage->getDescription() + ", Milk";
    }
    double getCost() {
        return m_beverage->getCost() + 0.10;
    }
};

#endif // _CONDIMENT_DECORATOR_H_
