#pragma once
class CEditorRemoteControl
{
public:
	using Command = std::function<void(std::istream&)>;

	CEditorRemoteControl(std::istream& input, std::ostream& output);

	void AddItem(const std::string& shortcut, const std::string& description, const Command& command);
	void Run();
	void ShowInstructions();
	void Exit();

private:
	bool ExecuteCommand(const std::string& shortcut);

	struct Item
	{
		Item(const std::string& shortcut, const std::string& description, const Command& command)
			: shortcut(shortcut)
			, description(description)
			, command(command)
		{
		}

		std::string shortcut;
		std::string description;
		Command command;
	};

	std::istream& m_input;
	std::ostream& m_output;

	std::vector<Item> m_items;
	bool m_exit = false;
};
