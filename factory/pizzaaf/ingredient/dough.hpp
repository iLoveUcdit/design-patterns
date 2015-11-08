#ifndef _DOUGH_HPP_
#define _DOUGH_HPP_

#include <string>

class Dough {
public:
    Dough() {}
    virtual ~Dough() {}
    virtual std::string toString() = 0;
};

class ThickCrustDough : public Dough {
public:
    ThickCrustDough() {}
    virtual ~ThickCrustDough() {}
    std::string toString() {
        return "ThickCrust style extra thick crust dough";
    }
};

class ThinCrustDough : public Dough {
public:
    ThinCrustDough() {}
    virtual ~ThinCrustDough() {}
    std::string toString() {
        return "Thin Crust Dough";
    }
};

#endif // _DOUGH_HPP_
