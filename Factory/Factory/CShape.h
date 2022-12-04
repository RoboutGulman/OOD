#pragma once
#include "stdafx.h"

#include "Color.h"
#include "IShape.h"
#include "Point.h"

class CShape : public IShape
{
public:
	Color GetColor() const
	{
		return m_color;
	}

protected:
	CShape(Point&& point, Color color)
		: m_basePoint(std::move(point))
		, m_color(color)
	{
	}

	Point GetBasePoint() const
	{
		return m_basePoint;
	}

private:
	// ���������� Point �� ������
	Point m_basePoint;
	Color m_color;
};
