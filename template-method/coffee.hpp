#ifndef _COFFEE_HPP_
#define _COFFEE_HPP_

#include "caffeine-beverage.hpp"

#include <iostream>

class Coffee : public CaffeineBeverage {
public:
    Coffee() {}
    virtual ~Coffee() {}
    void brew() {
        std::cout << "Dripping Coffee through filter" << std::endl;
    }
    void addCondiments() {
        std::cout << "Adding Sugar and Milk" << std::endl;
    }
};

#endif // _COFFEE_HPP_
