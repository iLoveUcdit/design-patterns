#include "beverage.hpp"
#include "base-beverage.hpp"
#include "condiment-decorator.hpp"

#include <iostream>

int main() {

    Beverage *beverage1 = new Espresso();
    std::cout << beverage1->getDescription() << " $" << beverage1->getCost() << std::endl;
    delete beverage1;

    Beverage *beverage2 = new DarkRoast();
    // TODO
    // The new instance of DarkRoast will free by beverage2.
    beverage2 = new Mocha(beverage2);
    beverage2 = new Mocha(beverage2);
    beverage2 = new Whip(beverage2);
    std::cout << beverage2->getDescription() << " $" << beverage2->getCost() << std::endl;
    delete beverage2;

    Beverage *beverage3 = new HouseBlend();
    beverage3 = new Soy(beverage3);
    beverage3 = new Mocha(beverage3);
    beverage3 = new Whip(beverage3);
    std::cout << beverage3->getDescription() << " $" << beverage3->getCost() << std::endl;
    delete beverage3;

    return 0;
}
