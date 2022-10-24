#include "stdafx.h"

#include "CRectangle.h"
#include "CShape.h"
#include "ICanvas.h"

CRectangle::CRectangle(Point leftTop, unsigned int width, unsigned int height, Color color)
	: CShape(leftTop, color)
	, m_rightBottom(leftTop.x + width, leftTop.y + height)
{
	if (width < 0 || height < 0)
	{
		throw std::invalid_argument("Width and height cannot be negative");
	}
}

Point CRectangle::GetLeftTop() const
{
	return GetBasePoint();
}

Point CRectangle::GetRightBottom() const
{
	return m_rightBottom;
}

void CRectangle::Draw(const std::shared_ptr<ICanvas>& canvas) const
{
	auto leftTop = GetLeftTop();
	auto rightBottom = GetRightBottom();

	auto rightTop = Point{ rightBottom.x, leftTop.y };
	auto leftBottom = Point{ leftTop.x, rightBottom.y };

	canvas->SetColor(GetColor());
	canvas->DrawLine(leftTop, rightTop);
	canvas->DrawLine(leftTop, leftBottom);
	canvas->DrawLine(rightTop, rightBottom);
	canvas->DrawLine(leftBottom, rightBottom);
}
