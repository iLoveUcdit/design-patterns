#include "amplifier.hpp"
#include "tuner.hpp"
#include "dvd-player.hpp"
#include "cd-player.hpp"
#include "projector.hpp"
#include "screen.hpp"
#include "theater-lights.hpp"
#include "popcorn-popper.hpp"
#include "home-theater-facade.hpp"

int main() {

    Amplifier *amp = new Amplifier("Top-O-Line Amplifier");
    Tuner *tuner = new Tuner("Top-O-Line AM/FM Tuner", amp);
    DvdPlayer *dvd = new DvdPlayer("Top-O-Line DVD Player", amp);
    CdPlayer *cd = new CdPlayer("Top-O-Line CD Player", amp);
    Projector *projector = new Projector("Top-O-Line Projector", dvd);
    TheaterLights *lights = new TheaterLights("Theater Ceiling Lights");
    Screen *screen = new Screen("Theater Screen");
    PopcornPopper *popper = new PopcornPopper("Popcorn Popper");

    HomeTheaterFacade *homeTheater = new HomeTheaterFacade(amp, tuner, dvd, cd, projector, screen, lights, popper);

    homeTheater->watchMovie("Raiders of the Lost Ark");
    homeTheater->endMovie();

    delete amp;
    delete tuner;
    delete dvd;
    delete cd;
    delete projector;
    delete lights;
    delete screen;
    delete popper;

    delete homeTheater;

    return 0;
}
