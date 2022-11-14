#pragma once
#include "stdafx.h"

#include "CDeleteDocumentItem.h"
#include "CDocumentItem.h"
#include "CompoundEdit.h"
#include "HtmlDocument.h"

class CReplaceDocumentItem : public CompoundEdit
{
public:
	CReplaceDocumentItem(DocumentItemsContainer& receiver,
		const CDocumentItem& oldDocItem,
		const CDocumentItem& newDocItem,
		size_t index)
		: CompoundEdit()
		, m_receiver(receiver)
		, m_index(index)
	{
		if (index >= receiver.size())
		{
			throw std::out_of_range("Failed to replace item in Document. Given index is out of range");
		}

		auto firstC = std::make_shared<CDeleteDocumentItem>(receiver,
			oldDocItem,
			index);
		auto secondC = std::make_shared<CInsertDocumentItem>(receiver,
			newDocItem,
			index);
		m_edits.emplace_back(std::move(firstC));
		m_edits.emplace_back(std::move(secondC));
	}

private:
	DocumentItemsContainer& m_receiver;

	size_t m_index;
};
