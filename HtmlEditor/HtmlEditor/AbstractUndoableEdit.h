#pragma once
#include <string>

#include "IUndoableEdit.h"

class AbstractUndoableEdit : public IUndoableEdit
{
public:
	void Execute();

	bool CanUndo() const override;
	bool CanRedo() const override;

	void Undo() override;
	void Redo() override;

	bool AddEdit(const IUndoableEditSharedPtr& edit) override;
	bool ReplaceEdit(const IUndoableEditSharedPtr& edit) override;

protected:
	AbstractUndoableEdit() = default;

	~AbstractUndoableEdit();

	virtual bool DerivedExecute() = 0;

	virtual bool DerivedUndo() = 0;
	virtual bool DerivedRedo() = 0;

	void Destroy() override;

private:
	bool m_wasExecuted = false;
};
