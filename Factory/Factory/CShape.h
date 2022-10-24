#pragma once
#include "stdafx.h"

#include "Color.h"
#include "Point.h"
#include "IShape.h"

class CShape: public IShape
{
public:
	Color GetColor() const
	{
		return m_color;
	}

	Point GetBasePoint() const
	{
		return m_basePoint;
	}

protected:
	CShape(Point point, Color color)
		: m_basePoint(point)
		, m_color(color)
	{
	}

private:
	//передавать Point по ссылке
	Point m_basePoint;
	Color m_color;
};


