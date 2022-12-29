#include "stdafx.h"

#include "CModernGraphicsRendererAdapter.h"

namespace app
{

CModernGraphicsRendererAdapter::CModernGraphicsRendererAdapter(Renderer& renderer)
	: m_adaptee(renderer)
	, m_currentPoint(0, 0)
	, m_rgbaColor(0, 0, 0, 1)
{
	m_adaptee.BeginDraw();
}

void CModernGraphicsRendererAdapter::SetColor(Color rgbColor)
{
	auto red = float(rgbColor & 0xFF) / 255;
	auto green = float((rgbColor >> 8) & 0xFF) / 255;
	auto blue = float((rgbColor >> 16) & 0xFF) / 255;

	m_rgbaColor = { red, green, blue, 1 };
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
	m_adaptee.DrawLine(m_currentPoint, modern_graphics_lib::Point(x, y), m_rgbaColor);

	MoveTo(x, y);
}

CModernGraphicsRendererAdapter::~CModernGraphicsRendererAdapter()
{
	m_adaptee.EndDraw();
}

} // namespace app
