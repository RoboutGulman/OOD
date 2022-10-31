#include "stdafx.h"

#include "CEllipse.h"
#include "CShape.h"
#include "ICanvas.h"
#include "Point.h"

CEllipse::CEllipse(Point&& basePoint, unsigned int verticalR, unsigned int horizontalR, Color color)
	: CShape(std::forward<Point>(basePoint), color)
	, m_verticalR(verticalR)
	, m_horizontalR(horizontalR)
{
	if (m_verticalR < 0 || m_horizontalR < 0)
	{
		throw std::invalid_argument("Ellipse radius cannot be negative");
	}
}

Point CEllipse::GetCenter() const
{
	return GetBasePoint();
}

unsigned int CEllipse::GetVerticalRadius() const
{
	return m_verticalR;
}

unsigned int CEllipse::GetHorizontalRadius() const
{
	return m_horizontalR;
}

void CEllipse::Draw(const std::shared_ptr<ICanvas>& canvas) const
{
	auto center = GetCenter();
	canvas->SetColor(GetColor());
	canvas->DrawEllipse(center.x, center.y, GetVerticalRadius(), GetHorizontalRadius());
}
