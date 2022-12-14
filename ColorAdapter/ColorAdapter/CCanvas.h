#pragma once
#include "ICanvas.h"

namespace graphics_lib
{

class CCanvas : public ICanvas
{
public:
	void SetColor(Color rgbColor) override;
	void MoveTo(int x, int y) override;
	void LineTo(int x, int y) override;
};

} // namespace graphics_lib
