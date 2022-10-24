#include "stdafx.h"

#include "CPictureDraft.h"
#include "IShape.h"

void CPictureDraft::AddShape(ShapePtr&& ptr)
{
	m_shapes.emplace_back(ptr);
}

size_t CPictureDraft::GetShapeCount() const
{
	return m_shapes.size();
}

//убрать &
const ShapePtr& CPictureDraft::GetShape(size_t index) const
{
	if (index >= m_shapes.size())
	{
		throw std::out_of_range("Failed to find shape. Given index is out of range");
	}

	return m_shapes[index];
}
