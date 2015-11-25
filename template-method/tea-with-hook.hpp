#ifndef _TEA_WITH_HOOK_HPP_
#define _TEA_WITH_HOOK_HPP_

#include "caffeine-beverage-with-hook.hpp"

#include <cctype>
#include <string>
#include <iostream>

class TeaWithHook : public CaffeineBeverageWithHook {
public:
    TeaWithHook() {}
    virtual ~TeaWithHook() {}
    void brew() {
        std::cout << "Steeping the tea" << std::endl;
    }
    void addCondiments() {
        std::cout << "Adding Lemon" << std::endl;
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
        std::cout << "Would you like lemon with your tea (y/n)? ";
        std::cin >> answer;
        if (answer == "") {
            return "no";
        }
        return answer;
    }
};

#endif // _TEA_WITH_HOOK_HPP_
