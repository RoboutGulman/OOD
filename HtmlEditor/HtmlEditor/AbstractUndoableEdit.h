#pragma once
#include <string>

#include "IUndoableEdit.h"

class AbstractUndoableEdit : public IUndoableEdit
{
public:
	void Execute() final;

	bool CanUndo() const override;
	bool CanRedo() const override;

	void Undo() override;
	void Redo() override;

	bool AddEdit(const IUndoableEditSharedPtr& edit) override;
	bool ReplaceEdit(const IUndoableEditSharedPtr& edit) override;

	const std::string& GetName() const final;

	void operator()() final;

protected:
	AbstractUndoableEdit() = default;

	AbstractUndoableEdit(std::string&& editName)
		: m_name(std::forward<std::string>(editName))
		, m_wasExecuted(false)
	{
	}
	~AbstractUndoableEdit();

	virtual bool DerivedExecute() = 0;

	virtual bool DerivedUndo() = 0;
	virtual bool DerivedRedo() = 0;

	void Destroy() override;

private:
	bool m_wasExecuted = false;
	const std::string m_name{};
};
