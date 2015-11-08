#include "pizza.hpp"
#include "pizza-store.hpp"

#include <iostream>

int main() {

    PizzaStore *nyStore = new NYPizzaStore();
    PizzaStore *chicagoStore = new ChicagoPizzaStore();

    Pizza *pizza = nyStore->orderPizza("cheese");
    std::cout << "Ethan ordered a " << pizza->toString() << "\n";
    delete pizza;

    pizza = chicagoStore->orderPizza("cheese");
    std::cout << "Joel ordered a " << pizza->toString() << "\n";
    delete pizza;

    pizza = nyStore->orderPizza("clam");
    std::cout << "Ethan ordered a " << pizza->toString() << "\n";
    delete pizza;

    pizza = chicagoStore->orderPizza("clam");
    std::cout << "Joel ordered a " << pizza->toString() << "\n";
    delete pizza;

    pizza = nyStore->orderPizza("pepperoni");
    std::cout << "Ethan ordered a " << pizza->toString() << "\n";
    delete pizza;

    pizza = chicagoStore->orderPizza("pepperoni");
    std::cout << "Joel ordered a " << pizza->toString() << "\n";
    delete pizza;

    pizza = nyStore->orderPizza("veggie");
    std::cout << "Ethan ordered a " << pizza->toString() << "\n";
    delete pizza;

    pizza = chicagoStore->orderPizza("veggie");
    std::cout << "Joel ordered a " << pizza->toString() << "\n";
    delete pizza;

    delete nyStore;
    delete chicagoStore;

    return 0;
}
