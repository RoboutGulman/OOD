#include "stdafx.h"
#include "CEditorMenu.h"

CEditorMenu::CEditorMenu(std::istream& input, std::ostream& output)
	: m_input(input)
	, m_output(output)
{
}

void CEditorMenu::AddItem(const std::string& shortcut, const std::string& description, const Command& command)
{
	m_items.emplace_back(shortcut, description, command);
}

void CEditorMenu::Run()
{
	ShowInstructions();

	std::string shortcut;
	while ((m_output << ">")
		&& std::getline(m_input, shortcut)
		&& ExecuteCommand(shortcut))
	{
	}
}

void CEditorMenu::ShowInstructions()
{
	m_output << "Commands list:\n";
	for (auto& item : m_items)
	{
		m_output << item.shortcut << ": " << item.description << std::endl;
	}
	m_output << std::endl;
}

void CEditorMenu::Exit()
{
	m_exit = true;
}

bool CEditorMenu::ExecuteCommand(const std::string& shortcut)
{
	std::istringstream iss(shortcut);
	std::string name;
	iss >> name;

	m_exit = false;
	auto it = std::find_if(m_items.begin(), m_items.end(), [&name](const Item& item) {
		return item.shortcut == name;
	});

	if (it != m_items.end())
	{
		it->command(iss);
	}
	else
	{
		m_output << "Unknown command\n";
	}
	return !m_exit;
}
