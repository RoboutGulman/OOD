#include "stdafx.h"
#include "CDocumentItem.h"

CDocumentItem::CDocumentItem(ParagraphPtr item)
	: m_item(item)
{
}

ParagraphPtr CDocumentItem::GetParagraph()
{
	return m_item;
}
