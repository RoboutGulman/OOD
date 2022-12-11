#include "stdafx.h"

#include "CModernGraphicsRendererAdapter.h"

namespace app
{

CModernGraphicsRendererAdapter::CModernGraphicsRendererAdapter(Renderer& renderer)
	: m_adaptee(renderer)
	, m_currentPoint(0, 0)
{
	m_adaptee.BeginDraw();
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
	m_adaptee.DrawLine(m_currentPoint, modern_graphics_lib::Point(x, y));

	MoveTo(x, y);
}

CModernGraphicsRendererAdapter::~CModernGraphicsRendererAdapter()
{
	m_adaptee.EndDraw();
}

} // namespace app
