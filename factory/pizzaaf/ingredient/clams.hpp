#ifndef _CLAMS_HPP_
#define _CLAMS_HPP_

#include <string>

class Clams {
public:
    Clams() {}
    virtual ~Clams() {}
    virtual std::string toString() = 0;
};

class FreshClams : public Clams {
public:
    FreshClams() {}
    virtual ~FreshClams() {}
    std::string toString() {
        return "Fresh Clams from Long Island Sound";
    }
};

class FrozenClams : public Clams {
public:
    FrozenClams() {}
    virtual ~FrozenClams() {}
    std::string toString() {
        return "Frozen Clams from Chesapeake Bay";
    }
};

#endif // _CLAMS_HPP_
