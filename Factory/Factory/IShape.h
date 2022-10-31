#pragma once
#include "Color.h"
#include "ICanvas.h"
#include "Point.h"
class IShape
{
public:
	virtual Color GetColor() const = 0;
	virtual void Draw(CanvasPtr canvas) const = 0;
	// ������ ���� �����
};

using ShapePtr = std::shared_ptr<IShape>;
