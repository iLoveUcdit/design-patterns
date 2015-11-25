#ifndef _TEA_HPP_
#define _TEA_HPP_

#include "caffeine-beverage.hpp"

#include <iostream>

class Tea : public CaffeineBeverage {
public:
    Tea() {}
    virtual ~Tea() {}
    void brew() {
        std::cout << "Steeping the tea" << std::endl;
    }
    void addCondiments() {
        std::cout << "Adding Lemon" << std::endl;
    }
};

#endif // _TEA_HPP_
