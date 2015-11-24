#ifndef _THEATER_LIGHTS_HPP_
#define _THEATER_LIGHTS_HPP_

#include <string>
#include <iostream>

class TheaterLights {
public:
    TheaterLights(std::string description) {
        m_description = description;
    }
    virtual ~TheaterLights() {}
    void on() {
        std::cout << m_description << " on" << std::endl;
    }
    void off() {
        std::cout << m_description << " off" << std::endl;
    }
    void dim(int level) {
        std::cout << m_description << " dimming to " << level  << "%" << std::endl;
    }
    std::string toString() {
        return m_description;
    }

private:
    std::string m_description;
};

#endif // _THEATER_LIGHTS_HPP_
