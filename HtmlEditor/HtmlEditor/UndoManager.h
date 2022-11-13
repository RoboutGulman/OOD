#pragma once
#include "CompoundEdit.h"

class UndoManager : private CompoundEdit
{
public:
	using CompoundEdit::Redo;
	using CompoundEdit::Undo;

	UndoManager() = default;

	bool CanUndo() const;
	bool CanRedo() const;

	void AddAndExecuteEdit(const IUndoableEditSharedPtr& edit);

private:
	bool DerivedExecute();
	bool DerivedUndo();
	bool DerivedRedo();

	size_t m_nextEditIndex{};
};