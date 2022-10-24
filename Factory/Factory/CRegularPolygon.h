#pragma once
#include "CShape.h"
#include "ICanvas.h"

class CRegularPolygon : public CShape
{
public:
	CRegularPolygon(Point center, unsigned int radius, unsigned int vertexCount, Color color);
	Point GetCenter() const;
	unsigned int GetRadius() const;
	unsigned int GetVertexCount() const;

	void Draw(const std::shared_ptr<ICanvas>& canvas) const;

private:
	unsigned int m_radius;
	unsigned int m_vertex_count;
};
