#ifndef _ITERATOR_HPP_
#define _ITERATOR_HPP_

#include "menu-component.hpp"

#include <stack>
#include <vector>

class Iterator {
public:
    Iterator() {}
    virtual ~Iterator() {}
    virtual MenuComponent* next() = 0;
    virtual bool hasNext() = 0;
};

class NullIterator : public Iterator {
public:
    NullIterator() {}
    virtual ~NullIterator() {}
    MenuComponent* next() {
        return NULL;
    }
    bool hasNext() {
        return false;
    }
};

class VectorIterator : public Iterator {
public:
    VectorIterator(std::vector<MenuComponent*>* items) {
        m_items = items;
        m_position = 0;
    }
    virtual ~VectorIterator() {}
    MenuComponent *next() {
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
    std::vector<MenuComponent*>* m_items;
    size_t m_position;
};

class CompositeIterator : public Iterator {
public:
    CompositeIterator(Iterator* iterator) {
        m_stack.push(iterator);
    }
    virtual ~CompositeIterator() {
        while (hasNext()) {}
    }
    MenuComponent* next() {
        if (hasNext()) {
            Iterator* iterator = m_stack.top();
            MenuComponent* component = iterator->next();
            m_stack.push(component->createIterator());
            return component;
        } else {
            return NULL;
        }
    }
    bool hasNext() {
        if (m_stack.empty()) {
            return false;
        } else {
            Iterator* iterator = m_stack.top();
            if (!iterator->hasNext()) {
                delete m_stack.top();
                m_stack.pop();
                return hasNext();
            } else {
                return true;
            }
        }
    }

private:
    std::stack<Iterator*> m_stack;
};

#endif // _ITERATOR_HPP_
