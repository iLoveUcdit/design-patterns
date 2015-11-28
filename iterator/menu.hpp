#ifndef _MENU_HPP_
#define _MENU_HPP_

#include "iterator.hpp"
#include "menu-item.hpp"

#include <list>
#include <string>
#include <vector>
#include <iostream>

class Menu {
public:
    Menu() {}
    virtual ~Menu() {}
    virtual Iterator *createIterator() = 0;
};

class DinerMenu : public Menu {
public:
    DinerMenu() {
        addItem("Vegetarian BLT", "(Fakin') Bacon with lettuce & tomato on whole wheat", true, 2.99);
        addItem("BLT", "Bacon with lettuce & tomato on whole wheat", false, 2.99);
        addItem("Soup of the day", "Soup of the day, with a side of potato salad", false, 3.29);
        addItem("Hotdog", "A hot dog, with saurkraut, relish, onions, topped with cheese", false, 3.05);
        addItem("Steamed Veggies and Brown Rice", "Steamed vegetables over brown rice", true, 3.99);
        addItem("Pasta", "Spaghetti with Marinara Sauce, and a slice of sourdough bread", true, 3.89);
    }
    virtual ~DinerMenu() {
        for (std::list<MenuItem *>::iterator it = m_menuItems.begin(); it != m_menuItems.end(); ++it) {
            if (*it != NULL) {
                delete *it;
            }
        }
    }
    void addItem(std::string name, std::string description, bool vegetarian, double price) {
        m_menuItems.push_back(new MenuItem(name, description, vegetarian, price));
    }
    Iterator* createIterator() {
        return (new DinerMenuIterator(&m_menuItems));
    }

private:
    std::list<MenuItem*> m_menuItems;
};


class PancakeHouseMenu : public Menu {
public:
    PancakeHouseMenu() {
        addItem("K&B's Pancake Breakfast", "Pancakes with scrambled eggs, and toast", true, 2.99);
        addItem("Regular Pancake Breakfast", "Pancakes with fried eggs, sausage", false, 2.99);
        addItem("Blueberry Pancakes", "Pancakes made with fresh blueberries", true, 3.49);
        addItem("Waffles", "Waffles, with your choice of blueberries or strawberries", true, 3.59);
    }
    virtual ~PancakeHouseMenu() {
        for (std::vector<MenuItem *>::iterator it = m_menuItems.begin(); it != m_menuItems.end(); ++it) {
            if (*it != NULL) {
                delete *it;
            }
        }
    }
    void addItem(std::string name, std::string description, bool vegetarian, double price) {
        m_menuItems.push_back(new MenuItem(name, description, vegetarian, price));
    }
    Iterator* createIterator() {
        return (new PancakeHouseMenuIterator(&m_menuItems));
    }


private:
    std::vector<MenuItem *> m_menuItems;
};

#endif // _MENU_HPP_
