#pragma once
#include "stdafx.h"

#include "CShape.h"
//class
struct IShapeFactory
{
	virtual ShapePtr CreateShape(const std::string& description) const = 0;
};
