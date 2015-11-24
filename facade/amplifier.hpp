#ifndef _AMPLIFIER_HPP_
#define _AMPLIFIER_HPP_

#include "tuner.hpp"
#include "cd-player.hpp"
#include "dvd-player.hpp"

#include <string>
#include <iostream>

class Amplifier {
public:
    Amplifier(std::string description) {
        m_description = description;
    }
    virtual ~Amplifier() {}
    void on() {
        std::cout << m_description << " on" << std::endl;
    }
    void off() {
        std::cout << m_description << " off" << std::endl;
    }
    void setStereoSound() {
        std::cout << m_description << " stereo mode on" << std::endl;
    }
    void setSurroundSound() {
        std::cout << m_description << " surround sound on (5 speakers, 1 subwoofer)" << std::endl;
    }
    void setVolume(int level) {
        std::cout << m_description << " setting volume to " << level << std::endl;
    }
    void setTuner(Tuner *tuner) {
        std::cout << m_description << " setting tuner to " << tuner->toString() << std::endl;
        m_tuner = tuner;
    }
    void setDvd(DvdPlayer *dvd) {
        std::cout << m_description << " setting DVD player to " << dvd->toString() << std::endl;
        m_dvd = dvd;
    }
    void setCd(CdPlayer *cd) {
        std::cout << m_description << " setting CD player to " << cd->toString() << std::endl;
        m_cd = cd;
    }
    std::string toString() {
        return m_description;
    }

private:
    std::string m_description;
    Tuner *m_tuner;
    DvdPlayer *m_dvd;
    CdPlayer *m_cd;
};

#endif // _AMPLIFIER_HPP_
