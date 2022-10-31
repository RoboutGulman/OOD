#include "stdafx.h"
#include "CRegularPolygon.h"

CRegularPolygon::CRegularPolygon(Point&& center, unsigned int radius, unsigned int vertexCount, Color color)
	: CShape(std::forward<Point>(center), color)
	, m_radius(radius)
	, m_vertex_count(vertexCount)
{
}

Point CRegularPolygon::GetCenter() const
{
	return GetBasePoint();
}

unsigned int CRegularPolygon::GetRadius() const
{
	return m_radius;
}

unsigned int CRegularPolygon::GetVertexCount() const
{
	return m_vertex_count;
}

void CRegularPolygon::Draw(const std::shared_ptr<ICanvas>& canvas) const
{
	canvas->SetColor(GetColor());
}
