#pragma once
#include "CShape.h"
#include "IShapeFactory.h"

class CShapeFactory : public IShapeFactory
{
public:
	ShapePtr CreateShape(const std::string& description) const override;
};
