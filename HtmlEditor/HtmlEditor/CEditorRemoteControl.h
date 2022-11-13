#pragma once
class CEditorRemoteControl
{
public:
	using CommandFunction = std::function<void(std::istream&)>;

	CEditorRemoteControl(std::istream& input, std::ostream& output);

	void AddItem(const std::string& command, const std::string& description, const CommandFunction& commandFunction);
	void Run();
	void ShowInstructions();
	void Exit();

private:
	bool ExecuteCommand(const std::string& command);

	struct Item
	{
		Item(const std::string& command, const std::string& description, const CommandFunction& commandFunction)
			: command(command)
			, description(description)
			, commandFunction(commandFunction)
		{
		}

		std::string command{};
		std::string description{};
		CommandFunction commandFunction{};
	};

	std::istream& m_input;
	std::ostream& m_output;

	std::vector<Item> m_items;
	bool m_exit = false;
};
