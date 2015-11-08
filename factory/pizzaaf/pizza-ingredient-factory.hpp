#ifndef _PIZZA_INGREDIENT_FACTORY_HPP_
#define _PIZZA_INGREDIENT_FACTORY_HPP_

#include "ingredient.h"

#include <vector>

class PizzaIngredientFactory {
public:
    PizzaIngredientFactory() {}
    virtual ~PizzaIngredientFactory() {}
    virtual Dough *createDough() = 0;
    virtual Sauce *createSauce() = 0;
    virtual Cheese *createCheese() = 0;
    virtual std::vector<Veggies *> createVeggies() = 0;
    virtual Pepperoni *createPepperoni() = 0;
    virtual Clams *createClam() = 0;
};

class NYPizzaIngredientFactory : public PizzaIngredientFactory {
public:
    NYPizzaIngredientFactory() {}
    virtual ~NYPizzaIngredientFactory() {}
    Dough *createDough() {
        return new ThinCrustDough();
    }
    Sauce *createSauce() {
        return new MarinaraSauce();
    }
    Cheese *createCheese() {
        return new ReggianoCheese();
    }
    std::vector<Veggies *> createVeggies() {
        Veggies *veggies[] = { new Garlic(), new Onion(), new Mushroom(), new RedPepper() };
        return std::vector<Veggies *>(veggies, veggies + 4);
    }
    Pepperoni *createPepperoni() {
        return new SlicedPepperoni();
    }
    Clams *createClam() {
        return new FreshClams();
    }
};

class ChicagoPizzaIngredientFactory : public PizzaIngredientFactory {
public:
    ChicagoPizzaIngredientFactory() {}
    virtual ~ChicagoPizzaIngredientFactory() {}
    Dough *createDough() {
        return new ThickCrustDough();
    }
    Sauce *createSauce() {
        return new PlumTomatoSauce();
    }
    Cheese *createCheese() {
        return new MozzarellaCheese();
    }
    std::vector<Veggies *> createVeggies() {
        Veggies *veggies[] = { new BlackOlives(), new Spinach(), new Eggplant() };
        return std::vector<Veggies *>(veggies, veggies + 3);
    }
    Pepperoni *createPepperoni() {
        return new SlicedPepperoni();
    }
    Clams *createClam() {
        return new FrozenClams();
    }
};

#endif // _PIZZA_INGREDIENT_FACTORY_HPP_
