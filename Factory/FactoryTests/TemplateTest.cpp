#include "../Factory/stdafx.h"

#define CATCH_CONFIG_MAIN
#include "../../../catch/catch.hpp"
#include "../Factory/CCanvas.h"
#include "../Factory/CDesigner.h"
#include "../Factory/CEllipse.h"
#include "../Factory/CPainter.h"
#include "../Factory/CRectangle.h"
#include "../Factory/CRegularPolygon.h"
#include "../Factory/CShapeFactory.h"
#include "../Factory/CTriangle.h"

SCENARIO("Shapes factory")
{
	CShapeFactory factory;

	WHEN("try to create ellipse")
	{
		std::shared_ptr<IShape> basePtr = factory.CreateShape("ellipse red 1 2 4 5");
		auto ellipsePtr = std::static_pointer_cast<CEllipse>(basePtr);
		THEN("ellipse is created and takes correct values")
		{
			CHECK(ellipsePtr->GetCenter() == Point(1, 2));
			CHECK(ellipsePtr->GetColor() == Color::RED);
			CHECK(ellipsePtr->GetVerticalRadius() == 4);
			CHECK(ellipsePtr->GetHorizontalRadius() == 5);
		}
	}
	WHEN("try to create rectangle")
	{
		std::shared_ptr<IShape> basePtr = factory.CreateShape("rectangle blue 5 6 7 8");
		auto rectanglePtr = std::static_pointer_cast<CRectangle>(basePtr);
		THEN("rectangle is created and takes correct values")
		{
			CHECK(rectanglePtr->GetColor() == Color::BLUE);
			CHECK(rectanglePtr->GetLeftTop() == Point(5, 6));
			CHECK(rectanglePtr->GetRightBottom() == Point(12, 14));
		}
	}
	WHEN("try to create regular polygon")
	{
		std::shared_ptr<IShape> basePtr = factory.CreateShape("regular-polygon green 5 6 7 8");
		auto poligonPtr = std::static_pointer_cast<CRegularPolygon>(basePtr);
		THEN("regular polygon is created and takes correct values")
		{
			CHECK(poligonPtr->GetCenter() == Point(5, 6));
			CHECK(poligonPtr->GetColor() == Color::GREEN);
			CHECK(poligonPtr->GetRadius() == 7);
			CHECK(poligonPtr->GetVertexCount() == 8);
		}
	}

	WHEN("try to create triangle")
	{
		std::shared_ptr<IShape> basePtr = factory.CreateShape("triangle pink 11 14 3 0 5 45");
		auto trianglePtr = std::static_pointer_cast<CTriangle>(basePtr);
		THEN("triangle is created and takes correct values")
		{
			CHECK(trianglePtr->GetVertex1() == Point(11, 14));
			CHECK(trianglePtr->GetVertex2() == Point(3, 0));
			CHECK(trianglePtr->GetVertex3() == Point(5, 45));
			CHECK(trianglePtr->GetColor() == Color::PINK);
		}
	}
	WHEN("try to create shape with not enough arguments")
	{
		REQUIRE_THROWS_AS(factory.CreateShape(""), std::invalid_argument);
		REQUIRE_THROWS_AS(factory.CreateShape("ellipse red 1 2 4"), std::invalid_argument);
		REQUIRE_THROWS_AS(factory.CreateShape("ellipse 1 2 4 5"), std::invalid_argument);
		REQUIRE_THROWS_AS(factory.CreateShape("yellow ellipse 1 2 4 5"), std::invalid_argument);
	}
	WHEN("try to create shape with incorrect arguments")
	{
		REQUIRE_THROWS_AS(factory.CreateShape("square red 1 2 4 5"), std::invalid_argument);
		REQUIRE_THROWS_AS(factory.CreateShape("regular polygon grey 1 2 4 5"), std::invalid_argument);
	}
}

SCENARIO("Designer")
{
	CShapeFactory factory;
	std::string input = "regular-polygon yellow 5 6 7 8\nrectangle blue 3 5 2 1\nellipse red 1 2 4 5\n";
	CDesigner designer(std::make_unique<CShapeFactory>(factory));
	std::istringstream strmIn(input);

	WHEN("designer creates a draft with shapes from input stream")
	{
		auto draft = designer.CreateDraft(strmIn);
		THEN("for each description the designer creates a shape")
		{
			CHECK(draft.GetShapeCount() == 3);
		}
		THEN("each shape takes correct values")
		{
			auto poligonPtr = std::static_pointer_cast<CRegularPolygon>(draft.GetShape(0));
			CHECK(poligonPtr->GetCenter() == Point(5, 6));
			CHECK(poligonPtr->GetColor() == Color::YELLOW);
			CHECK(poligonPtr->GetRadius() == 7);
			CHECK(poligonPtr->GetVertexCount() == 8);

			auto rectanglePtr = std::static_pointer_cast<CRectangle>(draft.GetShape(1));
			CHECK(rectanglePtr->GetColor() == Color::BLUE);
			CHECK(rectanglePtr->GetLeftTop() == Point(3, 5));
			CHECK(rectanglePtr->GetRightBottom() == Point(5, 6));

			CHECK(draft.GetShape(2)->GetColor() == Color::RED);
		}
	}
	WHEN("any of the descriptions are incorrect")
	{
		std::string input = "regular-polygon yellow 5 6 7 8\nrectangle blue 3 5 2 1\nellipse red 1 2\n";
		std::istringstream strmIn(input);
		THEN("an error occurs")
		{
			REQUIRE_THROWS_AS(designer.CreateDraft(strmIn), std::invalid_argument);
		}
	}
}

// тесты canvas
SCENARIO("Canvas")
{
	CShapeFactory factory;
	std::string input = "rectangle blue 3 5 2 1\nellipse red 1 2 4 5\n";
	std::istringstream strmIn(input);
	std::ostringstream strmOut;
	CDesigner designer(std::make_unique<CShapeFactory>(factory));
	auto draft = designer.CreateDraft(strmIn);
	CCanvas canvas(strmOut);

	CPainter painter;
	WHEN("painter draws a picture on canvas")
	{
		painter.DrawPicture(draft, std::make_unique<CCanvas>(canvas));
		THEN("he draws each shape using lines and ellipses")
		{
			CHECK(strmOut.str() == "Set color\nDraw line from {3,5} to {5,5}\n"
								   "Draw line from {3,5} to {3,6}\nDraw line from {5,5} to {5,6}\n"
								   "Draw line from {3,6} to {5,6}\n"
								   "Set color\nDraw ellipse with center in {1,2} width 4 height 5\n");
		}
	}
}
