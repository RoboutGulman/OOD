#pragma once
#include "Point.h"
#include "RGBAColor.h"

namespace modern_graphics_lib
{

class CModernGraphicsRenderer
{
public:
	CModernGraphicsRenderer(std::ostream& strm);
	~CModernGraphicsRenderer();

	void BeginDraw();
	void DrawLine(const Point& start, const Point& end, const RGBAColor& color);
	void EndDraw();

private:
	std::ostream& m_out;
	bool m_drawing = false;
};

} // namespace modern_graphics_lib
