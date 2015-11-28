#ifndef _ITERATOR_HPP_
#define _ITERATOR_HPP_

#include "menu-item.hpp"

#include <list>
#include <vector>

class Iterator {
public:
    Iterator() {}
    virtual ~Iterator() {}
    virtual bool hasNext() = 0;
    virtual MenuItem* next() = 0;
};

class DinerMenuIterator : public Iterator {
public:
    DinerMenuIterator(std::list<MenuItem*>* items) {
        m_items = items;
        m_position = (*items).begin();
    }
    virtual ~DinerMenuIterator() {}
    MenuItem *next() {
        if (hasNext()) {
            MenuItem* menuItem = *m_position;
            ++m_position;
            return menuItem;
        } else {
            return NULL;
        }
    }
    bool hasNext() {
        return m_position != (*m_items).end();
    }

private:
    std::list<MenuItem*>* m_items;
    std::list<MenuItem*>::iterator m_position;
};

class PancakeHouseMenuIterator : public Iterator {
public:
    PancakeHouseMenuIterator(std::vector<MenuItem*>* items) {
        m_items = items;
        m_position = 0;
    }
    virtual ~PancakeHouseMenuIterator() {}
    MenuItem *next() {
        if (hasNext()) {
            return (*m_items)[m_position++];
        } else {
            return NULL;
        }
    }
    bool hasNext() {
        return m_position < (*m_items).size();
    }

private:
    std::vector<MenuItem*>* m_items;
    size_t m_position;
};

#endif // _ITERATOR_HPP_
