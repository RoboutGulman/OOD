#include "stdafx.h"

#include "CEllipse.h"
#include "CRectangle.h"
#include "CRegularPolygon.h"
#include "CShape.h"
#include "CShapeFactory.h"
#include "CTriangle.h"
#include "IShapeFactory.h"
#include "ShapeType.h"

//функции getColor, getPoint вызывать отдельно при создании каждой фигуры

constexpr auto NOT_ENOUGH_ARGUMENTS_ERROR = "The description should contain more arguments.";

ShapePtr MakeEllipse(Point&& basePoint, Color color, std::stringstream& stream)
{
	unsigned int verticalR, horizontalR;
	if (!(stream >> verticalR >> horizontalR))
	{
		throw std::invalid_argument("Ellipse parameters not found");
	}

	return std::make_shared<CEllipse>(std::move(basePoint), verticalR, horizontalR, color);
}

ShapePtr MakeRectangle(Point&& basePoint, Color color, std::stringstream& stream)
{
	unsigned int width, height;
	if (!(stream >> width >> height))
	{
		throw std::invalid_argument("Rectangle parameters not found");
	}
	return std::make_shared<CRectangle>(std::move(basePoint), width, height, color);
}

ShapePtr MakeRegularPoligon(Point&& basePoint, Color color, std::stringstream& stream)
{
	unsigned int radius, vertexCount;
	if (!(stream >> radius >> vertexCount))
	{
		throw std::invalid_argument("Regular polygon parameters not found");
	}
	return std::make_shared<CRegularPolygon>(std::move(basePoint), radius, vertexCount, color);
}

ShapePtr MakeTriangle(Point&& vertex1, Color color, std::stringstream& stream)
{
	Point vertex2, vertex3;

	if (!(stream >> vertex2 >> vertex3))
	{
		throw std::invalid_argument("Triangle parameters not found");
	}
	return std::make_shared<CTriangle>(std::move(vertex1), std::move(vertex2), std::move(vertex3), color);
}

ShapePtr MakeShape(ShapeType shapeType, Color color, std::stringstream& stream, Point&& basePoint)
{
	// перенести в createShape

	if (shapeType == ShapeType::ELLIPSE)
	{
		return MakeEllipse(std::move(basePoint), color, stream);
	}
	if (shapeType == ShapeType::RECTANGLE)
	{
		return MakeRectangle(std::move(basePoint), color, stream);
	}
	if (shapeType == ShapeType::REGULAR_POLYGON)
	{
		return MakeRegularPoligon(std::move(basePoint), color, stream);
	}
	if (shapeType == ShapeType::TRIANGLE)
	{
		return MakeTriangle(std::move(basePoint), color, stream);
	}
	return nullptr;
}

ShapePtr CShapeFactory::CreateShape(const std::string& description) const
{
	std::stringstream stream(description);
	std::string buffer;

	if (!(stream >> buffer))
	{
		throw std::invalid_argument(NOT_ENOUGH_ARGUMENTS_ERROR);
	}
	ShapeType shapeType = StringToShapeType(buffer);
	if (shapeType == ShapeType::UNKNOWN)
	{
		throw std::invalid_argument("Unknown shape type");
	}

	if (!(stream >> buffer))
	{
		throw std::invalid_argument(NOT_ENOUGH_ARGUMENTS_ERROR);
	}
	Color color = StringToColor(buffer);
	if (color == Color::UNKNOWN)
	{
		throw std::invalid_argument("Unknown color");
	}

	Point basePoint;

	if (!(stream >> basePoint))
	{
		throw std::invalid_argument("base point not found");
	}

	ShapePtr ptr = MakeShape(shapeType, color, stream, std::move(basePoint));

	return ptr;
}
