#ifndef _CAFFEINE_BEVERAGE_WITH_HOOK_
#define _CAFFEINE_BEVERAGE_WITH_HOOK_

#include <iostream>

class CaffeineBeverageWithHook {
public:
    CaffeineBeverageWithHook() {}
    virtual ~CaffeineBeverageWithHook() {}
    void prepareRecipe() {
        boilWater();
        brew();
        pourInCup();
        if (customerWantsCondiments()) {
            addCondiments();
        }
    }
    virtual void brew() = 0;
    virtual void addCondiments() = 0;
    void boilWater() {
        std::cout << "Boiling water" << std::endl;
    }
    void pourInCup() {
        std::cout << "Pouring into cup" << std::endl;
    }
    virtual bool customerWantsCondiments() {
        return true;
    }
};

#endif // _CAFFEINE_BEVERAGE_WITH_HOOK_
