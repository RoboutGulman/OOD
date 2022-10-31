#pragma once
struct Point
{
	Point(int x = 0, int y = 0)
		: x(x)
		, y(y)
	{
	}

	bool operator==(const Point& other) const noexcept
	{
		return x == other.x && y == other.y;
	}

	int x;
	int y;
};

inline std::istream& operator>>(std::istream& stream, Point& point)
{
	int x, y;

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
