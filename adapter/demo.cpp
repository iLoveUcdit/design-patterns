#include "duck.hpp"
#include "turkey.hpp"
#include "duck-adapter.hpp"
#include "turkey-adapter.hpp"

#include <iostream>

static void testDuck(Duck *duck) {
    duck->quack();
    duck->fly();
}

static void testTurkey(Turkey *turkey) {
    turkey->gobble();
    turkey->fly();
}

static void duckTestDrive() {
    MallardDuck *duck = new MallardDuck();

    WildTurkey *turkey = new WildTurkey();
    Duck *turkeyAdapter = new TurkeyAdapter(turkey);

    std::cout << "The Turkey says..." << std::endl;
    turkey->gobble();
    turkey->fly();

    std::cout << "\nThe Duck says..." << std::endl;
    testDuck(duck);

    std::cout << "\nThe TurkeyAdapter says..." << std::endl;
    testDuck(turkeyAdapter);

    delete turkeyAdapter;
    delete turkey;

    delete duck;
}

static void turkeyTestDrive() {
    MallardDuck *duck = new MallardDuck();
    Turkey *duckAdapter = new DuckAdapter(duck);

    for(int i = 0; i < 10; ++i) {
        std::cout << "The DuckAdapter says..." << std::endl;
        testTurkey(duckAdapter);
    }

    delete duckAdapter;
    delete duck;
}

int main() {

    duckTestDrive();
    turkeyTestDrive();

    return 0;
}
