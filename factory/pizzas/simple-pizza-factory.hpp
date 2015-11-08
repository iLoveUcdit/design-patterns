#include "pizza.hpp"

#ifndef _SIMPLE_PIZZA_FACTORY_HPP_
#define _SIMPLE_PIZZA_FACTORY_HPP_

class SimplePizzaFactory {
public:
    SimplePizzaFactory() {}
    virtual ~SimplePizzaFactory() {}
    static Pizza *createPizza(std::string type) {
        Pizza *pizza = NULL;
        if (type == "cheese") {
            pizza = new CheesePizza();
        } else if (type == "pepperoni") {
            pizza = new PepperoniPizza();
        } else if (type == "clam") {
            pizza = new ClamPizza();
        } else if (type == "veggie") {
            pizza = new VeggiePizza();
        }
        return pizza;
    }
};

#endif // _SIMPLE_PIZZA_FACTORY_HPP_
