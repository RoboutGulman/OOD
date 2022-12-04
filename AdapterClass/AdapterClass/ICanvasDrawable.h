#pragma once
#include "ICanvas.h"

namespace shape_drawing_lib
{

class ICanvasDrawable
{
public:
	using Canvas = graphics_lib::ICanvasPtr;

	virtual void Draw(const Canvas& canvas) const = 0;
};

using ICanvasDrawableSharedPtr = std::shared_ptr<ICanvasDrawable>;

} // namespace shape_drawing_lib
