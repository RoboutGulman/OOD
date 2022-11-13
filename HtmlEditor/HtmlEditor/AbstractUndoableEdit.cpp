#include "stdafx.h"

#include "AbstractUndoableEdit.h"

AbstractUndoableEdit::~AbstractUndoableEdit()
{
	Destroy();
}

void AbstractUndoableEdit::Execute()
{
	if (m_wasExecuted)
	{
		return;
	}

	m_wasExecuted = DerivedExecute();
}

void AbstractUndoableEdit::Undo()
{
	if (!CanUndo())
	{
		return;
	}

	m_wasExecuted = !DerivedUndo();
}

void AbstractUndoableEdit::Redo()
{
	if (!CanRedo())
	{
		return;
	}

	m_wasExecuted = DerivedRedo();
}

bool AbstractUndoableEdit::CanUndo() const
{
	return m_wasExecuted;
}

bool AbstractUndoableEdit::CanRedo() const
{
	return !m_wasExecuted;
}

void AbstractUndoableEdit::Destroy()
{
}

bool AbstractUndoableEdit::AddEdit(const IUndoableEditSharedPtr& edit)
{
	return false;
}

bool AbstractUndoableEdit::ReplaceEdit(const IUndoableEditSharedPtr& edit)
{
	return false;
}

const std::string& AbstractUndoableEdit::GetName() const
{
	return m_name;
}
