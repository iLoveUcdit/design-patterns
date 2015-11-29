#ifndef _MENU_HPP_
#define _MENU_HPP_

#include "iterator.hpp"
#include "menu-component.hpp"

#include <string>
#include <vector>
#include <iostream>

class Menu : public MenuComponent {
public:
    Menu(std::string name, std::string description) {
        m_name = name;
        m_description = description;
    }
    virtual ~Menu() {
        std::vector<MenuComponent*>::iterator it = m_menuComponents.begin();
        for (; it != m_menuComponents.end(); ++it) {
            if (*it != NULL) {
                delete (*it);
            }
        }
    }
    void add(MenuComponent* menuComponent) {
        m_menuComponents.push_back(menuComponent);
    }
    void remove(MenuComponent* menuComponent) {
        std::vector<MenuComponent*>::iterator it = m_menuComponents.begin();
        for (; it != m_menuComponents.end(); ++it) {
            if (*it == menuComponent) {
                break;
            }
        }
        if (it != m_menuComponents.end()) {
            m_menuComponents.erase(it);
        }
    }
    MenuComponent* getChild(int index) {
        return m_menuComponents[index];
    }
    std::string getName() {
        return m_name;
    }
    std::string getDescription() {
        return m_description;
    }
    double getPrice() {
        return 0.0;
    }
    bool isVegetarian() {
        return false;
    }
    Iterator* createIterator() {
        return (new CompositeIterator(new VectorIterator(&m_menuComponents)));
    }
    void print() {
        std::cout << "\n" << getName();
        std::cout << ", " << getDescription() << std::endl;
        std::cout << "---------------------" << std::endl;
        Iterator* iterator = createIterator();
        while (iterator->hasNext()) {
            MenuComponent* menuComponent = iterator->next();
            menuComponent->print();
        }
        delete iterator;
    }

private:
    std::vector<MenuComponent*> m_menuComponents;
    std::string m_name;
    std::string m_description;
};

#endif // _MENU_HPP_
