#include "stdafx.h"

#include "CCanvas.h"

CCanvas::CCanvas(std::ostream& output)
	: m_output(output)
{
}

void CCanvas::SetColor(Color color)
{
	m_output << "Set color" << std::endl;
}

void CCanvas::DrawLine(const Point& from, const Point& to)
{
	m_output << "Draw line from {" << from.x << ',' << from.y << "} to {" << to.x << ',' << to.y << '}' << std::endl;
}

void CCanvas::DrawEllipse(unsigned int l, unsigned int t, unsigned int width, unsigned int height)
{
	m_output << "Draw ellipse with center in {" << l << ',' << t << "} width " << width << " height " << height << std::endl;
}
