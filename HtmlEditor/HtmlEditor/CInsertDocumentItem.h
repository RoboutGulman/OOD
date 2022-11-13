#pragma once
#include "stdafx.h"

#include "CDocumentItem.h"
#include "AbstractUndoableEdit.h"

template <typename DocumentInnerContainerT>
class CInsertDocumentItem : public AbstractUndoableEdit
{
public:
	CInsertDocumentItem(DocumentInnerContainerT& target, const CDocumentItem& docItem, size_t index)
		: AbstractUndoableEdit()
		, m_target(target)
		, m_index(index)
		, m_state(docItem)
	{
	}

private:
	bool DerivedExecute()
	{
		if (m_index > m_target.size())
		{
			throw std::out_of_range("Failed to insert an item into Document. Given index is out of range");
		}

		auto it = m_target.begin();
		std::advance(it, m_index);

		m_target.emplace(it, m_state);

		return true;
	}

	bool DerivedUndo()
	{
		auto it = m_target.begin();
		std::advance(it, m_index);

		m_target.erase(it);

		return true;
	}

	bool DerivedRedo()
	{
		return DerivedExecute();
	}

	DocumentInnerContainerT& m_target;

	size_t m_index;
	CDocumentItem m_state;
};
