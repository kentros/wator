// prog4Doc.h : interface of the Cprog4Doc class
//


#pragma once
#include "wator.h"

class Cprog4Doc : public CDocument
{
protected: // create from serialization only
	Cprog4Doc();
	DECLARE_DYNCREATE(Cprog4Doc)

// Attributes
public:

// Operations
public:

// Overrides
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~Cprog4Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	CWaTor WaterWorld;
};


