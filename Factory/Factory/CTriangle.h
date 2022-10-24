#pragma once
#include "CShape.h"
#include "ICanvas.h"

class CTriangle : public CShape
{
public:
	CTriangle(Point v1, Point v2, Point v3, Color color);

	Point GetVertex1() const;
	Point GetVertex2() const;
	Point GetVertex3() const;

	void Draw(const std::shared_ptr<ICanvas>& canvas) const;

private:
	Point m_vertex2, m_vertex3;
};
