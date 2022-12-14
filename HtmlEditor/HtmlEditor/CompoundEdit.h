#pragma once
#include <deque>

#include "AbstractUndoableEdit.h"

class CompoundEdit : public AbstractUndoableEdit
{
public:
	template <typename StringT>
	CompoundEdit(StringT&& editName)
		: AbstractUndoableEdit(std::forward<StringT>(editName))
		, m_inCompose(true)
		, m_edits()
	{
	}

	bool AddEdit(const IUndoableEditSharedPtr& edit);
	bool EndCompose() noexcept;

protected:
	CompoundEdit() = default;

	bool DerivedExecute() override;
	bool DerivedUndo() override;
	bool DerivedRedo() override;

	//vector ?????? deque
	std::deque<IUndoableEditSharedPtr> m_edits;

private:
	bool m_inCompose = true;
};
