#pragma once
#include "CShape.h"

class CPictureDraft
{
public:
	void AddShape(ShapePtr&& ptr);

	size_t GetShapeCount() const;
	const ShapePtr GetShape(size_t index) const;

private:
	std::vector<ShapePtr> m_shapes;
};
