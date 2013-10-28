#pragma once


// CRunTimeParamDialog dialog

class CRunTimeParamDialog : public CDialog
{
	DECLARE_DYNAMIC(CRunTimeParamDialog)

public:
	CRunTimeParamDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CRunTimeParamDialog();

// Dialog Data
	enum { IDD = IDD_INITRUNTPARAM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double m_nFrameTime;
	int m_nSharkBreedTime;
	int m_nSharkStarveTime;
	int m_nTunaBreedTime;
};
