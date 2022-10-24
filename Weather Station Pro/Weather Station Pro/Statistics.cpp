#include "stdafx.h"

#include "Statistics.h"

std::ostream& operator<<(std::ostream& stream, WindAngleStatistics const& stat)
{
	stream << "average wind angle " << stat.GetAverage() << std::endl;
	stream << "----------------" << std::endl;

	return stream;
}
