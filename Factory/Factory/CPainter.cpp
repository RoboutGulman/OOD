#include "stdafx.h"
#include "CPainter.h"

void CPainter::DrawPicture(const CPictureDraft& draft, const std::shared_ptr<ICanvas>& canvas)
{
	for (int i = 0; i < draft.GetShapeCount(); i++)
	{
		auto shape = draft.GetShape(i);
		shape->Draw(canvas);
	}
}
