  //************************************************************//
  // In December, 1984, A.K. Dewdney wrote about a mythical world named WaTor. 
  // This is an AppWizard program that simulates the harsh life on this world.
  // Because WaTor is toroidal, the top edge of the grid is connected to the bottom 
  // edge of the grid, and the left edge of the grid is connected to the right edge 
  // of the grid. So, if a fish swims off of the left edge of the grid, it will reappear
  // on the right edge of the grid.
  // There are two species of fish that live on WaTor: tuna and sharks. The tuna feed
  // on the abundant supply of plankton that live in the ocean, and the sharks feed on the tuna. 
  // Both kinds of fish can reproduce when they reach a certain age. 
  // (Oddly, their reproduction is accomplished by fission -- one fish splitting into two fish.) 
  // Though there is plenty of plankton such that the tuna never starve, sharks will starve if 
  // they go too long without eating tuna.
  //************************************************************// 

#include "stdafx.h"
#include "prog4.h"
#include "MainFrm.h"

#include "prog4Doc.h"
#include "prog4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cprog4App

BEGIN_MESSAGE_MAP(Cprog4App, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
END_MESSAGE_MAP()


// Cprog4App construction

Cprog4App::Cprog4App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only Cprog4App object

Cprog4App theApp;

// Cprog4App initialization

BOOL Cprog4App::InitInstance()
{
	CWinApp::InitInstance();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));
	LoadStdProfileSettings(4);  // Load standard INI file options (including MRU)
	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(Cprog4Doc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(Cprog4View));
	AddDocTemplate(pDocTemplate);
	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);
	// Dispatch commands specified on the command line.  Will return FALSE if
	// app was launched with /RegServer, /Register, /Unregserver or /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// The one and only window has been initialized, so show and update it
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	// call DragAcceptFiles only if there's a suffix
	//  In an SDI app, this should occur after ProcessShellCommand
	return TRUE;
}



// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

// App command to run the dialog
void Cprog4App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


// Cprog4App message handlers

