#pragma once
#include "stdafx.h"

class IUndoableEdit;

using IUndoableEditSharedPtr = std::shared_ptr<IUndoableEdit>;

class IUndoableEdit
{
public:
	virtual void Execute() = 0;

	virtual bool CanUndo() const = 0;
	virtual bool CanRedo() const = 0;

	virtual void Undo() = 0;
	virtual void Redo() = 0;
	virtual void Destroy() = 0;

	virtual bool AddEdit(const IUndoableEditSharedPtr& edit) = 0;
	virtual bool ReplaceEdit(const IUndoableEditSharedPtr& edit) = 0;

	virtual const std::string& GetName() const = 0;

	virtual ~IUndoableEdit() = default;
};

