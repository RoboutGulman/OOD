#include "stdafx.h"

#include "CRectangle.h"

namespace shape_drawing_lib
{

CRectangle::CRectangle(const Point& leftTop, int width, int height)
	: m_leftTop(leftTop)
	, m_width(width)
	, m_height(height)
{
	if (m_width < 0 || m_height < 0)
	{
		throw std::invalid_argument("Failed to create rectangle. Given sides are negative");
	}
}

void CRectangle::Draw(const Canvas& canvas) const
{
	auto rightBottom = Point{ m_leftTop.x + m_width, m_leftTop.y - m_height };
	auto rightTop = Point{ rightBottom.x, m_leftTop.y };
	auto leftBottom = Point{ m_leftTop.x, rightBottom.y };

	canvas->MoveTo(m_leftTop.x, m_leftTop.y);

	canvas->LineTo(rightTop.x, rightTop.y);
	canvas->LineTo(rightBottom.x, rightBottom.y);
	canvas->LineTo(leftBottom.x, leftBottom.y);
	canvas->LineTo(m_leftTop.x, m_leftTop.y);
}

} // namespace shape_drawing_lib
