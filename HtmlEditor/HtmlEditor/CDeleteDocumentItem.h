#pragma once
#include "stdafx.h"

#include "CDocumentItem.h"
#include "CompoundEdit.h"
#include "HtmlDocument.h"

class CDeleteDocumentItem : public AbstractUndoableEdit
{
public:
	CDeleteDocumentItem(DocumentItemsContainer& receiver, const CDocumentItem& item, size_t index)
		: AbstractUndoableEdit()
		, m_receiver(receiver)
		, m_index(index)
		, m_state(item)
	{
	}

private:
	bool DerivedExecute()
	{
		if (m_index > m_receiver.size())
		{
			throw std::out_of_range("Failed to delete an item from Document. Given index is out of range");
		}

		auto it = m_receiver.begin();
		std::advance(it, m_index);

		m_receiver.erase(it);

		return true;
	}

	bool DerivedUndo()
	{
		auto it = m_receiver.begin();
		std::advance(it, m_index);

		m_receiver.emplace(it, m_state);

		return true;
	}

	bool DerivedRedo()
	{
		return DerivedExecute();
	}

	DocumentItemsContainer& m_receiver;

	size_t m_index;
	CDocumentItem m_state;
};
