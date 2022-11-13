#include "stdafx.h"

#include "CInsertDocumentItem.h"
#include "CParagraph.h"
#include "HtmlDocument.h"

HTMLDocument::HTMLDocument(std::string&& title)
	: m_title(std::move(title))
	, m_items()
	, m_undoManager()
{
}

ParagraphPtr HTMLDocument::InsertParagraph(const std::string& text, std::optional<size_t> position)
{
	const auto index = (position.has_value()) ? *position : m_items.size();

	auto newParagraph = std::make_shared<CParagraph>(text);
	auto newDocumentItem = CDocumentItem(newParagraph);

	m_undoManager.AddAndExecuteEdit(std::make_shared<CInsertDocumentItem<Container>>(m_items, newDocumentItem, index));

	return newParagraph;
}

ParagraphPtr HTMLDocument::ReplaceParagraph(const std::string& newText, std::optional<size_t> position)
{
	return ParagraphPtr();
}

size_t HTMLDocument::GetItemsCount() const
{
	return size_t();
}

const CDocumentItem& HTMLDocument::GetItem(size_t index) const
{
	// // O: insert return statement here
	return CDocumentItem(std::make_shared<CParagraph>("l"));
}

void HTMLDocument::DeleteItem(size_t index)
{
}

const std::string& HTMLDocument::GetTitle() const
{
	// // O: insert return statement here
	return "0";
}

void HTMLDocument::SetTitle(const std::string& title)
{
}

bool HTMLDocument::CanUndo() const
{
	return false;
}

void HTMLDocument::Undo()
{
}

bool HTMLDocument::CanRedo() const
{
	return false;
}

void HTMLDocument::Redo()
{
}

void HTMLDocument::Save(const Path& path) const
{
	for (auto item : m_items)
	{
		std::cout << item.GetParagraph()->GetText() << std::endl;
	}
}
