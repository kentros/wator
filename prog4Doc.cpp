#include "stdafx.h"
#include "prog4.h"

#include "prog4Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cprog4Doc

IMPLEMENT_DYNCREATE(Cprog4Doc, CDocument)

BEGIN_MESSAGE_MAP(Cprog4Doc, CDocument)
END_MESSAGE_MAP()


// Cprog4Doc construction/destruction

Cprog4Doc::Cprog4Doc()
{
}

Cprog4Doc::~Cprog4Doc()
{
}

BOOL Cprog4Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}




// Cprog4Doc serialization

void Cprog4Doc::Serialize(CArchive& ar)
{
}


// Cprog4Doc diagnostics

#ifdef _DEBUG
void Cprog4Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void Cprog4Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Cprog4Doc commands
