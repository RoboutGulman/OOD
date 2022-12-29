#include "stdafx.h"

#include "CCanvas.h"

namespace graphics_lib
{

void ChangeOStream(std::ostream& os, size_t width, char fillSymb, decltype(std::hex) iosBase)
{
	os << std::setw(width) << std::setfill(fillSymb) << iosBase;
}

void CCanvas::SetColor(Color rgbColor)
{
	std::cout << "SetColor #";

	const auto savedFill = std::cout.fill();
	ChangeOStream(std::cout, 6, '0', std::hex);

	std::cout << rgbColor << std::endl;

	ChangeOStream(std::cout, 0, savedFill, std::dec);
}
void CCanvas::MoveTo(int x, int y)
{
	std::cout << "MoveTo (" << x << ", " << y << ")" << std::endl;
}
void CCanvas::LineTo(int x, int y)
{
	std::cout << "LineTo (" << x << ", " << y << ")" << std::endl;
}
} // namespace graphics_lib
