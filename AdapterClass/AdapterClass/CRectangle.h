#pragma once
#include "ICanvasDrawable.h"
#include "Point.h"

namespace shape_drawing_lib
{

class CRectangle : public ICanvasDrawable
{
public:
	CRectangle(const Point& leftTop, int width, int height);

	void Draw(const Canvas& canvas) const override;

private:
	Point m_leftTop;
	int m_width, m_height;
};

} // namespace shape_drawing_lib
