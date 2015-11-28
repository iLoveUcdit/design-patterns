#include "menu.hpp"
#include "waitress.hpp"

int main() {

    PancakeHouseMenu* pancakeHouseMenu = new PancakeHouseMenu();
    DinerMenu* dinerMenu = new DinerMenu();

    Waitress* waitress = new Waitress(pancakeHouseMenu, dinerMenu);

    waitress->printMenu();

    delete pancakeHouseMenu;
    delete dinerMenu;

    delete waitress;

    return 0;
}

