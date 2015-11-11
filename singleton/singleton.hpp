// TODO
// NOTE: This is not thread safe!

#ifndef _SINGLETON_HPP_
#define _SINGLETON_HPP_

#include <string>

class Singleton {
public:
    virtual ~Singleton() {}
    static Singleton &getInstance() {
        static Singleton sm_uniqueInstance;
        return sm_uniqueInstance;
    }
    std::string getDescription() {
        return "I'm a classic Singleton!";
    }

private:
    Singleton() {}
    Singleton(const Singleton &);
    void operator= (const Singleton &);

};

#endif // _SINGLETON_HPP_
