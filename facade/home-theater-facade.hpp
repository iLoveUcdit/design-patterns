#ifndef _HOME_THEATER_FACADE_HPP_
#define _HOME_THEATER_FACADE_HPP_

#include "amplifier.hpp"
#include "tuner.hpp"
#include "dvd-player.hpp"
#include "cd-player.hpp"
#include "projector.hpp"
#include "screen.hpp"
#include "theater-lights.hpp"
#include "popcorn-popper.hpp"

#include <string>
#include <iostream>

class HomeTheaterFacade {
public:
    HomeTheaterFacade(Amplifier *amp,
                      Tuner *tuner,
                      DvdPlayer *dvd,
                      CdPlayer *cd,
                      Projector *projector,
                      Screen *screen,
                      TheaterLights *lights,
                      PopcornPopper *popper) {
        m_amp = amp;
        m_tuner = tuner;
        m_dvd = dvd;
        m_cd = cd;
        m_projector = projector;
        m_screen = screen;
        m_lights = lights;
        m_popper = popper;
    }
    virtual ~HomeTheaterFacade() {}
    void watchMovie(std::string movie) {
        std::cout << "Get ready to watch a movie..." << std::endl;
        m_popper->on();
        m_popper->pop();
        m_lights->dim(10);
        m_screen->down();
        m_projector->on();
        m_projector->wideScreenMode();
        m_amp->on();
        m_amp->setDvd(m_dvd);
        m_amp->setSurroundSound();
        m_amp->setVolume(5);
        m_dvd->on();
        m_dvd->play(movie);
    }
    void endMovie() {
        std::cout << "Shutting movie theater down..." << std::endl;
        m_popper->off();
        m_lights->on();
        m_screen->up();
        m_projector->off();
        m_amp->off();
        m_dvd->stop();
        m_dvd->eject();
        m_dvd->off();
    }
    void listenToCd(std::string cdTitle) {
        std::cout << "Get ready for an audiopile experence..." << std::endl;
        m_lights->on();
        m_amp->on();
        m_amp->setVolume(5);
        m_amp->setCd(m_cd);
        m_amp->setStereoSound();
        m_cd->on();
        m_cd->play(cdTitle);
    }
    void endCd() {
        std::cout << "Shutting down CD..." << std::endl;
        m_amp->off();
        m_amp->setCd(m_cd);
        m_cd->eject();
        m_cd->off();
    }
    void listenToRadio(double frequency) {
        std::cout << "Tuning in the airwaves..." << std::endl;
        m_tuner->on();
        m_tuner->setFrequency(frequency);
        m_amp->on();
        m_amp->setVolume(5);
        m_amp->setTuner(m_tuner);
    }
    void endRadio() {
        std::cout << "Shutting down the tuner..." << std::endl;
        m_tuner->off();
        m_amp->off();
    }

private:
    Amplifier *m_amp;
    Tuner *m_tuner;
    DvdPlayer *m_dvd;
    CdPlayer *m_cd;
    Projector *m_projector;
    TheaterLights *m_lights;
    Screen *m_screen;
    PopcornPopper *m_popper;
};

#endif // _HOME_THEATER_FACADE_HPP_
