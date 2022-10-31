#pragma once
#include "CShape.h"
#include "ICanvas.h"
#include "Point.h"

class CEllipse : public CShape
{
public:
	CEllipse(Point&& basePoint, unsigned int verticalR, unsigned int horizontalR, Color color);

	Point GetCenter() const;
	unsigned int GetVerticalRadius() const;
	unsigned int GetHorizontalRadius() const;

	void Draw(const std::shared_ptr<ICanvas>& canvas) const;

private:
	unsigned int m_verticalR, m_horizontalR;
};
