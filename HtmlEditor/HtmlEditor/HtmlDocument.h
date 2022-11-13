#pragma once
#include "CDocumentItem.h"
#include "IDocument.h"
#include "UndoManager.h"

class HTMLDocument : public IDocument
{
public:
	 using Container = std::deque<CDocumentItem>;

	HTMLDocument() = default;

	HTMLDocument(std::string&& title);

	ParagraphPtr InsertParagraph(const std::string& text,
		std::optional<size_t> position = std::nullopt);
	ParagraphPtr ReplaceParagraph(const std::string& newText,
		std::optional<size_t> position = std::nullopt);

	/*IImageSharedPtr InsertImage(const Path& path, size_t width, size_t height,
		std::optional<size_t> position = std::nullopt) final;
	IImageSharedPtr ResizeImage(size_t width, size_t height,
		std::optional<size_t> position = std::nullopt) final;*/

	size_t GetItemsCount() const;
	const CDocumentItem& GetItem(size_t index) const;

	void DeleteItem(size_t index);

	const std::string& GetTitle() const;
	void SetTitle(const std::string& title);

	bool CanUndo() const;
	void Undo();
	bool CanRedo() const;
	void Redo();

	 void Save(const Path& path) const;

private:
	// size_t CountImages() const;

	std::string m_title = "Title";

	Container m_items;
	UndoManager m_undoManager;
};
