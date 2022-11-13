// TemplateTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../HtmlEditor/stdafx.h"

#define CATCH_CONFIG_MAIN
#include "../../../catch/catch.hpp"
#include "../HtmlEditor/CEditorRemoteControl.h"
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
	CEditorRemoteControl editorRC{ is, os };
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
	const std::string expectedOut = std::string("Commands list:\n") + "first: firstD\n" + "second: secondD\n" + "third: thirdD\n" + "exit: Stops\n\n>>>>";

	editorRC.Run();

	CHECK(firstExecuted == true);
	CHECK(secondExecuted == true);
	CHECK(thirdExecuted == true);
	CHECK(os.str() == expectedOut);
}

SCENARIO("Html Document")
{
	HTMLDocument doc;

	WHEN("create document")
	{
		THEN("it takes correct values")
		{
			CHECK(doc.CanRedo() == false);
			CHECK(doc.CanRedo() == false);
			REQUIRE_THROWS_AS(doc.GetItem(0), std::out_of_range);
			CHECK(doc.GetItemsCount() == 0);
			CHECK(doc.GetTitle() == "Title");
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
				CHECK(doc.GetTitle() == "Title");
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
}
