#include "stdafx.h"

#include "CInsertDocumentItem.h"
#include "CParagraph.h"
#include "CReplaceDocumentItem.h"
#include "CSetTitle.h"
#include "HtmlDocument.h"

ParagraphPtr HTMLDocument::InsertParagraph(const std::string& text, std::optional<size_t> position)
{
	const auto index = (position.has_value()) ? *position : m_items.size();

	auto newParagraph = std::make_shared<CParagraph>(text);
	auto newDocumentItem = CDocumentItem(newParagraph);

	m_undoManager.AddAndExecuteEdit(std::make_shared<CInsertDocumentItem>(m_items, newDocumentItem, index));

	return newParagraph;
}

ParagraphPtr HTMLDocument::ReplaceParagraph(const std::string& newText, std::optional<size_t> position)
{
	size_t index = !position.has_value()
		? (m_items.size() != 0)
			? m_items.size() - 1
			: 0
		: *position;

	if (index >= m_items.size())
	{
		throw std::out_of_range("Failed to replace paragraph's text in Document. Given index is out of range");
	}

	auto oldItem = m_items[index];
	if (oldItem.GetParagraph() == nullptr)
	{
		throw std::invalid_argument("Document doesn't contain paragraph at given index.");
	}

	auto newParagraph = std::make_shared<CParagraph>(newText);
	auto newDocumentItem = CDocumentItem(newParagraph);
	m_undoManager.AddAndExecuteEdit(std::make_shared<CReplaceDocumentItem>(m_items, oldItem, newDocumentItem, index));

	return newParagraph;
}

size_t HTMLDocument::GetItemsCount() const
{
	return m_items.size();
}

CDocumentItem HTMLDocument::GetItem(size_t index) const
{
	if (index >= GetItemsCount())
	{
		throw std::out_of_range("Failed to get item from HTMLDocument. Given index is out of range");
	}

	return m_items[index];
}

void HTMLDocument::DeleteItem(size_t index)
{
	if (index >= m_items.size())
	{
		throw std::out_of_range("Failed to delete item in HTMLDocument. Given index is out of range");
	}

	m_undoManager.AddAndExecuteEdit(std::make_shared<CDeleteDocumentItem>(m_items,
		GetItem(index),
		index));
}

std::string HTMLDocument::GetTitle() const
{
	return m_title;
}

void HTMLDocument::SetTitle(const std::string& title)
{
	m_undoManager.AddAndExecuteEdit(std::make_shared<CSetTitle>(m_title, title));
}

bool HTMLDocument::CanUndo() const
{
	return m_undoManager.CanUndo();
}

void HTMLDocument::Undo()
{
	m_undoManager.Undo();
}

bool HTMLDocument::CanRedo() const
{
	return m_undoManager.CanRedo();
}

void HTMLDocument::Redo()
{
	m_undoManager.Redo();
}