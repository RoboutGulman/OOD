#include "stdafx.h"

#include "CCanvasPainter.h"

namespace shape_drawing_lib
{

CCanvasPainter::CCanvasPainter(Canvas&& canvas)
	: m_canvas(std::move(canvas))
{
	if (m_canvas == nullptr)
	{
		throw std::invalid_argument("Failed to create CanvasPainter, invalid canvas was given");
	}
}

void CCanvasPainter::Draw(const ICanvasDrawableSharedPtr& drawable)
{
	if (drawable == nullptr)
	{
		throw std::invalid_argument("Failed to draw drawable, invalid drawable was given");
	}

	drawable->Draw(m_canvas);
}

} // namespace shape_drawing_lib
