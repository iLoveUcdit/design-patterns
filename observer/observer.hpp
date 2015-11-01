#ifndef _OBSERVER_HPP_
#define _OBSERVER_HPP_

class Observer {
public:
    Observer() {}
    virtual ~Observer() {}
    virtual void update() = 0;
    virtual void display() = 0;
};

#endif // _OBSERVER_HPP_
