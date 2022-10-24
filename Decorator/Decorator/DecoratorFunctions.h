#pragma once
#include "Beverages.h"
#include "Condiments.h"
#include "IBeverage.h"

template <typename Condiment, typename... Args>
auto MakeCondiment(const Args &...args)
{
    // Возвращаем функцию, декорирующую напиток, переданный ей в качестве аргумента
    // Дополнительные аргументы декоратора, захваченные лямбда-функцией, передаются
    // конструктору декоратора через make_unique
    return [=](auto &&b) {
        // Функции make_unique передаем b вместе со списком аргументов внешней функции
        return make_unique<Condiment>(forward<decltype(b)>(b), args...);
    };
}

template <typename Component, typename Decorator>
auto operator<<(Component &&component, const Decorator &decorate)
{
    return decorate(forward<Component>(component));
}

void DialogWithUser()
{
    std::cout << "Type 1 for coffee or 2 for tea\n";
    int beverageChoice;
    std::cin >> beverageChoice;

    std::unique_ptr<IBeverage> beverage;

    if (beverageChoice == 1)
    {
        beverage = std::make_unique<CCoffee>();
    }
    else if (beverageChoice == 2)
    {
        beverage = std::make_unique<CTea>(TeaSort::Indian);
    }
    else
    {
        return;
    }

    int condimentChoice;
    for (;;)
    {
        std::cout << "1 - Lemon, 2 - Cinnamon, 0 - Checkout" << std::endl;
        std::cin >> condimentChoice;

        if (condimentChoice == 1)
        {
            // beverage = make_unique<CLemon>(move(beverage));
            beverage = move(beverage) << MakeCondiment<CLemon>(2);
        }
        else if (condimentChoice == 2)
        {
            // beverage = make_unique<CCinnamon>(move(beverage));
            beverage = move(beverage) << MakeCondiment<CCinnamon>();
        }
        else if (condimentChoice == 0)
        {
            break;
        }
        else
        {
            return;
        }
    }

    std::cout << beverage->GetDescription() << ", cost: " << beverage->GetCost() << std::endl;
}
