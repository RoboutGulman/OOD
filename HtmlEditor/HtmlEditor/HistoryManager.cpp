#include "stdafx.h"

#include "HistoryManager.h"

bool HistoryManager::CanUndo() const
{
	return m_nextEditIndex != 0;
}

bool HistoryManager::CanRedo() const
{
	return m_nextEditIndex != m_edits.size();
}

void HistoryManager::AddAndExecuteEdit(const IUndoableEditSharedPtr& edit)
{
	// переделать
	edit->Execute();

	if (m_nextEditIndex < m_edits.size())
	{
		m_edits.resize(++m_nextEditIndex);
		m_edits.back() = edit;
	}
	else
	{
		m_edits.emplace_back(edit);
		++m_nextEditIndex;
	}
}

bool HistoryManager::DerivedExecute()
{
	return false;
}

bool HistoryManager::DerivedUndo()
{
	m_edits[--m_nextEditIndex]->Undo();

	return true;
}

bool HistoryManager::DerivedRedo()
{
	m_edits[m_nextEditIndex++]->Redo();

	return true;
}
