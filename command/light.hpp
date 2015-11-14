#ifndef _LIGHT_HPP_
#define _LIGHT_HPP_

#include "command.hpp"

#include <string>
#include <iostream>

class Light {
public:
    Light(std::string location) {
        m_location = location;
    }
    virtual ~Light() {}
    void on() {
        m_level = 100;
        std::cout << "Light is on" << std::endl;
    }
    void off() {
        m_level = 0;
        std::cout << "Light is off" << std::endl;
    }
    void dim(int level) {
        m_level = level;
        if (level == 0) {
            off();
        } else {
            std::cout << "Light is dimmed to " << level << "%" << std::endl;
        }
    }
    int getLevel() {
        return m_level;
    }

private:
    std::string m_location;
    int m_level;
};

class LightOffCommand : public Command {
public:
    LightOffCommand(Light *light) {
        m_light = light;
    }
    virtual ~LightOffCommand() {}
    void execute() {
        m_level = m_light->getLevel();
        m_light->off();
    }
    void undo() {
        m_light->dim(m_level);
    }
    std::string getName() {
        return "LightOffCommand";
    }

private:
    Light *m_light;
    int m_level;
};

class LightOnCommand : public Command {
public:
    LightOnCommand(Light *light) {
        m_light = light;
    }
    virtual ~LightOnCommand() {}
    void execute() {
        m_level = m_light->getLevel();
        m_light->on();
    }
    void undo() {
        m_light->dim(m_level);
    }
    std::string getName() {
        return "LightOnCommand";
    }

private:
    Light *m_light;
    int m_level;
};

class DimmerLightOffCommand : public Command {
public:
    DimmerLightOffCommand(Light *light) {
        m_light = light;
        m_prevLevel = 100;
    }
    virtual ~DimmerLightOffCommand() {}
    void execute() {
        m_prevLevel = m_light->getLevel();
        m_light->off();
    }
    void undo() {
        m_light->dim(m_prevLevel);
    }
    std::string getName() {
        return "DimmerLightOffCommand";
    }

private:
    Light *m_light;
    int m_prevLevel;
};

class DimmerLightOnCommand : public Command {
public:
    DimmerLightOnCommand(Light *light) {
        m_light = light;
    }
    virtual ~DimmerLightOnCommand() {}
    void execute() {
        m_prevLevel = m_light->getLevel();
        m_light->dim(75);
    }
    void undo() {
        m_light->dim(m_prevLevel);
    }
    std::string getName() {
        return "DimmerLightOnCommand";
    }

private:
    Light *m_light;
    int m_prevLevel;
};

#endif // _LIGHT_HPP_
