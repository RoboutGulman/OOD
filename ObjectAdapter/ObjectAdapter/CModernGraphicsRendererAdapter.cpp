#include "stdafx.h"

#include "CModernGraphicsRendererAdapter.h"

namespace app
{

CModernGraphicsRendererAdapter::CModernGraphicsRendererAdapter(Renderer& renderer)
	: m_adaptee(renderer)
	, m_currentPoint(0, 0)
	, m_drawing(false)
{
}

void CModernGraphicsRendererAdapter::MoveTo(int x, int y)
{
	// не должно падать при двойном запуске
	if (!m_drawing)
	{
		m_adaptee.BeginDraw();
		m_drawing = true;
	}

	m_currentPoint.x = x;
	m_currentPoint.y = y;
}

void CModernGraphicsRendererAdapter::LineTo(int x, int y)
{
	// изменить логику
	if (!m_drawing)
	{
		MoveTo(m_currentPoint.x, m_currentPoint.y);
	}

	m_adaptee.DrawLine(m_currentPoint, modern_graphics_lib::Point(x, y));
	m_currentPoint = modern_graphics_lib::Point(x, y);
	m_adaptee.EndDraw();

	m_drawing = false;
}

} // namespace app
