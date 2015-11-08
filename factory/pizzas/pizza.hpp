#include <vector>
#include <string>
#include <iostream>

#ifndef _PIZZA_HPP_
#define _PIZZA_HPP_

class Pizza {
public:
    Pizza() {
        m_name = "";
        m_dough = "";
        m_sauce = "";
        m_toppings.clear();
    }
    virtual ~Pizza() {};
    std::string getName() {
        return m_name;
    }
    void prepare() {
        std::cout << "Preparing " << m_name << std::endl;
    }
    void bake() {
        std::cout << "Baking " << m_name << std::endl;
    }
    void cut() {
        std::cout << "Cutting " << m_name << std::endl;
    }
    void box() {
        std::cout << "Boxing " << m_name << std::endl;
    }
    std::string toString() {
        std::string str = "";
        str += "---- " + m_name + " ----\n";
        str += m_dough + "\n";
        str += m_sauce + "\n";
        for (std::vector<std::string>::iterator it = m_toppings.begin(); it != m_toppings.end(); ++it) {
            str += (*it) + "\n";
        }
        return str;
    }

protected:
    std::string m_name;
    std::string m_dough;
    std::string m_sauce;
    std::vector<std::string> m_toppings;
};

class CheesePizza : public Pizza {
public:
    CheesePizza() {
        Pizza::m_name = "Cheese Pizza";
        Pizza::m_dough = "Regular Crust";
        Pizza::m_sauce = "Marinara Pizza Sauce";
        Pizza::m_toppings.push_back("Fresh Mozzarella");
        Pizza::m_toppings.push_back("Parmesan");
    }
    virtual ~CheesePizza() {}
};

class ClamPizza : public Pizza {
public:
    ClamPizza() {
        Pizza::m_name = "Clam Pizza";
        Pizza::m_dough = "Thin Crust";
        Pizza::m_sauce = "White Garlic Sauce";
        Pizza::m_toppings.push_back("Clams");
        Pizza::m_toppings.push_back("Grated Parmesan Cheese");
    }
    virtual ~ClamPizza() {}
};

class PepperoniPizza : public Pizza {
public:
    PepperoniPizza() {
        Pizza::m_name = "Pepperoni Pizza";
        Pizza::m_dough = "Crust";
        Pizza::m_sauce = "Marinara Sauce";
        Pizza::m_toppings.push_back("Sliced Pepperoni");
        Pizza::m_toppings.push_back("Sliced Onion");
        Pizza::m_toppings.push_back("Grated Parmesan Cheese");
    }
    virtual ~PepperoniPizza() {}
};

class VeggiePizza : public Pizza {
public:
    VeggiePizza() {
        Pizza::m_name = "Veggie Pizza";
        Pizza::m_dough = "Crust";
        Pizza::m_sauce = "Marinara Sauce";
        Pizza::m_toppings.push_back("Shredded Mozzarella");
        Pizza::m_toppings.push_back("Grated Parmesan");
        Pizza::m_toppings.push_back("Diced Onion");
        Pizza::m_toppings.push_back("Sliced Mushrooms");
        Pizza::m_toppings.push_back("Sliced Red Pepper");
        Pizza::m_toppings.push_back("Sliced Black Olives");
    }
    virtual ~VeggiePizza() {}
};

#endif // _PIZZA_HPP_
