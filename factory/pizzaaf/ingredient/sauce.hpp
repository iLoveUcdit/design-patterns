#ifndef _SAUCE_HPP_
#define _SAUCE_HPP_

#include <string>

class Sauce {
public:
    Sauce() {}
    virtual ~Sauce() {}
    virtual std::string toString() = 0;
};

class PlumTomatoSauce : public Sauce {
public:
    PlumTomatoSauce() {}
    virtual ~PlumTomatoSauce() {}
    std::string toString() {
        return "Tomato sauce with plum tomatoes";
    }
};

class MarinaraSauce : public Sauce {
public:
    MarinaraSauce() {}
    virtual ~MarinaraSauce() {}
    std::string toString() {
        return "Marinara Sauce";
    }
};

#endif // _SAUCE_HPP_
