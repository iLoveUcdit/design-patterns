#include <string>

#ifndef _BEVERAGE_H_
#define _BEVERAGE_H_

class Beverage {
public:
    Beverage() {
        m_description = "Unknown Beverage";
    }
    virtual ~Beverage() {}
    virtual std::string getDescription() {
        return m_description;
    }
    virtual double getCost() = 0;
protected:
    std::string m_description;
};

#endif // _BEVERAGE_H_
