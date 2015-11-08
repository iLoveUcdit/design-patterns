#ifndef _PIZZA_H_
#define _PIZZA_H_

#include "ingredient.h"
#include "pizza-ingredient-factory.hpp"

#include <string>
#include <vector>
#include <iostream>

class Pizza {
public:
    Pizza(PizzaIngredientFactory *ingredientFactory) {
        m_dough = NULL;
        m_sauce = NULL;
        m_veggies.clear();
        m_cheese = NULL;
        m_pepperoni = NULL;
        m_clam = NULL;
        m_ingredientFactory = ingredientFactory;
    }
    virtual ~Pizza() {
        if (m_dough != NULL) {
            delete m_dough;
        }
        if (m_sauce != NULL) {
            delete m_sauce;
        }
        for (std::vector<Veggies *>::iterator it = m_veggies.begin(); it !=m_veggies.end(); ++it) {
            if ((*it) != NULL) {
                delete (*it);
            }
        }
        if (m_cheese != NULL)  {
            delete m_cheese;
        }
        if (m_pepperoni != NULL) {
            delete m_pepperoni;
        }
        if (m_clam != NULL) {
            delete m_clam;
        }
        if (m_ingredientFactory != NULL) {
            delete m_ingredientFactory;
        }
    }
    virtual void prepare() = 0;
    virtual void bake() {
        std::cout << "Bake for 25 minutes at 350" << std::endl;
    }
    virtual void cut() {
        std::cout << "Cutting the pizza into diagonal slices"<< std::endl;
    }
    virtual void box() {
        std::cout << "Place pizza in official PizzaStore box"<< std::endl;
    }
    void setName(std::string name) {
        m_name = name;
    }
    std::string getName() {
        return m_name;
    }
    virtual std::string toString() {
        std::string str = "";
        str += "---- " + m_name + " ----\n";
        if (m_dough != NULL) {
            str += m_dough->toString() + "\n";
        }
        if (m_sauce != NULL) {
            str += m_sauce->toString() + "\n";
        }
        if (m_cheese != NULL) {
            str += m_cheese->toString() + "\n";
        }
        for (size_t i = 0; i < m_veggies.size(); ++i) {
            if (m_veggies[i] != NULL) {
                str += m_veggies[i]->toString() +((i == m_veggies.size() - 1) ? "\n": ", ");
            }
        }
        if (m_clam != NULL) {
            str += m_clam->toString() + "\n";
        }
        if (m_pepperoni != NULL) {
            str += m_pepperoni->toString() + "\n";
        }
        return str;
    }

protected:
    std::string m_name;
    Dough *m_dough;
    Sauce *m_sauce;
    std::vector<Veggies *> m_veggies;
    Cheese *m_cheese;
    Pepperoni *m_pepperoni;
    Clams *m_clam;
    PizzaIngredientFactory *m_ingredientFactory;
};

class ClamPizza : public Pizza {
public:
    ClamPizza(PizzaIngredientFactory *ingredientFactory) : Pizza(ingredientFactory) {}
    virtual ~ClamPizza() {}
    void prepare() {
        std::cout << "Preparing " << m_name << std::endl;
        if (m_dough != NULL) {
            delete m_dough;
        }
        m_dough = m_ingredientFactory->createDough();
        if (m_sauce != NULL) {
            delete m_sauce;
        }
        m_sauce = m_ingredientFactory->createSauce();
        if (m_cheese != NULL)  {
            delete m_cheese;
        }
        m_cheese = m_ingredientFactory->createCheese();
        if (m_clam != NULL) {
            delete m_clam;
        }
        m_clam = m_ingredientFactory->createClam();
    }
};

class CheesePizza : public Pizza {
public:
    CheesePizza(PizzaIngredientFactory *ingredientFactory) : Pizza(ingredientFactory) {}
    virtual ~CheesePizza() {}
    void prepare() {
        std::cout << "Preparing " << m_name << std::endl;
        if (m_dough != NULL) {
            delete m_dough;
        }
        m_dough = m_ingredientFactory->createDough();
        if (m_sauce != NULL) {
            delete m_sauce;
        }
        m_sauce = m_ingredientFactory->createSauce();
        if (m_cheese != NULL)  {
            delete m_cheese;
        }
        m_cheese = m_ingredientFactory->createCheese();
    }
};

class PepperoniPizza : public Pizza {
public:
    PepperoniPizza(PizzaIngredientFactory *ingredientFactory) : Pizza(ingredientFactory) {}
    virtual ~PepperoniPizza() {}
    void prepare() {
        std::cout << "Preparing " << m_name << std::endl;
        if (m_dough != NULL) {
            delete m_dough;
        }
        m_dough = m_ingredientFactory->createDough();
        if (m_sauce != NULL) {
            delete m_sauce;
        }
        m_sauce = m_ingredientFactory->createSauce();
        if (m_cheese != NULL)  {
            delete m_cheese;
        }
        m_cheese = m_ingredientFactory->createCheese();
        for (std::vector<Veggies *>::iterator it = m_veggies.begin(); it !=m_veggies.end(); ++it) {
            if ((*it) != NULL) {
                delete (*it);
            }
        }
        m_veggies = m_ingredientFactory->createVeggies();
        if (m_pepperoni  != NULL) {
            delete m_pepperoni;
        }
        m_pepperoni = m_ingredientFactory->createPepperoni();
    }
};

class VeggiePizza : public Pizza {
public:
    VeggiePizza(PizzaIngredientFactory *ingredientFactory) : Pizza(ingredientFactory) {}
    virtual ~VeggiePizza() {}
    void prepare() {
        std::cout << "Preparing " << m_name << std::endl;
        if (m_dough != NULL) {
            delete m_dough;
        }
        m_dough = m_ingredientFactory->createDough();
        if (m_sauce != NULL) {
            delete m_sauce;
        }
        m_sauce = m_ingredientFactory->createSauce();
        if (m_cheese != NULL)  {
            delete m_cheese;
        }
        m_cheese = m_ingredientFactory->createCheese();
        for (std::vector<Veggies *>::iterator it = m_veggies.begin(); it !=m_veggies.end(); ++it) {
            if ((*it) != NULL) {
                delete (*it);
            }
        }
        m_veggies = m_ingredientFactory->createVeggies();
    }
};

#endif // _PIZZA_H_
