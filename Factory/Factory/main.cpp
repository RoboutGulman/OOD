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
		CCanvas canvas;

		CPainter painter;
		//uniquePtr
		painter.DrawPicture(draft, std::make_shared<CCanvas>(canvas));
	}
	catch (std::exception& exception)
	{
		std::cout << exception.what() << std::endl;
		std::exit(1);
	}

	return 0;
}
