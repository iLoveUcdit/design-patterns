#ifndef _PIZZA_STORE_HPP_
#define _PIZZA_STORE_HPP_

#include "pizza.hpp"
#include "pizza-ingredient-factory.hpp"

#include <string>

class PizzaStore {
public:
    PizzaStore() {}
    virtual ~PizzaStore() {}
    virtual Pizza *createPizza(std::string item) = 0;
    Pizza *orderPizza(std::string type) {
        Pizza *pizza = createPizza(type);
        std::cout << "--- Making a " << pizza->getName() << " ---" << std::endl;
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
        Pizza *pizza = NULL;
        PizzaIngredientFactory *ingredientFactory = new ChicagoPizzaIngredientFactory();
        // TODO
        // The new instance of PizzaIngredientFactory will free by pizza.
        if (item == "cheese") {
            pizza = new CheesePizza(ingredientFactory);
            pizza->setName("Chicago Style Cheese Pizza");
        } else if (item == "veggie") {
            pizza = new VeggiePizza(ingredientFactory);
            pizza->setName("Chicago Style Veggie Pizza");
        } else if (item == "clam") {
            pizza = new ClamPizza(ingredientFactory);
            pizza->setName("Chicago Style Clam Pizza");
        } else if (item == "pepperoni") {
            pizza = new PepperoniPizza(ingredientFactory);
            pizza->setName("Chicago Style Pepperoni Pizza");
        }
        return pizza;
    }
};

class NYPizzaStore : public PizzaStore {
public:
    NYPizzaStore() {}
    virtual ~NYPizzaStore() {}
    Pizza *createPizza(std::string item) {
        Pizza *pizza = NULL;
        PizzaIngredientFactory *ingredientFactory = new NYPizzaIngredientFactory();
        // TODO
        // The new instance of PizzaIngredientFactory will free by pizza.
        if (item == "cheese") {
            pizza = new CheesePizza(ingredientFactory);
            pizza->setName("New York Style Cheese Pizza");
        } else if (item == "veggie") {
            pizza = new VeggiePizza(ingredientFactory);
            pizza->setName("New York Style Veggie Pizza");
        } else if (item == "clam") {
            pizza = new ClamPizza(ingredientFactory);
            pizza->setName("New York Style Clam Pizza");
        } else if (item == "pepperoni") {
            pizza = new PepperoniPizza(ingredientFactory);
            pizza->setName("New York Style Pepperoni Pizza");
        }
        return pizza;
    }
};

#endif // _PIZZA_STORE_HPP_
