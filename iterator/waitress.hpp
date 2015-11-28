#ifndef _WAITRESS_HPP_
#define _WAITRESS_HPP_

#include "menu.hpp"
#include "menu-item.hpp"
#include "iterator.hpp"

#include <iostream>

class Waitress {
public:
    Waitress(Menu* pancakeHouseMenu, Menu* dinerMenu) {
        m_pancakeHouseMenu = pancakeHouseMenu;
        m_dinerMenu = dinerMenu;
    }
    virtual ~Waitress() {}
    void printMenu() {
        Iterator *pancakeIterator = m_pancakeHouseMenu->createIterator();
        Iterator *dinerIterator = m_dinerMenu->createIterator();
        std::cout << "MENU\n----\nBREAKFAST" << std::endl;
        printMenu(pancakeIterator);
        std::cout << "\nLUNCH" << std::endl;
        printMenu(dinerIterator);
        delete pancakeIterator;
        delete dinerIterator;
    }

private:
    void printMenu(Iterator *iterator) {
        while (iterator->hasNext()) {
            MenuItem *menuItem = iterator->next();
            std::cout << menuItem->getName() << ", ";
            std::cout << menuItem->getPrice() << " -- ";
            std::cout << menuItem->getDescription() << std::endl;
        }
    }

    Menu* m_pancakeHouseMenu;
    Menu* m_dinerMenu;
};

#endif // _WAITRESS_HPP_
