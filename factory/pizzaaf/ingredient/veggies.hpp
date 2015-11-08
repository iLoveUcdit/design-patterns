#ifndef _VEGGIES_HPP_
#define _VEGGIES_HPP_

#include <string>

class Veggies {
public:
    Veggies() {}
    virtual ~Veggies() {}
    virtual std::string toString() = 0;
};

class Garlic : public Veggies {
public:
    Garlic() {}
    virtual ~Garlic() {}
    std::string toString() {
        return "Garlic";
    }
};

class Spinach : public Veggies {
public:
    Spinach() {}
    virtual ~Spinach() {}
    std::string toString() {
        return "Spinach";
    }
};

class BlackOlives : public Veggies {
public:
    BlackOlives() {}
    virtual ~BlackOlives() {}
    std::string toString() {
        return "Black Olives";
    }
};

class Onion : public Veggies {
public:
    Onion() {}
    virtual ~Onion() {}
    std::string toString() {
        return "Onion";
    }
};

class Mushroom : public Veggies {

public:
    Mushroom() {}
    virtual ~Mushroom() {}
    std::string toString() {
        return "Mushrooms";
    }
};

class Eggplant : public Veggies {
public:
    Eggplant() {}
    virtual ~Eggplant() {}
    std::string toString() {
        return "Eggplant";
    }
};

class RedPepper : public Veggies {
public:
    RedPepper() {}
    virtual ~RedPepper() {}
    std::string toString() {
        return "Red Pepper";
    }
};

#endif // _VEGGIES_HPP_
