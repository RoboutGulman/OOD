#include "stdafx.h"
#include "CRegularPolygon.h"
#define _USE_MATH_DEFINES
#include <math.h>

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

inline std::vector<Point> CreateRegularPolygonVertexes(const Point& center, unsigned int radius, unsigned int vertexCount)
{
	if (vertexCount < 3)
	{
		throw std::invalid_argument("Failed to create regular-polygon points. The number of vertices must be greater than 2");
	}

	double angle = 0.;
	double addAngle = 2 * M_PI / vertexCount;
	std::vector<Point> res{};
	res.reserve(vertexCount);

	for (size_t i = 0; i < vertexCount; ++i)
	{
		res.emplace_back(Point{
			static_cast<int>(std::round(radius * std::cos(angle))) + center.x,
			static_cast<int>(std::round(radius * std::sin(angle))) + center.y });
		angle += addAngle;
	}

	return res;
}

void CRegularPolygon::Draw(CanvasPtr canvas) const
{
	canvas->SetColor(GetColor());
	auto vetrexes = CreateRegularPolygonVertexes(GetCenter(), m_radius, m_vertex_count);
	for (int i = 1; i < vetrexes.size(); i++)
	{
		canvas->DrawLine(vetrexes[i - 1], vetrexes[i]);
	}
	canvas->DrawLine(vetrexes[vetrexes.size() - 1], vetrexes[0]);
}
