#include "singleton.hpp"

#include <iostream>

int main() {

    Singleton &singleton1 = Singleton::getInstance();
    std::cout << singleton1.getDescription() << std::endl;

    Singleton &singleton2 = Singleton::getInstance();
    std::cout << singleton2.getDescription() << std::endl;

    return 0;
}
