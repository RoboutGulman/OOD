// TemplateTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../HtmlEditor/stdafx.h"

#define CATCH_CONFIG_MAIN
#include "../../../catch/catch.hpp"
#include "../HtmlEditor/CEditor.h"
#include "../HtmlEditor/CEditorMenu.h"
#include "../HtmlEditor/CParagraph.h"
#include "../HtmlEditor/HtmlDocument.h"

SCENARIO("Paragraph")
{
	WHEN("we create paragraph with some text")
	{
		const auto expectedText = "ExpectedText";
		CParagraph paragraph(expectedText);
		THEN("paragraph takes correct text")
		{
			CHECK(paragraph.GetText() == expectedText);
		}
	}
	WHEN("we create paragraph with empty string")
	{
		const auto expectedText = "";
		CParagraph paragraph(expectedText);
		THEN("paragraph takes correct value")
		{
			CHECK(paragraph.GetText() == expectedText);
		}
	}
	WHEN("we create paragraph with empty string and then set some text")
	{
		CParagraph paragraph("");

		const auto expectedText = "ExpectedText";
		paragraph.SetText(expectedText);

		THEN("paragraph takes correct text")
		{
			CHECK(paragraph.GetText() == expectedText);
		}
	}
}

SCENARIO("Remote Control")
{
	const std::string firstCShortCut = "first", secondCShortCut = "second", thirdCShortCut = "third";
	const std::string exitC = "exit", exitCD = "Stops";
	const std::string firstDcsrp = "firstD", secondDscrp = "secondD", thirdD = "thirdD";
	std::istringstream is{ firstCShortCut + '\n' + secondCShortCut + '\n' + thirdCShortCut + '\n' + exitC + '\n' };
	std::ostringstream os{};
	CEditorMenu editorRC{ is, os };
	bool firstExecuted = false, secondExecuted = false, thirdExecuted = false;
	editorRC.AddItem(firstCShortCut, firstDcsrp, [&firstExecuted](std::istream&) noexcept {
		firstExecuted = true;
	});
	editorRC.AddItem(secondCShortCut, secondDscrp, [&secondExecuted](std::istream&) noexcept {
		secondExecuted = true;
	});
	editorRC.AddItem(thirdCShortCut, thirdD, [&thirdExecuted](std::istream&) noexcept {
		thirdExecuted = true;
	});
	editorRC.AddItem(exitC, exitCD, [&editorRC](std::istream&) noexcept {
		editorRC.Exit();
	});
	const std::string expectedOut = std::string("Welcome to Editor. Type 'Help' to show availible commands\n>>>>Commands list:\n") + "first: firstD\n" + "second: secondD\n" + "third: thirdD\n" + "exit: Stops\n\n";

	editorRC.Run();
	editorRC.ShowInstructions();

	CHECK(firstExecuted == true);
	CHECK(secondExecuted == true);
	CHECK(thirdExecuted == true);
	CHECK(os.str() == expectedOut);
}

SCENARIO("Html Document")
{
	HTMLDocument doc;
	const auto defaultTitle = "Title";

	WHEN("create document")
	{
		THEN("it takes correct values")
		{
			CHECK(doc.CanRedo() == false);
			CHECK(doc.CanRedo() == false);
			REQUIRE_THROWS_AS(doc.GetItem(0), std::out_of_range);
			CHECK(doc.GetItemsCount() == 0);
			CHECK(doc.GetTitle() == defaultTitle);
		}
	}
	WHEN("set document title")
	{
		const auto title = "NewDocumentTitle";
		doc.SetTitle(title);
		THEN("can undo and can't redo")
		{
			CHECK(doc.CanUndo() == true);
			CHECK(doc.CanRedo() == false);
		}
		WHEN("undo")
		{
			doc.Undo();
			THEN("title returns to default")
			{
				CHECK(doc.GetTitle() == defaultTitle);
				CHECK(doc.CanUndo() == false);
				CHECK(doc.CanRedo() == true);
			}
			WHEN("redo")
			{
				doc.Redo();
				THEN("title changes again")
				{
					CHECK(doc.GetTitle() == title);
					CHECK(doc.CanUndo() == true);
					CHECK(doc.CanRedo() == false);
				}
			}
		}
	}
	WHEN("insert paragraph")
	{
		const auto paragraphText = "Paragraph text";
		auto paragraph = doc.InsertParagraph(paragraphText);
		THEN("document contain paragraph with inserted text")
		{
			CHECK(paragraph->GetText() == paragraphText);
			CHECK(doc.CanRedo() == false);
			CHECK(doc.CanUndo() == true);
			CHECK(doc.GetItem(0).GetParagraph() == paragraph);
			CHECK(doc.GetItemsCount() == 1);
		}
	}
	WHEN("have document with 1 paragraph")
	{
		const auto paragraph1Text = "Paragraph 1 text";
		auto paragraph1 = doc.InsertParagraph(paragraph1Text);

		WHEN("insert paragraph on default position")
		{
			const auto paragraph2Text = "Paragraph 2 text";
			auto paragraph2 = doc.InsertParagraph(paragraph2Text);
			THEN("new paragraph insert in end of document")
			{
				CHECK(doc.GetItemsCount() == 2);
				CHECK(doc.GetItem(0).GetParagraph() == paragraph1);
				CHECK(doc.GetItem(1).GetParagraph() == paragraph2);
			}
		}
	}
	WHEN("have document with 2 paragraphs")
	{
		const auto paragraph1Text = "Paragraph 1 text";
		auto paragraph1 = doc.InsertParagraph(paragraph1Text);

		const auto paragraph2Text = "Paragraph 2 text";
		auto paragraph2 = doc.InsertParagraph(paragraph2Text);

		WHEN("insert paragraph in the first position")
		{
			const auto paragraph3Text = "Paragraph 3 text";
			auto paragraph3 = doc.InsertParagraph(paragraph3Text, 1);
			THEN("the first paragraph remains in its place, the second is shifted")
			{
				CHECK(doc.GetItemsCount() == 3);
				CHECK(doc.GetItem(0).GetParagraph() == paragraph1);
				CHECK(doc.GetItem(1).GetParagraph() == paragraph3);
				CHECK(doc.GetItem(2).GetParagraph() == paragraph2);
			}
		}
	}
	WHEN("insert paragraph on incorrect position")
	{
		REQUIRE_THROWS_AS(doc.InsertParagraph("text", 2), std::out_of_range);
	}
	WHEN("replace paragraph text")
	{
		const auto paragraphText = "Paragraph text";
		const auto newParagraphText = "new text of Paragraph";
		doc.InsertParagraph(paragraphText);

		auto paragraph = doc.ReplaceParagraph(newParagraphText);
		THEN("text in paragraph changes")
		{
			CHECK(paragraph->GetText() == newParagraphText);
			CHECK(doc.GetItemsCount() == 1);
			CHECK(doc.GetItem(0).GetParagraph() == paragraph);
		}
	}
	WHEN("replace paragraph in empty document")
	{
		REQUIRE_THROWS_AS(doc.ReplaceParagraph("text"), std::out_of_range);
	}
	WHEN("replace paragraph on incorrect position")
	{
		REQUIRE_THROWS_AS(doc.ReplaceParagraph("text", 2), std::out_of_range);
	}

	WHEN("have document with 3 paragraphs")
	{
		const auto paragraph1Text = "Paragraph 1 text";
		auto paragraph1 = doc.InsertParagraph(paragraph1Text);

		const auto paragraph2Text = "Paragraph 2 text";
		auto paragraph2 = doc.InsertParagraph(paragraph2Text);

		const auto paragraph3Text = "Paragraph 3 text";
		auto paragraph3 = doc.InsertParagraph(paragraph3Text);

		WHEN("delete paragraph in the first position")
		{
			doc.DeleteItem(1);
			THEN("the first paragraph remains in its place, the second is shifted")
			{
				CHECK(doc.GetItemsCount() == 2);
				CHECK(doc.GetItem(0).GetParagraph() == paragraph1);
				CHECK(doc.GetItem(1).GetParagraph() == paragraph3);
			}
		}
	}
}

SCENARIO("editor saves document with one paragraph")
{
	std::filesystem::path directoryPath = " directory";
	std::string input = "InsertParagraph end text\nList\nSave directory\nExit\n ";
	std::istringstream strmIn(input);
	std::ostringstream strmOut;
	auto document = std::make_unique<HTMLDocument>();
	CEditor editor(std::move(document), strmIn, strmOut);
	editor.Start();
	CHECK(strmOut.str() == "Welcome to Editor. Type 'Help' to show availible commands\n>>Title: Title\n1.  text\n>>");
	CHECK(std::filesystem::exists(directoryPath));
	std::filesystem::remove_all(directoryPath);
}
