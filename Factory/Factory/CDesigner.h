#pragma once
#include "IDesigner.h"
#include "IShapeFactory.h"

class CDesigner : public IDesigner
{
public:
	CDesigner(std::unique_ptr<IShapeFactory> factoryPtr);
	CPictureDraft CreateDraft(std::istream&) const;

private:
	std::unique_ptr<IShapeFactory> m_factoryPtr;
};
