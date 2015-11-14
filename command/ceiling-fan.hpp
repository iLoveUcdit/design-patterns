#ifndef _CEILING_FAN_HPP_
#define _CEILING_FAN_HPP_

#include "command.hpp"

#include <string>
#include <iostream>

class CeilingFan {
public:
    static const int HIGH = 3;
    static const int MEDIUM = 2;
    static const int LOW = 1;
    static const int OFF = 0;

    CeilingFan(std::string location) {
        m_location = location;
        m_speed = OFF;
    }
    virtual ~CeilingFan() {}
    void high() {
        m_speed = HIGH;
        std::cout << m_location << " ceiling fan is on high" << std::endl;
    }
    void medium() {
        m_speed = MEDIUM;
        std::cout << m_location << " ceiling fan is on medium" << std::endl;
    }
    void low() {
        m_speed = LOW;
        std::cout << m_location << " ceiling fan is on low" << std::endl;
    }
    void off() {
        m_speed = OFF;
        std::cout << m_location << " ceiling fan is off" << std::endl;
    }
    int getSpeed() {
        return m_speed;
    }

private:
    std::string m_location;
    int m_speed;
};

class CeilingFanHighCommand : public Command {
public:
    CeilingFanHighCommand(CeilingFan *ceilingFan) {
        m_ceilingFan = ceilingFan;
    }
    virtual ~CeilingFanHighCommand() {}
    void execute() {
        m_prevSpeed = m_ceilingFan->getSpeed();
        m_ceilingFan->high();
    }
    void undo() {
        if (m_prevSpeed == CeilingFan::HIGH) {
            m_ceilingFan->high();
        } else if (m_prevSpeed == CeilingFan::MEDIUM) {
            m_ceilingFan->medium();
        } else if (m_prevSpeed == CeilingFan::LOW) {
            m_ceilingFan->low();
        } else if (m_prevSpeed == CeilingFan::OFF) {
            m_ceilingFan->off();
        }
    }
    std::string getName() {
        return "CeilingFanHighCommand";
    }

private:
    CeilingFan *m_ceilingFan;
    int m_prevSpeed;
};

class CeilingFanMediumCommand : public Command {
public:
    CeilingFanMediumCommand(CeilingFan *ceilingFan) {
        m_ceilingFan = ceilingFan;
    }
    virtual ~CeilingFanMediumCommand() {}
    void execute() {
        m_prevSpeed = m_ceilingFan->getSpeed();
        m_ceilingFan->medium();
    }
    void undo() {
        if (m_prevSpeed == CeilingFan::HIGH) {
            m_ceilingFan->high();
        } else if (m_prevSpeed == CeilingFan::MEDIUM) {
            m_ceilingFan->medium();
        } else if (m_prevSpeed == CeilingFan::LOW) {
            m_ceilingFan->low();
        } else if (m_prevSpeed == CeilingFan::OFF) {
            m_ceilingFan->off();
        }
    }
    std::string getName() {
        return "CeilingFanMediumCommand";
    }

private:
    CeilingFan *m_ceilingFan;
    int m_prevSpeed;
};

class CeilingFanLowCommand : public Command {
public:
    CeilingFanLowCommand(CeilingFan *ceilingFan) {
        m_ceilingFan = ceilingFan;
    }
    virtual ~CeilingFanLowCommand() {}
    void execute() {
        m_prevSpeed = m_ceilingFan->getSpeed();
        m_ceilingFan->low();
    }
    void undo() {
        if (m_prevSpeed == CeilingFan::HIGH) {
            m_ceilingFan->high();
        } else if (m_prevSpeed == CeilingFan::MEDIUM) {
            m_ceilingFan->medium();
        } else if (m_prevSpeed == CeilingFan::LOW) {
            m_ceilingFan->low();
        } else if (m_prevSpeed == CeilingFan::OFF) {
            m_ceilingFan->off();
        }
    }
    std::string getName() {
        return "CeilingFanLowCommand";
    }

private:
    CeilingFan *m_ceilingFan;
    int m_prevSpeed;
};

class CeilingFanOffCommand : public Command {
public:
    CeilingFanOffCommand(CeilingFan *ceilingFan) {
        m_ceilingFan = ceilingFan;
    }
    virtual ~CeilingFanOffCommand() {}
    void execute() {
        m_prevSpeed = m_ceilingFan->getSpeed();
        m_ceilingFan->off();
    }
    void undo() {
        if (m_prevSpeed == CeilingFan::HIGH) {
            m_ceilingFan->high();
        } else if (m_prevSpeed == CeilingFan::MEDIUM) {
            m_ceilingFan->medium();
        } else if (m_prevSpeed == CeilingFan::LOW) {
            m_ceilingFan->low();
        } else if (m_prevSpeed == CeilingFan::OFF) {
            m_ceilingFan->off();
        }
    }
    std::string getName() {
        return "CeilingFanOffCommand";
    }

private:
    CeilingFan *m_ceilingFan;
    int m_prevSpeed;
};

#endif // _CEILING_FAN_HPP_
