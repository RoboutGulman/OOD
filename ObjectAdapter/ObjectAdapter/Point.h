#pragma once

namespace modern_graphics_lib
{

class Point
{
public:
	Point(int x, int y)
		: x(x)
		, y(y)
	{
	}

	int x, y;
};

} // namespace modern_graphics_lib

namespace shape_drawing_lib
{

struct Point
{
	int x;
	int y;
};

} // namespace shape_drawing_lib
