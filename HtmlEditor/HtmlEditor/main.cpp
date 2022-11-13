#include "stdafx.h"

#include "CEditor.h"
#include "HtmlDocument.h"

int main()
{
	auto doc = std::make_unique<HTMLDocument>();
	CEditor editor{ std::move(doc), std::cin, std::cout };
	editor.Start();

	return 0;
}
