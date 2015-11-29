#ifndef _MENU_ITEM_HPP_
#define _MENU_ITEM_HPP_

#include "iterator.hpp"
#include "menu-component.hpp"

#include <string>
#include <iostream>

class MenuItem : public MenuComponent {
public:
    MenuItem(std::string name, std::string description, bool vegetarian, double price) {
        m_name = name;
        m_description = description;
        m_vegetarian = vegetarian;
        m_price = price;
    }
    virtual ~MenuItem() {}
    void add(MenuComponent* menuComponent) {}
    void remove(MenuComponent* menuComponent) {}
    MenuComponent* getChild(int index) {
        return NULL;
    }
    std::string getName() {
        return m_name;
    }
    std::string getDescription() {
        return m_description;
    }
    double getPrice() {
        return m_price;
    }
    bool isVegetarian() {
        return m_vegetarian;
    }
    Iterator* createIterator() {
        return (new NullIterator());
    }
    void print() {
        std::cout << "  " << getName();
        if (isVegetarian()) {
            std::cout << "(v)";
        }
        std::cout << ", " << getPrice() << std::endl;
        std::cout << "     -- " << getDescription() << std::endl;
    }

private:
    std::string m_name;
    std::string m_description;
    bool m_vegetarian;
    double m_price;
};

#endif // _MENU_ITEM_HPP_
