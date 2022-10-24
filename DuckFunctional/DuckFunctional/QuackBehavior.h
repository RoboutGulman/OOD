#pragma once
#include "stdafx.h"

std::function<void()> QuackBehavior()
{
    return []() { std::cout << "Quack Quack!!!" << std::endl; };
}

std::function<void()> SqueekBehavior()
{
    return []() { std::cout << "Squeek!!!" << std::endl; };
}

std::function<void()> MuteBehavior()
{
    return []() {};
}
