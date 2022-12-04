#pragma once
#include "ICanvas.h"
#include "ICanvasDrawable.h"

namespace shape_drawing_lib
{

class CCanvasPainter
{
public:
	using Canvas = graphics_lib::ICanvasPtr;

	CCanvasPainter(Canvas&& canvas);

	void Draw(const ICanvasDrawableSharedPtr& drawable);

private:
	Canvas m_canvas;
};

} // namespace shape_drawing_lib
