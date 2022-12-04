#include "stdafx.h"

#include "CDesigner.h"
#include "CShapeFactory.h"
#include "CPainter.h"

int main()
{
	try
	{
		CShapeFactory factory;
		CDesigner designer(std::make_unique<CShapeFactory>(factory));
		auto draft = designer.CreateDraft(std::cin);
		CCanvas canvas(std::cout);

		CPainter painter;
		//uniquePtr
		painter.DrawPicture(draft, std::make_unique<CCanvas>(canvas));
	}
	catch (std::exception& exception)
	{
		std::cout << exception.what() << std::endl;
		return 1;
	}

	return 0;
}

/*
 #include <math.h>
#include <corecrt_math_defines.h>
 int n = 4;
	int r = 5;
	int x = 0, y = 0;
	for (int i = 0; i < n; i++)
	{
		printf("%f %f\n", x + r * std::cos(2 * M_PI * i / n), y + r * std::sin(2 * M_PI * i / n));
	}
*/
