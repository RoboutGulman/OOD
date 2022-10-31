#pragma once
#include "ICanvas.h"
class CCanvas : public ICanvas
{
public:
	CCanvas(std::ostream& output);
	void SetColor(Color color) override;
	void DrawLine(const Point& from, const Point& to) override;
	void DrawEllipse(unsigned int l, unsigned int t, unsigned int width, unsigned int height) override;

private:
	std::ostream& m_output;
};
