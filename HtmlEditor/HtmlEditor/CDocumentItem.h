#pragma once
#include "IParagraph.h"

/* class CConstDocumentItem
{
public:
	std::shared_ptr<const IParagraph> GetParagraph() const;
	virtual ~CConstDocumentItem() = default;
};*/

class CDocumentItem 
{
public:
	CDocumentItem(ParagraphPtr item);
	ParagraphPtr GetParagraph();

private:
	ParagraphPtr m_item;
};
