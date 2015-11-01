#include "observer.hpp"

#include <set>

#ifndef _SUBJECT_HPP_
#define _SUBJECT_HPP_

class Subject {
public:
    Subject() {
        m_observers.clear();
    }
    virtual ~Subject() {}
    void registerObserver(Observer *o) {
        m_observers.insert(o);
    }
    void removeObserver(Observer *o) {
        std::set<Observer *>::iterator it = m_observers.find(o);
        if (it != m_observers.end()) {
            m_observers.erase(it);
        }
    }
    void notifyObservers() {
        for (std::set<Observer *>::iterator it = m_observers.begin(); it != m_observers.end(); ++it) {
            (*it)->update();
        }
    }

private:
    std::set<Observer *> m_observers;
};

#endif // _SUBJECT_HPP_
