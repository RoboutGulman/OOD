#pragma once
#include "stdafx.h"

std::function<void()> FlyBehavior()
{
    return []() { std::cout << "I'm flying with wings!" << std::endl; };
}

// как подсчитывать количество полётов
std::function<void()> FlyWithCountBehavior()
{
    return [flightCount = 0]() mutable -> void {
        ++flightCount;
        std::cout << "I'm flying with wings! This is the " << flightCount << " flight" << std::endl;
    };
}

std::function<void()> FlyNoWayBehavior()
{
    return []() {};
}
