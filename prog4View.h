// prog4View.h : interface of the Cprog4View class
//


#pragma once


class Cprog4View : public CView
{
protected: // create from serialization only
	Cprog4View();
	DECLARE_DYNCREATE(Cprog4View)

// Attributes
public:
	Cprog4Doc* GetDocument() const;

// Operations
public:

// Overrides
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~Cprog4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	COLORREF tunaColor;
	COLORREF sharkColor;
	COLORREF starveSharkColor;
	COLORREF oceanColor;
	void DrawGrid(CDC* pDC);
	afx_msg void OnStart();
	afx_msg void OnEditInitialization();
	afx_msg void OnEditParameters();
	double timeStep;
	bool isStarted;
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnColorsSharks();
	afx_msg void OnColorsStarvingsharks();
	afx_msg void OnColorsTuna();
	afx_msg void OnUpdateStart(CCmdUI *pCmdUI);
	afx_msg void OnUpdateEditInitialization(CCmdUI *pCmdUI);
	afx_msg void OnUpdateEditParameters(CCmdUI *pCmdUI);
	bool m_bFirstStart;
	int m_nCountFrames;
	afx_msg void OnUpdateColorsSharks(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorsStarvingsharks(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorsTuna(CCmdUI *pCmdUI);
	afx_msg void OnClose();
};

#ifndef _DEBUG  // debug version in prog4View.cpp
inline Cprog4Doc* Cprog4View::GetDocument() const
   { return reinterpret_cast<Cprog4Doc*>(m_pDocument); }
#endif

