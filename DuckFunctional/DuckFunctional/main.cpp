#include "stdafx.h"

#include "DecoyDuck.h"
#include "DuckFunctions.h"
#include "FlyBehavior.h"
#include "MallardDuck.h"
#include "ModelDuck.h"
#include "RedheadDuck.h"
#include "RubberDuck.h"

int main()
{
    MallardDuck mallardDuck;
    PlayWithDuck(mallardDuck);

    RedheadDuck redheadDuck;
    PlayWithDuck(redheadDuck);
    redheadDuck.SetFlyBehavior(FlyBehavior());
    PlayWithDuck(redheadDuck);
    redheadDuck.SetFlyBehavior(FlyWithCountBehavior());
    PlayWithDuck(redheadDuck);

    RubberDuck rubberDuck;
    PlayWithDuck(rubberDuck);

    DecoyDuck decoyDuck;
    PlayWithDuck(decoyDuck);

    ModelDuck modelDuck;
    PlayWithDuck(modelDuck);
    modelDuck.SetFlyBehavior(FlyBehavior());
    PlayWithDuck(modelDuck);
}
