#include "stdafx.h"

#include "CEditor.h"
#include "HtmlDocument.h"

int main()
{
	auto document = std::make_unique<HTMLDocument>();
	CEditor editor(std::move(document), std::cin, std::cout);
	editor.Start();

	return 0;
}
