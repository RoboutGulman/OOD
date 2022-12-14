#pragma once
#include "stdafx.h"

#include "CDocumentItem.h"
#include "IParagraph.h"

class IDocument
{
public:
	virtual ParagraphPtr InsertParagraph(const std::string& text,
		std::optional<size_t> position = std::nullopt)
		= 0;
	virtual ParagraphPtr ReplaceParagraph(const std::string& newText,
		std::optional<size_t> position = std::nullopt)
		= 0;

	virtual size_t GetItemsCount() const = 0;
	virtual CDocumentItem GetItem(size_t index) const = 0;

	virtual void DeleteItem(size_t index) = 0;

	virtual std::string GetTitle() const = 0;
	virtual void SetTitle(const std::string& title) = 0;

	virtual bool CanUndo() const = 0;
	virtual void Undo() = 0;

	virtual bool CanRedo() const = 0;
	virtual void Redo() = 0;

	//????????? ? editor ??????? Save
	
	//????????? ? editor ??????? print
	
	virtual ~IDocument() = default;
};

using DocumentPtr = std::unique_ptr<IDocument>;
