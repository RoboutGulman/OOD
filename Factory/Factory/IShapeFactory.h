#pragma once
#include "stdafx.h"

#include "CShape.h"
// class
class IShapeFactory
{
public:
	virtual ShapePtr CreateShape(const std::string& description) const = 0;
};
