#ifndef _WAITRESS_HPP_
#define _WAITRESS_HPP_

#include "iterator.hpp"
#include "menu-component.hpp"

#include <iostream>

class Waitress {
public:
    Waitress(MenuComponent* allMenus) {
        m_allMenus = allMenus;
    }
    virtual ~Waitress() {}
    void printMenu() {
        m_allMenus->print();
    }
    void printVegetarianMenu() {
        Iterator* iterator = m_allMenus->createIterator();
        std::cout << "\nVEGETARIAN MENU\n----" << std::endl;
        while (iterator->hasNext()) {
            MenuComponent* menuComponent = iterator->next();
            if (menuComponent != NULL && menuComponent->isVegetarian()) {
                menuComponent->print();
            }
        }
        delete iterator;
    }

private:
    MenuComponent* m_allMenus;
};

#endif // _WAITRESS_HPP_ 
