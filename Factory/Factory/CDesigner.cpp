#include "stdafx.h"

#include "CDesigner.h"

CDesigner::CDesigner(std::unique_ptr<IShapeFactory> factoryPtr)
	: m_factoryPtr(std::move(factoryPtr))
{
}

CPictureDraft CDesigner::CreateDraft(std::istream& istream) const
{
	CPictureDraft draft;

	std::string description;
	while (std::getline(istream, description))
	{
		if (description == "end")
		{
			break;
		}
		if (description.empty())
		{
			continue;
		}
		draft.AddShape(m_factoryPtr->CreateShape(description));
	}

	return draft;
}
