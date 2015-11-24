#ifndef _DVD_PLAYER_HPP_
#define _DVD_PLAYER_HPP_

#include <string>
#include <iostream>

class Amplifier;

class DvdPlayer {
public:
    DvdPlayer(std::string description, Amplifier *amplifier) {
        m_description = description;
        m_amplifier = amplifier;
    }
    virtual ~DvdPlayer() {}
    void on() {
        std::cout << m_description << " on" << std::endl;
    }
    void off() {
        std::cout << m_description << " off" << std::endl;
    }
    void eject() {
        m_movie = "";
        std::cout << m_description << " eject" << std::endl;
    }
    void play(std::string movie) {
        m_movie = movie;
        m_currentTrack = 0;
        std::cout << m_description << " playing \"" << m_movie << "\"" << std::endl;
    }
    void play(int track) {
        if (m_movie == "") {
            std::cout << m_description << " can't play track " << track << " no dvd inserted" << std::endl;
        } else {
            m_currentTrack = track;
            std::cout << m_description << " playing track " << m_currentTrack << " of \"" << m_movie << "\"" << std::endl;
        }
    }
    void stop() {
        m_currentTrack = 0;
        std::cout << m_description << " stopped \"" << m_movie << "\"" << std::endl;
    }
    void pause() {
        std::cout << m_description << " paused \"" << m_movie << "\"" << std::endl;
    }
    void setTwoChannelAudio() {
        std::cout << m_description << " set two channel audio" << std::endl;
    }
    void setSurroundAudio() {
        std::cout << m_description << " set surround audio" << std::endl;
    }
    std::string toString() {
        return m_description;
    }

private:
    std::string m_description;
    int m_currentTrack;
    Amplifier *m_amplifier;
    std::string m_movie;
};

#endif // _DVD_PLAYER_HPP_
