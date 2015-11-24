#ifndef _PROJECTOR_HPP_
#define _PROJECTOR_HPP_

#include "dvd-player.hpp"

#include <string>
#include <iostream>

class Projector {
public:
    Projector(std::string description, DvdPlayer *dvdPlayer) {
        m_description = description;
        m_dvdPlayer = dvdPlayer;
    }
    virtual ~Projector() {}
    void on() {
        std::cout << m_description << " on" << std::endl;
    }
    void off() {
        std::cout << m_description << " off" << std::endl;
    }
    void wideScreenMode() {
        std::cout << m_description << " in widescreen mode (16x9 aspect ratio)" << std::endl;
    }
    void tvMode() {
        std::cout << m_description << " in tv mode (4x3 aspect ratio)" << std::endl;
    }
    std::string toString() {
        return m_description;
    }

private:
    std::string m_description;
    DvdPlayer *m_dvdPlayer;
};

#endif // _PROJECTOR_HPP_
