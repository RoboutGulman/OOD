#pragma once
#include "stdafx.h"

#include "CDeleteDocumentItem.h"
#include "CDocumentItem.h"
#include "CompoundEdit.h"
#include "HtmlDocument.h"

class CReplaceDocumentItem : public CompoundEdit
{
public:
	CReplaceDocumentItem(DocumentItemsContainer& target,
		const CDocumentItem& oldDocItem,
		const CDocumentItem& newDocItem,
		size_t index)
		: CompoundEdit()
		, m_target(target)
		, m_index(index)
	{
		if (index >= target.size())
		{
			throw std::out_of_range("Failed to replace item in Document. Given index is out of range");
		}

		auto firstC = std::make_shared<CDeleteDocumentItem>(target,
			oldDocItem,
			index);
		auto secondC = std::make_shared<CInsertDocumentItem>(target,
			newDocItem,
			index);
		m_edits.emplace_back(std::move(firstC));
		m_edits.emplace_back(std::move(secondC));
	}

private:
	DocumentItemsContainer& m_target;

	size_t m_index;
};
