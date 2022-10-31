#pragma once
#include "CShape.h"
#include "ICanvas.h"

class CRectangle : public CShape
{
public:
	CRectangle(Point&& leftTop, unsigned int width, unsigned int height, Color color);

	Point GetLeftTop() const;
	Point GetRightBottom() const;

	void Draw( CanvasPtr canvas) const;

private:
	Point m_rightBottom;
};
