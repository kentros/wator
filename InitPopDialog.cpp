// InitPopDialog.cpp : implementation file
//

#include "stdafx.h"
#include "prog4.h"
#include "InitPopDialog.h"


// CInitPopDialog dialog

IMPLEMENT_DYNAMIC(CInitPopDialog, CDialog)
CInitPopDialog::CInitPopDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CInitPopDialog::IDD, pParent)
	, m_nSharkNum(0)
	, m_nTunaNum(0)
{
}

CInitPopDialog::~CInitPopDialog()
{
}

void CInitPopDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SHARK_EDIT, m_nSharkNum);
	DDV_MinMaxInt(pDX, m_nSharkNum, 1, 5000);
	DDX_Text(pDX, IDC_TUNA_EDIT, m_nTunaNum);
	DDV_MinMaxInt(pDX, m_nTunaNum, 1, 5000);
}


BEGIN_MESSAGE_MAP(CInitPopDialog, CDialog)
END_MESSAGE_MAP()


// CInitPopDialog message handlers
