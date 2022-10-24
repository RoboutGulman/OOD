#pragma once

#include "stdafx.h"

enum class ShapeType
{
	RECTANGLE,
	TRIANGLE,
	ELLIPSE,
	REGULAR_POLYGON,
	UNKNOWN,
};

inline ShapeType StringToShapeType(const std::string& str)
{
	if (str == "rectangle")
	{
		return ShapeType::RECTANGLE;
	}
	if (str == "triangle")
	{
		return ShapeType::TRIANGLE;
	}
	if (str == "ellipse")
	{
		return ShapeType::ELLIPSE;
	}
	if (str == "regular-polygon")
	{
		return ShapeType::REGULAR_POLYGON;
	}
	return ShapeType::UNKNOWN;
}
