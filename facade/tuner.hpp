#ifndef _TUNER_HPP_
#define _TUNER_HPP_

#include <string>
#include <iostream>

class Amplifier;

class Tuner {
public:
    Tuner(std::string description, Amplifier *amplifier) {
        m_description = description;
    }
    virtual ~Tuner() {}
    void on() {
        std::cout << m_description << " on" << std::endl;
    }
    void off() {
        std::cout << m_description << " off" << std::endl;
    }
    void setFrequency(double frequency) {
        std::cout << m_description << " setting frequency to " << frequency << std::endl;
        m_frequency = frequency;
    }
    void setAm() {
        std::cout << m_description << " setting AM mode" << std::endl;
    }
    void setFm() {
        std::cout << m_description << " setting FM mode" << std::endl;
    }
    std::string toString() {
        return m_description;
    }

private:
    std::string m_description;
    Amplifier *m_amplifier;
    double m_frequency;
};

#endif // _TUNER_HPP_
