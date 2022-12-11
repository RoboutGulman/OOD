#pragma once
#include "CModernGraphicsRenderer.h"
#include "ICanvas.h"
#include "Point.h"

namespace app
{

class CModernGraphicsRendererAdapter : public graphics_lib::ICanvas
	, public modern_graphics_lib::CModernGraphicsRenderer
{
public:
	CModernGraphicsRendererAdapter(std::ostream& os);

	void MoveTo(int x, int y) override;
	void LineTo(int x, int y) override;

	~CModernGraphicsRendererAdapter();

private:
	using Target = graphics_lib::ICanvas;
	using Adaptee = modern_graphics_lib::CModernGraphicsRenderer;

	modern_graphics_lib::Point m_currentPoint;
};

} // namespace app
