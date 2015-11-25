#include "tea.hpp"
#include "coffee.hpp"
#include "tea-with-hook.hpp"
#include "coffee-with-hook.hpp"

#include <iostream>

int main() {

    Tea *tea = new Tea();
    Coffee *coffee = new Coffee();

    std::cout << "\nMaking tea..." << std::endl;
    tea->prepareRecipe();

    std::cout << "\nMaking coffee..." << std::endl;
    coffee->prepareRecipe();

    delete tea;
    delete coffee;

    TeaWithHook *teaHook = new TeaWithHook();
    CoffeeWithHook *coffeeHook = new CoffeeWithHook();

    std::cout << "\nMaking tea..." << std::endl;
    teaHook->prepareRecipe();

    std::cout << "\nMaking coffee..." << std::endl;
    coffeeHook->prepareRecipe();

    delete teaHook;
    delete coffeeHook;

    return 0;
}
