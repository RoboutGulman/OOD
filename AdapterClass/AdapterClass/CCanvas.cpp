#include "stdafx.h"

#include "CCanvas.h"

namespace graphics_lib
{
void CCanvas::MoveTo(int x, int y)
{
	std::cout << "MoveTo (" << x << ", " << y << ")" << std::endl;
}
void CCanvas::LineTo(int x, int y)
{
	std::cout << "LineTo (" << x << ", " << y << ")" << std::endl;
}
} // namespace graphics_lib
