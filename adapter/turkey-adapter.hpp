#ifndef _TURKEY_ADAPTER_HPP_
#define _TURKEY_ADAPTER_HPP_

#include "duck.hpp"
#include "turkey.hpp"

class TurkeyAdapter : public Duck {
public:
    TurkeyAdapter(Turkey *turkey) {
        m_turkey = turkey;
    }
    virtual ~TurkeyAdapter() {}
    void quack() {
        m_turkey->gobble();
    }
    void fly() {
        for(int i = 0; i < 5; ++i) {
            m_turkey->fly();
        }
    }

private:
    Turkey *m_turkey;
};

#endif // _TURKEY_ADAPTER_HPP_
