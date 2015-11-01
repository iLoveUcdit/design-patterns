#include "duck.hpp"
#include "fly-behavior.hpp"

int main() {

    MallardDuck *mallard = new MallardDuck();
    RubberDuck *rubberDuckie = new RubberDuck();
    DecoyDuck *decoy = new DecoyDuck();

    mallard->performQuack();
    rubberDuckie->performQuack();
    decoy->performQuack();

    delete mallard;
    delete rubberDuckie;
    delete decoy;

    Duck *model = new ModelDuck();

    model->performFly();
    model->setFlyBehavior(new FlyRocketPowered());
    // TODO
    // The new instance of FlyRocketPowered will free in model.
    model->performFly();

    delete model;

    return 0;
}
