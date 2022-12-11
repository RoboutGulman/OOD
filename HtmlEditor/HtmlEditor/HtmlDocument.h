#pragma once
#include "stdafx.h"

#include "CDocumentItem.h"
#include "IDocument.h"
#include "HistoryManager.h"

using DocumentItemsContainer = std::vector<CDocumentItem>;

class HTMLDocument : public IDocument
{
public:
	ParagraphPtr InsertParagraph(const std::string& text,
		std::optional<size_t> position = std::nullopt);
	ParagraphPtr ReplaceParagraph(const std::string& newText,
		std::optional<size_t> position = std::nullopt);

	/*IImageSharedPtr InsertImage(const Path& path, size_t width, size_t height,
		std::optional<size_t> position = std::nullopt);
	IImageSharedPtr ResizeImage(size_t width, size_t height,
		std::optional<size_t> position = std::nullopt);*/

	size_t GetItemsCount() const;
	CDocumentItem GetItem(size_t index) const;

	void DeleteItem(size_t index);

	std::string GetTitle() const;
	void SetTitle(const std::string& title);

	bool CanUndo() const;
	void Undo();
	bool CanRedo() const;
	void Redo();

private:
	std::string m_title = "Title";

	DocumentItemsContainer m_items;
	HistoryManager m_undoManager;
};
