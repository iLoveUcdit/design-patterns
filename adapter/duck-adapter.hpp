#ifndef _DUCK_ADAPTER_HPP_
#define _DUCK_ADAPTER_HPP_

#include "duck.hpp"
#include "turkey.hpp"

#include <ctime>
#include <cstdlib>

class DuckAdapter : public Turkey {
public:
    DuckAdapter(Duck *duck) {
        m_duck = duck;
    }
    virtual ~DuckAdapter() {}
    void gobble() {
        m_duck->quack();
    }
    void fly() {
        srand(time(NULL));
        if (rand() % 5  == 0) {
            m_duck->fly();
        }
    }

private:
    Duck *m_duck;
};

#endif // _DUCK_ADAPTER_HPP_
