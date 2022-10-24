#pragma once
struct Point
{
	Point(unsigned int x = 0, unsigned int y = 0)
		: x(x)
		, y(y)
	{
	}

	bool operator==(const Point& other) const noexcept
	{
		return x == other.x && y == other.y;
	}

	unsigned int x;
	unsigned int y;
};

inline std::istream& operator>>(std::istream& stream, Point& point)
{
	unsigned int x, y;

	if (stream >> x >> y)
	{
		point.x = x;
		point.y = y;
	}
	else
	{
		stream.setstate(std::ios_base::failbit | stream.rdstate());
	}

	return stream;
}
