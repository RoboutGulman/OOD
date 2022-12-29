#include "stdafx.h"

#include "CModernGraphicsRendererAdapter.h"

namespace app
{

CModernGraphicsRendererAdapter::CModernGraphicsRendererAdapter(Renderer& renderer)
	: m_adaptee(renderer)
	, m_currentPoint(0, 0)
{
	// �������� BeginDraw �� ������� ����
}

void CModernGraphicsRendererAdapter::MoveTo(int x, int y)
{
	// �� ������ ������ ��� ������� �������
	m_currentPoint.x = x;
	m_currentPoint.y = y;
}

void CModernGraphicsRendererAdapter::LineTo(int x, int y)
{
	// �������� ������
	m_adaptee.DrawLine(m_currentPoint, modern_graphics_lib::Point(x, y));

	MoveTo(x, y);
}

} // namespace app
