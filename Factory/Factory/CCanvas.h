#pragma once
#include "ICanvas.h"
class CCanvas : public ICanvas
{
public:
	void SetColor(Color color) override;
	void DrawLine(const Point& from, const Point& to) override;
	void DrawEllipse(unsigned int l, unsigned int t, unsigned int width, unsigned int height) override;
};
