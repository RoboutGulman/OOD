#pragma once
#include "stdafx.h"

namespace graphics_lib
{
using Color = uint32_t;

class ICanvas
{
public:
	virtual void SetColor(Color rgbColor) = 0;
	virtual void MoveTo(int x, int y) = 0;
	virtual void LineTo(int x, int y) = 0;
};

using ICanvasPtr = std::unique_ptr<ICanvas>;

} // namespace graphics_lib
