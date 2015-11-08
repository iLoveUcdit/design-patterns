#include "pizza.hpp"

#include <iostream>

#ifndef _PIZZA_STORE_HPP_
#define _PIZZA_STORE_HPP_

class PizzaStore {
public:
    PizzaStore() {}
    virtual ~PizzaStore() {}
    virtual Pizza *createPizza(std::string item) = 0;
    Pizza *orderPizza(std::string type) {
        Pizza *pizza = createPizza(type);
        std::cout << "--- Making a " <<  pizza->getName() << " ---" << std::endl;
        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();
        return pizza;
    }
};

class ChicagoPizzaStore : public PizzaStore {
public:
    ChicagoPizzaStore() {}
    virtual ~ChicagoPizzaStore() {}
    Pizza *createPizza(std::string item) {
        if (item == "cheese") {
            return new ChicagoStyleCheesePizza();
        } else if (item == "veggie") {
            return new ChicagoStyleVeggiePizza();
        } else if (item == "clam") {
            return new ChicagoStyleClamPizza();
        } else if (item == "pepperoni") {
            return new ChicagoStylePepperoniPizza();
        } else {
            return NULL;
        }
    }
};

class NYPizzaStore : public PizzaStore {
public:
    NYPizzaStore() {}
    virtual ~NYPizzaStore() {}
    Pizza *createPizza(std::string item) {
        if (item == "cheese") {
            return new NYStyleCheesePizza();
        } else if (item == "veggie") {
            return new NYStyleVeggiePizza();
        } else if (item == "clam") {
            return new NYStyleClamPizza();
        } else if (item == "pepperoni") {
            return new NYStylePepperoniPizza();
        } else {
            return NULL;
        }
    }
};

#endif // _PIZZA_STORE_HPP_
