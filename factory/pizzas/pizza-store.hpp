#include "pizza.hpp"
#include "simple-pizza-factory.hpp"

#ifndef _PIZZA_STORE_HPP_
#define _PIZZA_STORE_HPP_

class PizzaStore {
public:
    PizzaStore(SimplePizzaFactory *factory) {
        m_factory = factory;
    }
    virtual ~PizzaStore() {
        if (m_factory != NULL) {
            delete m_factory;
            m_factory = NULL;
        }
    }
    Pizza *orderPizza(std::string type) {
        Pizza *pizza = m_factory->createPizza(type);
        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();
        return pizza;
    }

private:
    SimplePizzaFactory *m_factory;
};

#endif // _PIZZA_STORE_HPP_
