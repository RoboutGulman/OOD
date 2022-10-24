#pragma once
#include "CPictureDraft.h"
#include "CCanvas.h"

class CPainter
{
public:
	void DrawPicture(const CPictureDraft& draft, const std::shared_ptr<ICanvas>& canvas);
};
