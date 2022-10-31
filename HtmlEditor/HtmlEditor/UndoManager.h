#pragma once
#include "CompoundEdit.h"

class UndoManager : private CompoundEdit
{
public:
	using CompoundEdit::Redo;
	using CompoundEdit::Undo;

	UndoManager() = default;

	bool CanUndo() const final;
	bool CanRedo() const final;

	void AddAndExecuteEdit(const IUndoableEditSharedPtr& edit);

private:
	bool DerivedExecute() final;
	bool DerivedUndo() final;
	bool DerivedRedo() final;

	size_t m_nextEditIndex{};
};