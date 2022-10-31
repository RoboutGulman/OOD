#include "stdafx.h"

#include "CShape.h"
#include "CTriangle.h"
#include "ICanvas.h"

CTriangle::CTriangle(Point&& v1, Point&& v2, Point&& v3, Color color)
	: CShape(std::forward<Point>(v1), color)
	, m_vertex2(std::forward<Point>(v2))
	, m_vertex3(std::forward<Point>(v3))
{
}

Point CTriangle::GetVertex1() const
{
	return GetBasePoint();
}

Point CTriangle::GetVertex2() const
{
	return m_vertex2;
}

Point CTriangle::GetVertex3() const
{
	return m_vertex3;
}

void CTriangle::Draw(CanvasPtr canvas) const
{
	canvas->SetColor(GetColor());
	canvas->DrawLine(GetVertex1(), GetVertex2());
	canvas->DrawLine(GetVertex1(), GetVertex3());
	canvas->DrawLine(GetVertex2(), GetVertex3());
}
