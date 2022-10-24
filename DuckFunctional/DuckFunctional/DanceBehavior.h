#pragma once
#include "stdafx.h"

std::function<void()> DanceMinuetBehavior()
{
    return []() { std::cout << "I'm dancing minuet!!" << std::endl; };
}

std::function<void()> DanceWaltzBehavior()
{
    return []() { std::cout << "I'm dancing waltz!!" << std::endl; };
}

std::function<void()> DanceNoWayBehavior()
{
    return []() {};
}
