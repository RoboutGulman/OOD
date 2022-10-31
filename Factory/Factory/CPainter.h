#pragma once
#include "CPictureDraft.h"
#include "CCanvas.h"

class CPainter
{
public:
	void DrawPicture(const CPictureDraft& draft, CanvasPtr canvas);
};
