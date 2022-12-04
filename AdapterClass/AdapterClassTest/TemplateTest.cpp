// TemplateTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../AdapterClass/stdafx.h"

#define CATCH_CONFIG_MAIN
#include "../../../catch/catch.hpp"
#include "../AdapterClass/CCanvasPainter.h"
#include "../AdapterClass/CModernGraphicsRendererAdapter.h"

std::string CreateExpectedAdapterOutput(int fromX, int fromY, int toX, int toY)
{
	return std::string("<draw>\n") + "<line fromX=\"" + std::to_string(fromX) + "\" fromY=\"" + std::to_string(fromY) + "\" toX=\"" + std::to_string(toX) + "\" toY=\"" + std::to_string(toY) + "\" />\n" + "</draw>\n";
}

SCENARIO("Adapter")
{

	std::stringstream ss{};
	graphics_lib::ICanvasPtr adapter = std::make_unique<app::CModernGraphicsRendererAdapter>(ss);

	WHEN("move to")
	{
		adapter->MoveTo(0, 10);

		THEN("drawing has started")
		{
			CHECK(ss.str() == "<draw>\n");
		}
	}

	WHEN("move two times")
	{
		adapter->MoveTo(0, 10);
		adapter->MoveTo(3, 5);

		THEN("drawing has started only one time")
		{
			CHECK(ss.str() == "<draw>\n");
		}
	}
	WHEN("move to and then draw line")
	{
		const int fromX = 30, fromY = 10, toX = 1000, toY = 10;
		const std::string expectedCanvasOutput = CreateExpectedAdapterOutput(fromX, fromY, toX, toY);

		adapter->MoveTo(fromX, fromY);
		adapter->LineTo(toX, toY);

		THEN("drawing has started, line is drawn with correct coordinates and drawing is finished")
		{
			CHECK(ss.str() == expectedCanvasOutput);
		}
	}
	WHEN("draw line")
	{
		const int fromX = 0, fromY = 0, toX = 100, toY = 100;
		const std::string expectedCanvasOutput = CreateExpectedAdapterOutput(fromX, fromY, toX, toY);

		adapter->LineTo(toX, toY);

		THEN("drawing has started, line is drawn from (0,0) with correct coordinates and drawing is finished")
		{
			CHECK(ss.str() == expectedCanvasOutput);
		}
	}
	WHEN("draw line and then move")
	{
		const int fromX = 0, fromY = 0, toX = 8, toY = 13;
		const std::string expectedCanvasOutput = CreateExpectedAdapterOutput(fromX, fromY, toX, toY);

		adapter->LineTo(toX, toY);
		adapter->MoveTo(fromX, fromY);

		THEN("line is drawn from (0,0) with correct coordinates and drawing starts again")
		{
			CHECK(ss.str() == expectedCanvasOutput + "<draw>\n");
		}
	}
	WHEN("draw 2 lines")
	{
		const modern_graphics_lib ::Point firstLineEndpoint(1, 1);
		const modern_graphics_lib ::Point secondLineEndpoint(3, 3);

		const std::string expectedCanvasOutput1 = CreateExpectedAdapterOutput(0, 0, firstLineEndpoint.x, firstLineEndpoint.y);
		const std::string expectedCanvasOutput2 = CreateExpectedAdapterOutput(firstLineEndpoint.x, firstLineEndpoint.y, secondLineEndpoint.x, secondLineEndpoint.y);

		adapter->LineTo(firstLineEndpoint.x, firstLineEndpoint.y);
		adapter->LineTo(secondLineEndpoint.x, secondLineEndpoint.y);

		THEN("both line is drawn. end of first line is start of second")
		{
			CHECK(ss.str() == expectedCanvasOutput1 + expectedCanvasOutput2);
		}
	}
	WHEN("draw line, move and then draw another line")
	{
		const modern_graphics_lib ::Point firstPoint(1, 1);
		const modern_graphics_lib ::Point movePoint(2, 2);
		const modern_graphics_lib ::Point secondPoint(3, 3);

		const std::string expectedCanvasOutput1 = CreateExpectedAdapterOutput(0, 0, firstPoint.x, firstPoint.y);
		const std::string expectedCanvasOutput2 = CreateExpectedAdapterOutput(movePoint.x, movePoint.y, secondPoint.x, secondPoint.y);

		adapter->LineTo(firstPoint.x, firstPoint.y);
		adapter->MoveTo(movePoint.x, movePoint.y);
		adapter->LineTo(secondPoint.x, secondPoint.y);

		THEN("both line is drawn. first line drawn from (0,0) second line drawn from move point")
		{
			CHECK(ss.str() == expectedCanvasOutput1 + expectedCanvasOutput2);
		}
	}
}
