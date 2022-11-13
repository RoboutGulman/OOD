#include "stdafx.h"
#include "CEditor.h"

constexpr auto EXIT_CMND = "Exit";
constexpr auto EXIT_CMND_DSCRP = "Stops the editor from working";

constexpr auto INSERT_PARAGRAPH_CMND = "InsertParagraph";
constexpr auto INSERT_PARAGRAPH_CMND_DSCRP = "Inserts a paragraph before <pos>. Args: {end|<pos>} <text>";

constexpr auto SAVE_CMND = "Save";
constexpr auto SAVE_CMND_DSCRP = "Saves document. Args: <path>";

constexpr auto BAD_ARGUMENTS_MSG = "Failed to read command's arguments. See help\n";

size_t GetCorrectIndexOfDocumentItem(size_t totalItemsInDocument, const std::string& userInput)
{
	bool isEndInsert = userInput == "end";

	size_t itemIndex = isEndInsert
		? totalItemsInDocument
		: std::stoi(userInput);

	if (totalItemsInDocument != 0 && !isEndInsert)
	{
		--itemIndex;
	}

	return itemIndex;
}

CEditor::CEditor(DocumentPtr&& document, std::istream& input, std::ostream& output)
	: m_document(std::move(document))
	, m_remoteControl(input, output)
	, m_output(output)
{
	m_remoteControl.AddItem(EXIT_CMND, EXIT_CMND_DSCRP, [&remoteControl = m_remoteControl](std::istream&) {
		remoteControl.Exit();
	});
	m_remoteControl.AddItem(INSERT_PARAGRAPH_CMND, INSERT_PARAGRAPH_CMND_DSCRP, [this](std::istream& is) {
		InsertParagparh(is);
	});
	m_remoteControl.AddItem(SAVE_CMND, SAVE_CMND_DSCRP, [this](std::istream& is) {
		Save(is);
	});
}

void CEditor::Start()
{
	m_remoteControl.Run();
}

void CEditor::Redo()
{
	if (!m_document->CanRedo())
	{
		m_output << "Can't redo\n";
		return;
	}

	m_document->Redo();
}

void CEditor::Undo()
{
	if (!m_document->CanUndo())
	{
		m_output << "Can't undo\n";
		return;
	}

	m_document->Undo();
}

void CEditor::InsertParagparh(std::istream& is)
{
	std::string text, paragraphIndex;
	if (!(is >> paragraphIndex) || !std::getline(is, text))
	{
		m_output << BAD_ARGUMENTS_MSG;
		return;
	}
	try
	{
		auto insertIndex = GetCorrectIndexOfDocumentItem(m_document->GetItemsCount(), paragraphIndex);
		m_document->InsertParagraph(text, insertIndex);
	}
	catch (std::exception& exception)
	{
		m_output << exception.what() << std::endl;
	}
}

void CEditor::Save(std::istream& is)
{
	std::string path;
	if (!std::getline(is, path))
	{
		m_output << BAD_ARGUMENTS_MSG;
		return;
	}

	try
	{
		m_document->Save(path);
	}
	catch (const std::exception& e)
	{
		m_output << e.what() << std::endl;
	}
}
