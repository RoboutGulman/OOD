#include "stdafx.h"
#include "CEditorRemoteControl.h"

CEditorRemoteControl::CEditorRemoteControl(std::istream& input, std::ostream& output)
	: m_input(input)
	, m_output(output)
{
}

void CEditorRemoteControl::AddItem(const std::string& command, const std::string& description, const CommandFunction& commandFunction)
{
	m_items.emplace_back(command, description, commandFunction);
}

void CEditorRemoteControl::Run()
{
	ShowInstructions();

	std::string command;
	while ((m_output << ">")
		&& std::getline(m_input, command)
		&& ExecuteCommand(command))
	{
	}
}

void CEditorRemoteControl::ShowInstructions()
{
	m_output << "Commands list:\n";
	for (auto& item : m_items)
	{
		m_output << item.command << ": " << item.description << std::endl;
	}
	m_output << std::endl;
}

void CEditorRemoteControl::Exit()
{
	m_exit = true;
}

bool CEditorRemoteControl::ExecuteCommand(const std::string& command)
{
	std::istringstream iss(command);
	std::string name;
	iss >> name;

	m_exit = false;
	auto it = std::find_if(m_items.begin(), m_items.end(), [&name](const Item& item) {
		return item.command == name;
	});

	if (it != m_items.end())
	{
		it->commandFunction(iss);
	}
	else
	{
		m_output << "Unknown command\n";
	}
	return !m_exit;
}
