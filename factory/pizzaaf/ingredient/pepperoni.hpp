#ifndef _PEPPERONI_HPP_
#define _PEPPERONI_HPP_

#include <string>

class Pepperoni {
public:
    Pepperoni() {}
    virtual ~Pepperoni() {}
    virtual std::string toString() = 0;
};

class SlicedPepperoni : public Pepperoni {
public:
    SlicedPepperoni() {}
    virtual ~SlicedPepperoni() {}
    std::string toString() {
        return "Sliced Pepperoni";
    }
};

#endif // _PEPPERONI_HPP_
