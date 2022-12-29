// TemplateTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../ObjectAdapter/stdafx.h"

#define CATCH_CONFIG_MAIN
#include "../../../catch/catch.hpp"
#include "../ObjectAdapter/CModernGraphicsRenderer.h"
#include "../ObjectAdapter/CModernGraphicsRendererAdapter.h"
#include "../ObjectAdapter/ICanvas.h"
#include "../ObjectAdapter/Point.h"

std::string CreateExpectedAdapterOutput(int fromX, int fromY, int toX, int toY)
{
	return "<line fromX=\"" + std::to_string(fromX) + "\" fromY=\"" + std::to_string(fromY) + "\" toX=\"" + std::to_string(toX) + "\" toY=\"" + std::to_string(toY) + "\" />\n" ;
}

const std::string startDrawingMessage = "<draw>\n";

SCENARIO("Adapter")
{
	std::stringstream ss{};
	modern_graphics_lib::CModernGraphicsRenderer renderer{ ss };
	renderer.BeginDraw();
	graphics_lib::ICanvasPtr adapter = std::make_unique<app::CModernGraphicsRendererAdapter>(renderer);

	// доработать тесты
	WHEN("move to and then draw line")
	{
		const int fromX = 30, fromY = 10, toX = 1000, toY = 10;
		const std::string expectedCanvasOutput = CreateExpectedAdapterOutput(fromX, fromY, toX, toY);

		adapter->MoveTo(fromX, fromY);
		adapter->LineTo(toX, toY);

		THEN("drawing has started, line is drawn with correct coordinates and drawing is finished")
		{
			CHECK(ss.str() == startDrawingMessage + expectedCanvasOutput);
		}
	}

	WHEN("move two times and then draw line")
	{
		const modern_graphics_lib ::Point firstMovePoint(0, 10);
		const modern_graphics_lib ::Point secondMovePoint(3, 5);
		const modern_graphics_lib ::Point endLinePoint(10, 8);

		const std::string expectedCanvasOutput = CreateExpectedAdapterOutput(secondMovePoint.x, secondMovePoint.y, endLinePoint.x, endLinePoint.y);

		adapter->MoveTo(firstMovePoint.x, firstMovePoint.y);
		adapter->MoveTo(secondMovePoint.x, secondMovePoint.y);
		adapter->LineTo(endLinePoint.x, endLinePoint.y);

		THEN("Line was drawn from second move point")
		{
			CHECK(ss.str() == startDrawingMessage + expectedCanvasOutput);
		}
	}

	WHEN("draw line")
	{
		const int fromX = 0, fromY = 0, toX = 100, toY = 100;
		const std::string expectedCanvasOutput = CreateExpectedAdapterOutput(fromX, fromY, toX, toY);

		adapter->LineTo(toX, toY);

		THEN("drawing has started, line is drawn from (0,0) with correct coordinates and drawing is finished")
		{
			CHECK(ss.str() == startDrawingMessage + expectedCanvasOutput);
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
			CHECK(ss.str() == startDrawingMessage + expectedCanvasOutput);
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
			CHECK(ss.str() == startDrawingMessage + expectedCanvasOutput1 + expectedCanvasOutput2);
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
			CHECK(ss.str() == startDrawingMessage + expectedCanvasOutput1 + expectedCanvasOutput2);
		}
	}
}
