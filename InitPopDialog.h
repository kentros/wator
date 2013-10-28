#pragma once


// CInitPopDialog dialog

class CInitPopDialog : public CDialog
{
	DECLARE_DYNAMIC(CInitPopDialog)

public:
	CInitPopDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CInitPopDialog();

// Dialog Data
	enum { IDD = IDD_INITPOP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int m_nSharkNum;
	int m_nTunaNum;
};
