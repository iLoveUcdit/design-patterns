#ifndef _CAFFEINE_BEVERAGE_HPP_
#define _CAFFEINE_BEVERAGE_HPP_

#include <iostream>

class CaffeineBeverage {
public:
    CaffeineBeverage() {}
    virtual ~CaffeineBeverage() {}
    void prepareRecipe() {
        boilWater();
        brew();
        pourInCup();
        addCondiments();
    }
    virtual void brew() = 0;
    virtual void addCondiments() = 0;
    void boilWater() {
        std::cout << "Boiling water" << std::endl;
    }
    void pourInCup() {
        std::cout << "Pouring into cup" << std::endl;
    }
};

#endif // _CAFFEINE_BEVERAGE_HPP_
