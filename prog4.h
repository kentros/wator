// prog4.h : main header file for the prog4 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols


// Cprog4App:
// See prog4.cpp for the implementation of this class
//

class Cprog4App : public CWinApp
{
public:
	Cprog4App();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cprog4App theApp;