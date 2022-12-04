#pragma once
#include "ICanvasDrawable.h"
#include "Point.h"
namespace shape_drawing_lib
{

class CTriangle : public ICanvasDrawable
{
public:
	CTriangle(const Point& p1, const Point& p2, const Point& p3);

	void Draw(const Canvas& canvas) const override;

private:
	Point m_p1, m_p2, m_p3;
};

} // namespace shape_drawing_lib
