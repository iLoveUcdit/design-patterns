#ifndef _CD_PLAYER_HPP_
#define _CD_PLAYER_HPP_

#include <string>
#include <iostream>

class Amplifier;

class CdPlayer {
public:
    CdPlayer(std::string description, Amplifier *amplifier) {
        m_description = description;
        m_amplifier = amplifier;
    }
    virtual ~CdPlayer() {}
    void on() {
        std::cout << m_description << " on" << std::endl;
    }
    void off() {
        std::cout << m_description << " off" << std::endl;
    }
    void eject() {
        m_title = "";
        std::cout << m_description << " eject" << std::endl;
    }
    void play(std::string title) {
        m_title = title;
        m_currentTrack = 0;
        std::cout << m_description << " playing \"" << m_title << "\"" << std::endl;
    }
    void play(int track) {
        if (m_title == "") {
            std::cout << m_description << " can't play track " << m_currentTrack << ", no cd inserted" << std::endl;
        } else {
            m_currentTrack = track;
            std::cout << m_description << " playing track " << m_currentTrack << std::endl;
        }
    }
    void stop() {
        m_currentTrack = 0;
        std::cout << m_description << " stopped" << std::endl;
    }
    void pause() {
        std::cout << m_description << " paused \"" << m_title << "\"" << std::endl;
    }
    std::string toString() {
        return m_description;
    }

private:
    std::string m_description;
    int m_currentTrack;
    Amplifier *m_amplifier;
    std::string m_title;
};

#endif // _CD_PLAYER_HPP_
