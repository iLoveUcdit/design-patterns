#ifndef _CHEESE_HPP_
#define _CHEESE_HPP_

#include <string>

class Cheese {
public:
    Cheese() {}
    virtual ~Cheese() {}
    virtual std::string toString() = 0;
};

class ParmesanCheese : public Cheese {
public:
    ParmesanCheese() {}
    virtual ~ParmesanCheese() {}
    std::string toString() {
        return "Shredded Parmesan";
    }
};

class ReggianoCheese : public Cheese {
public:
    ReggianoCheese() {}
    virtual ~ReggianoCheese() {}
    std::string toString() {
        return "Reggiano Cheese";
    }
};

class MozzarellaCheese : public Cheese {
public:
    MozzarellaCheese() {}
    virtual ~MozzarellaCheese() {}
    std::string toString() {
        return "Shredded Mozzarella";
    }
};

#endif // _CHEESE_HPP_
