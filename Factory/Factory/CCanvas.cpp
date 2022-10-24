#include "stdafx.h"

#include "CCanvas.h"

void CCanvas::SetColor(Color color)
{
	std::cout << "Set color" << std::endl;
}

void CCanvas::DrawLine(const Point& from, const Point& to)
{
	std::cout << "Draw line" << std::endl;
}

void CCanvas::DrawEllipse(unsigned int l, unsigned int t, unsigned int width, unsigned int height)
{
	std::cout << "Draw ellipse" << std::endl;
}
