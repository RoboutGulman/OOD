#include "stdafx.h"

#include "DecoyDuck.h"
#include "DuckFunctions.h"
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

    RubberDuck rubberDuck;
    PlayWithDuck(rubberDuck);

    DecoyDuck decoyDuck;
    PlayWithDuck(decoyDuck);

    ModelDuck modelDuck;
    PlayWithDuck(modelDuck);
    modelDuck.SetFlyBehavior(std::make_unique<FlyWithWings>());
    PlayWithDuck(modelDuck);
}
