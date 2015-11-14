#ifndef _REMOTE_CONTROL_HPP_
#define _REMOTE_CONTROL_HPP_

#include "command.hpp"

#include <vector>
#include <string>
#include <sstream>

//
// This is the invoker
//

class RemoteControl {
public:
    static const int MAX_SLOT_NUM = 7;

    RemoteControl() {
        m_undoCommand = NULL;
        for(int i = 0; i < MAX_SLOT_NUM; ++i) {
            m_onCommands[i] = NULL;
            m_offCommands[i] = NULL;
        }
    }
    virtual ~RemoteControl() {}
    void setCommand(int slot, Command *onCommand, Command *offCommand) {
        if (0 <= slot && slot < MAX_SLOT_NUM) {
            m_onCommands[slot] = onCommand;
            m_offCommands[slot] = offCommand;
        }
    }
    void onButtonWasPushed(int slot) {
        if (0 <= slot && slot < MAX_SLOT_NUM && m_onCommands[slot] != NULL) {
            m_onCommands[slot]->execute();
            m_undoCommand = m_onCommands[slot];
        }
    }
    void offButtonWasPushed(int slot) {
        if (0 <= slot && slot < MAX_SLOT_NUM && m_offCommands[slot] != NULL) {
            m_offCommands[slot]->execute();
            m_undoCommand = m_offCommands[slot];
        }
    }
    void undoButtonWasPushed() {
        if (m_undoCommand != NULL) {
            m_undoCommand->undo();
        }
    }
    std::string toString() {
        std::stringstream out;
        out << "\n------ Remote Control -------\n";
        for (int i = 0; i < MAX_SLOT_NUM; ++i) {
            out << "[slot " << i << "] " << (m_onCommands[i] == NULL ? "NoCommand" : m_onCommands[i]->getName());
            out  << "    " << (m_offCommands[i] == NULL ? "NoCommand" : m_offCommands[i]->getName()) << "\n";
        }
        out << "[undo] " << (m_undoCommand == NULL ? "NoCommand" : m_undoCommand->getName()) << "\n";
        return out.str();
    }

private:
    Command *m_onCommands[MAX_SLOT_NUM];
    Command *m_offCommands[MAX_SLOT_NUM];
    Command *m_undoCommand;
};

#endif // _REMOTE_CONTROL_HPP_
