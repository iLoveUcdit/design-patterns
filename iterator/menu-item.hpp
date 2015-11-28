#ifndef _MENU_ITEM_HPP_
#define _MENU_ITEM_HPP_

#include <string>
#include <sstream>

class MenuItem {
public:
    MenuItem(std::string name, std::string description, bool vegetarian, double price) {
        m_name = name;
        m_description = description;
        m_vegetarian = vegetarian;
        m_price = price;
    }
    virtual ~MenuItem() {}
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
    std::string toString() {
        std::stringstream out;
        out << m_name << ", $" << m_price << "\n   " << m_description;
        return out.str();
    }

private:
    std::string m_name;
    std::string m_description;
    bool m_vegetarian;
    double m_price;
};

#endif // _MENU_ITEM_HPP_
