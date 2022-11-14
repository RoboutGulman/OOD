#pragma once
#include "stdafx.h"

#include "CDocumentItem.h"
#include "CompoundEdit.h"
#include "HtmlDocument.h"

class CSetTitle : public AbstractUndoableEdit
{
public:
	template <typename StringT = std::string>
	CSetTitle(std::string& receiver, StringT&& name)
		: AbstractUndoableEdit()
		, m_receiver(receiver)
		, m_state(std::forward<StringT>(name))
	{
	}

private:
	bool DerivedExecute()
	{
		m_receiver.swap(m_state);

		return true;
	}

	bool DerivedUndo()
	{
		return DerivedExecute();
	}

	bool DerivedRedo()
	{
		return DerivedExecute();
	}

	std::string& m_receiver;
	std::string m_state;
};
