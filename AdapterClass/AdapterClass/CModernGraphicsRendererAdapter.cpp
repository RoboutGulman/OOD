#include "stdafx.h"

#include "CModernGraphicsRendererAdapter.h"

namespace app
{

CModernGraphicsRendererAdapter::CModernGraphicsRendererAdapter(std::ostream& os)
	: Adaptee(os)
	, m_currentPoint(0, 0)
{
	BeginDraw();
}

void CModernGraphicsRendererAdapter::MoveTo(int x, int y)
{
	// не должно падать при двойном запуске

	m_currentPoint.x = x;
	m_currentPoint.y = y;
}

void CModernGraphicsRendererAdapter::LineTo(int x, int y)
{
	// изменить логику
	DrawLine(m_currentPoint, modern_graphics_lib::Point(x, y));

	m_currentPoint.x = x;
	m_currentPoint.y = y;
}

CModernGraphicsRendererAdapter::~CModernGraphicsRendererAdapter()
{
	EndDraw();
}

} // namespace app
