#pragma once

#include "stdafx.h"

enum class Color
{
	BLACK,
	BLUE,
	GREEN,
	PINK,
	RED,
	YELLOW,
	UNKNOWN
};

inline Color StringToColor(const std::string& str)
{
	if (str == "black")
	{
		return Color::BLACK;
	}
	if (str == "blue")
	{
		return Color::BLUE;
	}
	if (str == "green")
	{
		return Color::GREEN;
	}
	if (str == "pink")
	{
		return Color::PINK;
	}
	if (str == "red")
	{
		return Color::RED;
	}
	if (str == "yellow")
	{
		return Color::YELLOW;
	}
	return Color::UNKNOWN;
}
