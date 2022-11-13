#pragma once
#include "stdafx.h"

class IParagraph
{
public:
	virtual std::string GetText() const = 0;
	virtual void SetText(const std::string& text) = 0;
};

using ParagraphPtr = std::shared_ptr<IParagraph>;
