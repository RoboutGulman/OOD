#include "stdafx.h"

#include "CCanvas.h"
#include "CCanvasPainter.h"
#include "CModernGraphicsRenderer.h"
#include "CModernGraphicsRendererAdapter.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "ICanvasDrawable.h"
#include "PaintPicture.h"

namespace app
{

void PaintPicture(shape_drawing_lib::CCanvasPainter& painter)
{
	using namespace shape_drawing_lib;

	ICanvasDrawableSharedPtr triangle = std::make_shared<CTriangle>(Point{ 10, 15 }, Point{ 100, 200 }, Point{ 150, 250 });
	ICanvasDrawableSharedPtr rectangle = std::make_shared<CRectangle>(Point{ 30, 40 }, 18, 24);

	painter.Draw(triangle);
	painter.Draw(rectangle);
}

void PaintPictureOnCanvas()
{
	graphics_lib::ICanvasPtr simpleCanvas = std::make_unique<graphics_lib::CCanvas>();
	shape_drawing_lib::CCanvasPainter painter(std::move(simpleCanvas));

	PaintPicture(painter);
}

void PaintPictureOnModernGraphicsRenderer()
{
	modern_graphics_lib::CModernGraphicsRenderer renderer(std::cout);

	renderer.BeginDraw();
	graphics_lib::ICanvasPtr simpleCanvas = std::make_unique<CModernGraphicsRendererAdapter>(renderer);

	shape_drawing_lib::CCanvasPainter painter(std::move(simpleCanvas));

	PaintPicture(painter);
}

} // namespace app
