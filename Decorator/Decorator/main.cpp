#include "stdafx.h"

#include "Beverages.h"
#include "Condiments.h"
#include "DecoratorFunctions.h"

int main()
{
    {
        auto beverage = std::make_unique<CLatte>(LattePortion::DoublePortion)
                        << MakeCondiment<CSyrup>(SyrupType::Chocolate) << MakeCondiment<CCoconutFlakes>(1);

        std::cout << beverage->GetDescription() << " costs " << beverage->GetCost() << '\n';
    }

    {
        auto beverage = std::make_unique<CCappuccino>(CappuccinoPortion::DoublePortion);

        std::cout << beverage->GetDescription() << " costs " << beverage->GetCost() << '\n';
    }

    {
        auto beverage = std::make_unique<CCappuccino>(CappuccinoPortion::Standart);

        std::cout << beverage->GetDescription() << " costs " << beverage->GetCost() << '\n';
    }

    {
        auto beverage = std::make_unique<CTea>(TeaSort::EarlGrey);

        std::cout << beverage->GetDescription() << " costs " << beverage->GetCost() << '\n';
    }

    {
        auto beverage = std::make_unique<CMilkshake>(MilkShakePortion::Large);

        std::cout << beverage->GetDescription() << " costs " << beverage->GetCost() << '\n';
    }
    {
        auto beverage = std::make_unique<CLatte>(LattePortion::DoublePortion)
                        << MakeCondiment<CCream>() << MakeCondiment<CChocolate>(4)
                        << MakeCondiment<CLiquor>(LiquorType::Nut);

        std::cout << beverage->GetDescription() << " costs " << beverage->GetCost() << '\n';
    }
}
