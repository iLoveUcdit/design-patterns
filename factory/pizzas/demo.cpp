#include "pizza.hpp"
#include "simple-pizza-factory.hpp"
#include "pizza-store.hpp"

#include <iostream>

int main() {

    SimplePizzaFactory *factory = new SimplePizzaFactory();
    // TODO
    // The new instance of SimplePizzaFactory will free by store.
    PizzaStore *store = new PizzaStore(factory);

    Pizza *pizza = store->orderPizza("cheese");
    std::cout << "We ordered a " + pizza->getName() << std::endl;
    std::cout << pizza->toString() << std::endl;
    delete pizza;

    pizza = store->orderPizza("veggie");
    std::cout << "We ordered a " + pizza->getName() << std::endl;
    std::cout << pizza->toString() << std::endl;
    delete pizza;

    delete store;

    return 0;
}
