#include "stdafx.h"

#include "CompoundEdit.h"
#include <algorithm>

bool CompoundEdit::AddEdit(const IUndoableEditSharedPtr& edit)
{
	if (!m_inCompose)
	{
		return false;
	}

	if (!m_edits.empty())
	{
		if (auto& lastEdit = m_edits.back();
			!lastEdit->AddEdit(edit))
		{
			if (edit->ReplaceEdit(lastEdit))
			{
				m_edits.pop_back();
			}
			m_edits.push_back(edit);
		}
	}
	else
	{
		m_edits.push_back(edit);
	}

	return true;
}

bool CompoundEdit::EndCompose() noexcept
{
	bool result = m_inCompose;
	m_inCompose = false;

	return result;
}

bool CompoundEdit::DerivedExecute()
{
	std::for_each(m_edits.begin(), m_edits.end(), [](auto& edit) {
		edit->Execute();
	});
	return true;
}

bool CompoundEdit::DerivedUndo()
{
	std::for_each(m_edits.rbegin(), m_edits.rend(), [](auto& edit) {
		edit->Undo();
	});
	return true;
}

bool CompoundEdit::DerivedRedo()
{
	std::for_each(m_edits.begin(), m_edits.end(), [](auto& edit) {
		edit->Redo();
	});
	return true;
}
