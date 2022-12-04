#pragma once
#include "stdafx.h"

namespace graphics_lib
{

class ICanvas
{
public:
	virtual void MoveTo(int x, int y) = 0;
	virtual void LineTo(int x, int y) = 0;
};

using ICanvasPtr = std::unique_ptr<ICanvas>;

} // namespace graphics_lib
