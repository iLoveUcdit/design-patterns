#include "beverage.hpp"

#ifndef _BASE_BEVERAGE_HPP_
#define _BASE_BEVERAGE_HPP_

class DarkRoast : public Beverage {
public:
    DarkRoast() {
        m_description = "Dark Roast Coffee";
    }
    virtual ~DarkRoast() {}
    double getCost() {
        return 0.99;
    }
};

class Decaf : public Beverage {
public:
    Decaf() {
        m_description = "Decaf Coffee";
    }
    virtual ~Decaf() {}
    double getCost() {
        return 1.05;
    }
};

class Espresso : public Beverage {
public:
    Espresso() {
        m_description = "Espresso Coffee";
    }
    virtual ~Espresso() {}
    double getCost() {
        return 1.99;
    }
};

class HouseBlend : public Beverage {
public:
    HouseBlend() {
        m_description = "House Blend Coffee";
    }
    virtual ~HouseBlend() {}
    double getCost() {
        return 0.89;
    }
};

#endif // _BASE_BEVERAGE_HPP_
