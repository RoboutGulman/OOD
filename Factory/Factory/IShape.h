#pragma once
#include "Color.h"
#include "Point.h"
#include "ICanvas.h"
class IShape
{
public:
	virtual Color GetColor() const = 0;
	virtual void Draw(const std::shared_ptr<ICanvas>& canvas) const = 0;
	//убрать этот метод
	virtual Point GetBasePoint() const = 0;
};

using ShapePtr = std::shared_ptr<IShape>;
