#ifndef _MENU_COMPONENT_HPP_
#define _MENU_COMPONENT_HPP_

#include <string>

class Iterator;

class MenuComponent {
public:
    MenuComponent() {}
    virtual ~MenuComponent() {}
    virtual void add(MenuComponent* menuComponent) = 0;
    virtual void remove(MenuComponent* menuComponent) = 0;
    virtual MenuComponent* getChild(int index) = 0;
    virtual std::string getName() = 0;
    virtual std::string getDescription() = 0;
    virtual double getPrice() = 0;
    virtual bool isVegetarian() = 0;
    virtual Iterator* createIterator() = 0;
    virtual void print() = 0;
};

#endif // _MENU_COMPONENT_HPP_
