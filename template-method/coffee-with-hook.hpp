#ifndef _COFFEE_WITH_HOOK_HPP_
#define _COFFEE_WITH_HOOK_HPP_

#include "caffeine-beverage-with-hook.hpp"

#include <cctype>
#include <string>
#include <iostream>

class CoffeeWithHook : public CaffeineBeverageWithHook {
public:
    CoffeeWithHook() {}
    virtual ~CoffeeWithHook() {}
    void brew() {
        std::cout << "Dripping Coffee through filter" << std::endl;
    }
    void addCondiments() {
        std::cout << "Adding Sugar and Milk" << std::endl;
    }
    bool customerWantsCondiments() {
        std::string answer = getUserInput();
        if (tolower(answer[0]) == 'y') {
            return true;
        } else {
            return false;
        }
    }

private:
    std::string getUserInput() {
        std::string answer = "";
        std::cout << "Would you like milk and sugar with your coffee (y/n)? ";
        std::cin >> answer;
        if (answer == "") {
            return "no";
        }
        return answer;
    }
};

#endif // _COFFEE_WITH_HOOK_HPP_
