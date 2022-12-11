#pragma once
#include "CModernGraphicsRenderer.h"
#include "ICanvas.h"
#include "Point.h"

namespace app
{

class CModernGraphicsRendererAdapter : public graphics_lib::ICanvas
{
public:
	using Renderer = modern_graphics_lib::CModernGraphicsRenderer;

	CModernGraphicsRendererAdapter(Renderer& renderer);

	void MoveTo(int x, int y) override;
	void LineTo(int x, int y) override;

	~CModernGraphicsRendererAdapter();

private:
	Renderer& m_adaptee;
	modern_graphics_lib::Point m_currentPoint;
};

} // namespace app
