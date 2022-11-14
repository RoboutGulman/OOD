#pragma once
#include "IParagraph.h"

class CDocumentItem 
{
public:
	CDocumentItem(ParagraphPtr item);
	ParagraphPtr GetParagraph();

private:
	ParagraphPtr m_item;
};
