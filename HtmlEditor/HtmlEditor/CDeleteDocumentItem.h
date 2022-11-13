#pragma once
#include "stdafx.h"

#include "CDocumentItem.h"
#include "CompoundEdit.h"
#include "HtmlDocument.h"

class CDeleteDocumentItem : public AbstractUndoableEdit
{
public:
	CDeleteDocumentItem(DocumentItemsContainer& target, const CDocumentItem& item, size_t index)
		: AbstractUndoableEdit()
		, m_target(target)
		, m_index(index)
		, m_state(item)
	{
	}

private:
	bool DerivedExecute() final
	{
		if (m_index > m_target.size())
		{
			throw std::out_of_range("Failed to delete an item from Document. Given index is out of range");
		}

		auto it = m_target.begin();
		std::advance(it, m_index);

		m_target.erase(it);

		return true;
	}

	bool DerivedUndo() final
	{
		auto it = m_target.begin();
		std::advance(it, m_index);

		m_target.emplace(it, m_state);

		return true;
	}

	bool DerivedRedo() final
	{
		return DerivedExecute();
	}

	DocumentItemsContainer& m_target;

	size_t m_index;
	CDocumentItem m_state;
};
