// RunTimeParamDialog.cpp : implementation file
//

#include "stdafx.h"
#include "prog4.h"
#include "RunTimeParamDialog.h"


// CRunTimeParamDialog dialog

IMPLEMENT_DYNAMIC(CRunTimeParamDialog, CDialog)
CRunTimeParamDialog::CRunTimeParamDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CRunTimeParamDialog::IDD, pParent)
	, m_nFrameTime(0)
	, m_nSharkBreedTime(0)
	, m_nSharkStarveTime(0)
	, m_nTunaBreedTime(0)
{
}

CRunTimeParamDialog::~CRunTimeParamDialog()
{
}

void CRunTimeParamDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_INTER_FRAME_EDIT, m_nFrameTime);
	DDV_MinMaxDouble(pDX, m_nFrameTime, 0.01, 5.0);
	DDX_Text(pDX, IDC_SHARK_BREED_EDIT, m_nSharkBreedTime);
	DDV_MinMaxInt(pDX, m_nSharkBreedTime, 1, 5000);
	DDX_Text(pDX, IDC_SHARK_STARVE_EDIT, m_nSharkStarveTime);
	DDV_MinMaxInt(pDX, m_nSharkStarveTime, 1, 5000);
	DDX_Text(pDX, IDC_TUNA_BREED_EDIT, m_nTunaBreedTime);
	DDV_MinMaxInt(pDX, m_nTunaBreedTime, 1, 5000);
}


BEGIN_MESSAGE_MAP(CRunTimeParamDialog, CDialog)
END_MESSAGE_MAP()


// CRunTimeParamDialog message handlers
