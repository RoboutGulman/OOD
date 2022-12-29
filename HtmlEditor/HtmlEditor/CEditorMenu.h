#pragma once
//переименовать в Menu
class CEditorMenu
{
public:
	using Command = std::function<void(std::istream&)>;

	CEditorMenu(std::istream& input, std::ostream& output);

	//переименовать Item в Command
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
