#ifndef _POPCORN_POPPER_HPP_
#define _POPCORN_POPPER_HPP_

#include <string>
#include <iostream>

class PopcornPopper {
public:
    PopcornPopper(std::string description) {
        m_description = description;
    }
    virtual ~PopcornPopper() {}
    void on() {
        std::cout << m_description  <<  " on" << std::endl;
    }
    void off() {
        std::cout << m_description  <<  " off" << std::endl;
    }
    void pop() {
        std::cout << m_description  <<  " popping popcorn!" << std::endl;
    }
    std::string toString() {
        return m_description;
    }

private:
    std::string m_description;
};

#endif // _POPCORN_POPPER_HPP_
