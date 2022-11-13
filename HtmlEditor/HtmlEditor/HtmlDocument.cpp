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
	bool isEndInsert = !position.has_value();

	size_t index = isEndInsert
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

void HTMLDocument::Print(std::ostream& output) const
{
	output << "Title: " << GetTitle() << std::endl;

	size_t itemIndex = 1;
	for (auto item : m_items)
	{
		output << itemIndex++ << ". " << item.GetParagraph()->GetText() << std::endl;
	}
}

const std::map<char, std::string_view> SPEC_SYMBS_TO_HTML_SYMBS{
	{ '<', "&lt;" },
	{ '>', "&gt;" },
	{ '"', "&Prime;" },
	{ '\'', "&prime;" },
	{ '&', "&amp;" }
};

std::string GetEncodedHtmlString(const std::string& src)
{
	std::string res;
	res.reserve(src.size());

	for (const auto& ch : src)
	{
		if (auto it = SPEC_SYMBS_TO_HTML_SYMBS.find(ch);
			it != SPEC_SYMBS_TO_HTML_SYMBS.end())
		{
			res += it->second;
		}
		else
		{
			res += ch;
		}
	}

	return res;
}

void SaveHead(std::ostream& output, size_t indentIndex, const std::string& title)
{
	output << std::string(2 * ++indentIndex, ' ') + "<head>\n"
		   << std::string(2 * ++indentIndex, ' ') + "<title>" + title + "</title>\n"
		   << std::string(2 * --indentIndex, ' ') + "</head>\n";
}

void SaveParagraph(const ParagraphPtr& paragraphPtr, std::ostream& output)
{
	if (paragraphPtr != nullptr)
	{
		output << "<p>" + GetEncodedHtmlString(paragraphPtr->GetText()) + "</p>";
	}
}

void FormHtmlDocument(const std::string& title, const DocumentItemsContainer& items, std::ostream& output)
{
	output << "<!DOCTYPE html>\n";

	output << "<html lang=\"en\">\n";

	size_t indentIndex = 0;

	SaveHead(output, indentIndex, title);

	output << std::string(2 * ++indentIndex, ' ') + "<body>\n";

	++indentIndex;
	for (auto item : items)
	{
		auto paragraphPtr = item.GetParagraph();

		output << std::string(2 * indentIndex, ' ');

		SaveParagraph(paragraphPtr, output);

		output << std::endl;
	}
	--indentIndex;

	output << std::string(2 * indentIndex, ' ') + "</body>\n"
		   << "</html>" << std::endl;
}

void HTMLDocument::Save(const Path& path) const
{
	if (!std::filesystem::is_directory(path))
	{
		std::filesystem::create_directory(path);
	}

	Path correctPath = path;
	correctPath /= m_title;
	correctPath = correctPath.replace_extension(".html");

	std::ofstream output(correctPath.generic_string());

	FormHtmlDocument(m_title, m_items, output);
}
