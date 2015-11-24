#ifndef _SCREEN_HPP_
#define _SCREEN_HPP_

#include <string>
#include <iostream>

class Screen {
public:
    Screen(std::string description) {
        m_description = description;
    }
    virtual ~Screen() {}
    void up() {
        std::cout << m_description << " going up" << std::endl;
    }
    void down() {
        std::cout << m_description << " going down" << std::endl;
    }
    std::string toString() {
        return m_description;
    }

private:
    std::string m_description;
};

#endif // _SCREEN_HPP_
