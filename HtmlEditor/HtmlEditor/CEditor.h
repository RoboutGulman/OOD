#pragma once
#include "stdafx.h"

#include "IDocument.h"
#include "CEditorMenu.h"
class CEditor
{
public:
	CEditor(DocumentPtr&& document, std::istream& input, std::ostream& output);

	void Start();

private:
	void Redo();
	void Undo();

	void DeleteItem(std::istream& is);
	void InsertParagparh(std::istream& is);
	//void InsertImage(std::istream& is);
	void PrintDocument();
	//void ResizeImage(std::istream& is);
	void ReplaceText(std::istream& is);
	void Save(std::istream& is);
	void SetTitle(std::istream& is);

	DocumentPtr m_document;
	CEditorMenu m_remoteControl;

	std::ostream& m_output;
};
