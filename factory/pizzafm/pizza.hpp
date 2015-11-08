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
    virtual ~Pizza() {}
    std::string getName() {
        return m_name;
    }
    virtual void prepare() {
        std::cout << "Prepare " << m_name << std::endl;
        std::cout << "Tossing dough..." << std::endl;
        std::cout << "Adding sauce..." << std::endl;
        std::cout << "Adding toppings: " << std::endl;
        for (std::vector<std::string>::iterator it = m_toppings.begin(); it != m_toppings.end(); ++it) {
            std::cout << "   " << (*it) << std::endl;
        }
    }
    virtual void bake() {
        std::cout << "Bake for 25 minutes at 350" << std::endl;
    }
    virtual void cut() {
        std::cout << "Cut the pizza into diagonal slices" << std::endl;
    }
    virtual void box() {
        std::cout << "Place pizza in official PizzaStore box" << std::endl;
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

class ChicagoStyleCheesePizza : public Pizza {
public:
    ChicagoStyleCheesePizza() {
        m_name = "Chicago Style Deep Dish Cheese Pizza";
        m_dough = "Extra Thick Crust Dough";
        m_sauce = "Plum Tomato Sauce";
        m_toppings.push_back("Shredded Mozzarella Cheese");
    }
    virtual ~ChicagoStyleCheesePizza() {}
    void cut() {
        std::cout << "Cutting the pizza into square slices" << std::endl;
    }
};

class ChicagoStyleClamPizza : public Pizza {
public:
    ChicagoStyleClamPizza() {
        m_name = "Chicago Style Clam Pizza";
        m_dough = "Extra Thick Crust Dough";
        m_sauce = "Plum Tomato Sauce";
        m_toppings.push_back("Shredded Mozzarella Cheese");
        m_toppings.push_back("Frozen Clams from Chesapeake Bay");
    }
    virtual ~ChicagoStyleClamPizza() {}
    void cut() {
        std::cout << "Cutting the pizza into square slices" << std::endl;
    }
};

class ChicagoStylePepperoniPizza : public Pizza {
public:
    ChicagoStylePepperoniPizza() {
        m_name = "Chicago Style Pepperoni Pizza";
        m_dough = "Extra Thick Crust Dough";
        m_sauce = "Plum Tomato Sauce";
        m_toppings.push_back("Shredded Mozzarella Cheese");
        m_toppings.push_back("Black Olives");
        m_toppings.push_back("Spinach");
        m_toppings.push_back("Eggplant");
        m_toppings.push_back("Sliced Pepperoni");
    }
    virtual ~ChicagoStylePepperoniPizza() {}
    void cut() {
        std::cout << "Cutting the pizza into square slices" << std::endl;
    }
};

class ChicagoStyleVeggiePizza : public Pizza {
public:
    ChicagoStyleVeggiePizza() {
        m_name = "Chicago Deep Dish Veggie Pizza";
        m_dough = "Extra Thick Crust Dough";
        m_sauce = "Plum Tomato Sauce";
        m_toppings.push_back("Shredded Mozzarella Cheese");
        m_toppings.push_back("Black Olives");
        m_toppings.push_back("Spinach");
        m_toppings.push_back("Eggplant");
    }
    virtual ~ChicagoStyleVeggiePizza() {}
    void cut() {
        std::cout << "Cutting the pizza into square slices" << std::endl;
    }
};

class NYStyleCheesePizza : public Pizza {
public:
    NYStyleCheesePizza() {
        m_name = "NY Style Sauce and Cheese Pizza";
        m_dough = "Thin Crust Dough";
        m_sauce = "Marinara Sauce";
        m_toppings.push_back("Grated Reggiano Cheese");
    }
    virtual ~NYStyleCheesePizza() {}
};

class NYStyleClamPizza : public Pizza {
public:
    NYStyleClamPizza() {
        m_name = "NY Style Clam Pizza";
        m_dough = "Thin Crust Dough";
        m_sauce = "Marinara Sauce";
        m_toppings.push_back("Grated Reggiano Cheese");
        m_toppings.push_back("Fresh Clams from Long Island Sound");
    }
    virtual ~NYStyleClamPizza() {}
};

class NYStylePepperoniPizza : public Pizza {
public:
    NYStylePepperoniPizza() {
        m_name = "NY Style Pepperoni Pizza";
        m_dough = "Thin Crust Dough";
        m_sauce = "Marinara Sauce";
        m_toppings.push_back("Grated Reggiano Cheese");
        m_toppings.push_back("Sliced Pepperoni");
        m_toppings.push_back("Garlic");
        m_toppings.push_back("Onion");
        m_toppings.push_back("Mushrooms");
        m_toppings.push_back("Red Pepper");
    }
    virtual ~NYStylePepperoniPizza() {}
};

class NYStyleVeggiePizza : public Pizza {
public:
    NYStyleVeggiePizza() {
        m_name = "NY Style Veggie Pizza";
        m_dough = "Thin Crust Dough";
        m_sauce = "Marinara Sauce";
        m_toppings.push_back("Grated Reggiano Cheese");
        m_toppings.push_back("Garlic");
        m_toppings.push_back("Onion");
        m_toppings.push_back("Mushrooms");
        m_toppings.push_back("Red Pepper");
    }
    virtual ~NYStyleVeggiePizza() {}
};

#endif // _PIZZA_HPP_
