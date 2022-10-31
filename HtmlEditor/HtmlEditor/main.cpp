#include "stdafx.h"
#include <math.h>
#include <corecrt_math_defines.h>

int main()
{
    std::cout << "Hello World!\n";
	int n = 4;
	int r = 5;
	int x = 0, y = 0;
	for (int i = 0; i < n; i++)
	{
		printf("%f %f\n", x + r * std::cos(2 * M_PI * i / n), y + r * std::sin(2 * M_PI * i / n));
	}
}

