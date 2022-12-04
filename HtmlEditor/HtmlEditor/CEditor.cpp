#include "stdafx.h"
#include "CEditor.h"

constexpr auto EXIT_CMND = "Exit";
constexpr auto EXIT_DSCRP = "Stops the editor from working";

constexpr auto INSERT_PARAGRAPH_CMND = "InsertParagraph";
constexpr auto INSERT_PARAGRAPH_DSCRP = "Inserts a paragraph before <pos>. Args: {end|<pos>} <text>";

constexpr auto SAVE_CMND = "Save";
constexpr auto SAVE_DSCRP = "Saves document. Args: <path>";

constexpr auto SET_TITLE_CMND = "SetTitle";
constexpr auto SET_TITLE_DSCRP = "Changes title. Args: <new-title>";

constexpr auto PRINT_LIST_CMND = "List";
constexpr auto PRINT_LIST_DSCRP = "Lists document's content";

constexpr auto REPLACE_TEXT_CMND = "ReplaceText";
constexpr auto REPLACE_TEXT_DSCRP = "Replaces text item at <pos> with new content. Args: {end|<pos>}, <text>";

constexpr auto DELETE_CMND = "DeleteItem";
constexpr auto DELETE_DSCRP = "Deletes item at certain <pos>. Args: {pos}";

constexpr auto HELP_CMND = "Help";
constexpr auto HELP_DSCRP = "Shows list of available commands";

constexpr auto UNDO_CMND = "Undo";
constexpr auto UNDO_DSCRP = "Undo previous action";

constexpr auto REDO_CMND = "Redo";
constexpr auto REDO_DSCRP = "Redo undone action";

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
	m_remoteControl.AddItem(EXIT_CMND, EXIT_DSCRP, [&remoteControl = m_remoteControl](std::istream&) {
		remoteControl.Exit();
	});
	m_remoteControl.AddItem(INSERT_PARAGRAPH_CMND, INSERT_PARAGRAPH_DSCRP, [this](std::istream& is) {
		InsertParagparh(is);
	});
	m_remoteControl.AddItem(SAVE_CMND, SAVE_DSCRP, [this](std::istream& is) {
		Save(is);
	});
	m_remoteControl.AddItem(SET_TITLE_CMND, SET_TITLE_DSCRP, [this](std::istream& is) {
		SetTitle(is);
	});
	m_remoteControl.AddItem(PRINT_LIST_CMND, PRINT_LIST_DSCRP, [this](std::istream& is) {
		PrintDocument();
	});
	m_remoteControl.AddItem(REPLACE_TEXT_CMND, REPLACE_TEXT_DSCRP, [this](std::istream& is) {
		ReplaceText(is);
	});
	m_remoteControl.AddItem(DELETE_CMND, DELETE_DSCRP, [this](std::istream& is) {
		DeleteItem(is);
	});
	m_remoteControl.AddItem(HELP_CMND, HELP_DSCRP, [&remoteControl = m_remoteControl](std::istream&) {
		remoteControl.ShowInstructions();
	});
	m_remoteControl.AddItem(UNDO_CMND, UNDO_DSCRP, [this](std::istream&) {
		Undo();
	});
	m_remoteControl.AddItem(REDO_CMND, REDO_DSCRP, [this](std::istream&) {
		Redo();
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

void CEditor::DeleteItem(std::istream& is)
{
	std::string index;
	if (!(is >> index))
	{
		m_output << BAD_ARGUMENTS_MSG;
		return;
	}

	try
	{
		auto deleteIndex = GetCorrectIndexOfDocumentItem(m_document->GetItemsCount(), index);
		m_document->DeleteItem(deleteIndex);
	}
	catch (const std::exception& e)
	{
		m_output << e.what() << std::endl;
	}
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

void CEditor::PrintDocument()
{
	m_output << "Title: " << m_document->GetTitle() << std::endl;

	for (int itemIndex = 0; itemIndex < m_document->GetItemsCount(); itemIndex++)
	{
		m_output << itemIndex + 1 << ". " << m_document->GetItem(itemIndex).GetParagraph()->GetText() << std::endl;
	}
}

void CEditor::ReplaceText(std::istream& is)
{
	std::string text, paragraphIndex;
	if (!(is >> paragraphIndex) || !std::getline(is, text))
	{
		m_output << BAD_ARGUMENTS_MSG;
		return;
	}

	try
	{
		auto index = GetCorrectIndexOfDocumentItem(m_document->GetItemsCount(), paragraphIndex);
		m_document->ReplaceParagraph(text, index);
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

void CEditor::SetTitle(std::istream& is)
{
	std::string title;
	if (!std::getline(is, title))
	{
		m_output << BAD_ARGUMENTS_MSG;
		return;
	}

	m_document->SetTitle(title);
}
