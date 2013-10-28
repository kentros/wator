#include "stdafx.h"
#include "math.h"
#include "prog4.h"
#include "shark.h"
#include "tuna.h"
#include "creature.h"
#include "InitPopDialog.h"
#include "RunTimeParamDialog.h"

#include "prog4Doc.h"
#include "prog4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cprog4View

IMPLEMENT_DYNCREATE(Cprog4View, CView)

BEGIN_MESSAGE_MAP(Cprog4View, CView)
	ON_COMMAND(ID_START, OnStart)
	ON_COMMAND(ID_EDIT_INITIALIZATION, OnEditInitialization)
	ON_COMMAND(ID_EDIT_PARAMETERS, OnEditParameters)
	ON_WM_TIMER()
	ON_COMMAND(ID_COLORS_SHARKS, OnColorsSharks)
	ON_COMMAND(ID_COLORS_STARVINGSHARKS, OnColorsStarvingsharks)
	ON_COMMAND(ID_COLORS_TUNA, OnColorsTuna)
	ON_UPDATE_COMMAND_UI(ID_START, OnUpdateStart)
	ON_UPDATE_COMMAND_UI(ID_EDIT_INITIALIZATION, OnUpdateEditInitialization)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PARAMETERS, OnUpdateEditParameters)
	ON_UPDATE_COMMAND_UI(ID_COLORS_SHARKS, OnUpdateColorsSharks)
	ON_UPDATE_COMMAND_UI(ID_COLORS_STARVINGSHARKS, OnUpdateColorsStarvingsharks)
	ON_UPDATE_COMMAND_UI(ID_COLORS_TUNA, OnUpdateColorsTuna)
	ON_WM_CLOSE()
END_MESSAGE_MAP()

// Cprog4View construction/destruction

Cprog4View::Cprog4View()
: timeStep(.25)
, isStarted(false)
, m_bFirstStart(false)
, m_nCountFrames(0)
{
	sharkColor = 32768;
	starveSharkColor = 65408;
	tunaColor = RGB(255,0,0);
	oceanColor = RGB(102,102,255);

}

Cprog4View::~Cprog4View()
{
	//if (isStarted)
		//VERIFY(KillTimer(1));
}

BOOL Cprog4View::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

// Cprog4View drawing

void Cprog4View::OnDraw(CDC* pDC)
{
	Cprog4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// add draw code for native data here
	DrawGrid(pDC);

}


// Cprog4View diagnostics

#ifdef _DEBUG
void Cprog4View::AssertValid() const
{
	CView::AssertValid();
}

void Cprog4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cprog4Doc* Cprog4View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cprog4Doc)));
	return (Cprog4Doc*)m_pDocument;
}
#endif //_DEBUG


// Cprog4View message handlers

void Cprog4View::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	
	// Modify OnInitialUpdate to set the window size to 800 x 600
	AfxGetMainWnd()->SetWindowText("WaTor"); 
	AfxGetMainWnd()->MoveWindow(0,0,800,600,TRUE);

}

void Cprog4View::DrawGrid(CDC* pDC)
{
	//  Draw a hexagonal representation of the grid data stored in the document. 
	// Use light blue for the empty (i.e., ocean-filled) hexagons, and use the colors stored in 
	// the corresponding view data members for the tunas, sharks, and starving sharks. 
	// (When determining whether a non-NULL grid cell contains the address of a CTuna 
	// or a CShark, use run-time-type-information obtained from dynamic_cast.) 

	// find the client area
   CRect rect;
   GetClientRect(rect);
   
   Cprog4Doc *pDoc = GetDocument();
  

   // draw with a black pen
   CPen penBlack(PS_SOLID, 1, RGB(0, 0, 0));
   CPen* pOldPen = pDC->SelectObject(&penBlack);

   // and a solid red brush
    CBrush brushOcean(oceanColor);
	CBrush brushTuna(tunaColor);
	CBrush brushShark(sharkColor);
	CBrush brushStarveShark(starveSharkColor);

   CBrush* pOldBrush = pDC->SelectObject(&brushOcean);

	int rowNum = 50;
	int colNum = 70;

	// r = a / 2 
	// s = a / (2 * cos(30°)) 
	// h = s * sin(30°) 
	// b = s + (2 * h)
		
	int y = rect.Width();
	int a = y/69;
	//int b = rect.Height()/(rowNum);
	int r = a / 2;
	int s = (int) (a / (2 * cos(0.5235987)));
	int h = (int) (s * sin(.5235987));
	//int b = s + (2 * h);

	int Margin = 0;
	int evenRow = false;
	int offset = 0;

	// Find the vertices of the top left polygon, after that, just iterate through
   CPoint pts[6];
   pts[0].y = 0;
	
   for (int j = 1; j <= 50; j++)
   {
		if (evenRow)
			offset = r;

	   for (int i = 1; i <= 70; i++)
	   {

		   pts[0].x = rect.left + Margin + r*(i*2) + offset;
		   pts[0].y = rect.top + Margin + j*(s+h);

		   pts[1].x = pts[0].x + r;
		   pts[1].y = pts[0].y + h;

		   pts[2].x = pts[1].x;
		   pts[2].y = pts[1].y + s;

		   pts[3].x = pts[0].x;
		   pts[3].y = pts[2].y + h;

		   pts[4].x = pts[3].x - r;
		   pts[4].y = pts[2].y;

		   pts[5].x = pts[4].x;
		   pts[5].y = pts[1].y;

		   // Calling Polygon() on that array will draw three lines
		   // between the points, as well as an additional line to
		   // close the shape--from the last point to the first point
		   // we specified.
		   
			CCreature *cre = pDoc->WaterWorld.Grid[j-1][i-1];

			pDC->SelectObject(&brushOcean);
				
			if (isStarted)
			{

				if (CTuna *t2 = dynamic_cast<CTuna*>(cre))
					pDC->SelectObject(&brushTuna);
				if (CShark *s2 = dynamic_cast<CShark*>(cre))
				{	if (s2->Stomach < pDoc->WaterWorld.sharkStarveTime)
				pDC->SelectObject(&brushStarveShark);
				else
					pDC->SelectObject(&brushShark);

				}
			}

			pDC->Polygon(pts, 6);
	   }

	   evenRow = !evenRow;
	   offset = 0;
         
   } // end j

   // Put back the old objects.
   pDC->SelectObject(pOldPen);
   pDC->SelectObject(pOldBrush);

  m_nCountFrames++;
  

}

void Cprog4View::OnStart()
{
	Cprog4Doc *pDoc = GetDocument();

	if (!m_bFirstStart)
	{
		m_bFirstStart = !m_bFirstStart;
		pDoc->WaterWorld.Create();
		AfxGetMainWnd()->GetMenu()->ModifyMenu(ID_START,MF_BYCOMMAND,ID_START,"Stop");
	}


	if (!isStarted)
	{
		SetTimer(1,timeStep*1000,NULL);
		isStarted = true;
		AfxGetMainWnd()->GetMenu()->ModifyMenu(ID_START,MF_BYCOMMAND,ID_START,"Stop");
	}
	else
	{
		AfxGetMainWnd()->GetMenu()->ModifyMenu(ID_START,MF_BYCOMMAND,ID_START,"Start");
		KillTimer(1);
		isStarted = false;
	}
}

void Cprog4View::OnEditInitialization()
{
	Cprog4Doc *pDoc = GetDocument();
	
	CInitPopDialog myDialog;
	myDialog.m_nSharkNum = pDoc->WaterWorld.sharkInitNum;
	myDialog.m_nTunaNum = pDoc->WaterWorld.tunaInitNum;

	if (myDialog.DoModal() == IDOK)
	{
		pDoc->WaterWorld.sharkInitNum = myDialog.m_nSharkNum;
		pDoc->WaterWorld.tunaInitNum = myDialog.m_nTunaNum;
	}

}

void Cprog4View::OnEditParameters()
{
	Cprog4Doc *pDoc = GetDocument();

	CRunTimeParamDialog myDialog;
	myDialog.m_nSharkBreedTime = pDoc->WaterWorld.sharkBreedTime;
	myDialog.m_nSharkStarveTime = pDoc->WaterWorld.sharkStarveTime;
	myDialog.m_nTunaBreedTime = pDoc->WaterWorld.tunaBreedTime;
	myDialog.m_nFrameTime = timeStep;

	if (myDialog.DoModal() == IDOK)
	{
		pDoc->WaterWorld.sharkBreedTime = myDialog.m_nSharkBreedTime;
		pDoc->WaterWorld.sharkStarveTime = myDialog.m_nSharkStarveTime;
		pDoc->WaterWorld.tunaBreedTime = myDialog.m_nTunaBreedTime;
		timeStep = myDialog.m_nFrameTime;

	}
}

void Cprog4View::OnTimer(UINT nIDEvent)
{
	if (isStarted)
	{
		Cprog4Doc *pDoc = GetDocument();
		pDoc->WaterWorld.Update();
		Invalidate();
	}

	CView::OnTimer(nIDEvent);
}

void Cprog4View::OnColorsSharks()
{
	CColorDialog myColorDialog(sharkColor);

	if (myColorDialog.DoModal() == IDOK)
		sharkColor = myColorDialog.GetColor();
}

void Cprog4View::OnColorsStarvingsharks()
{
	CColorDialog myColorDialog(starveSharkColor);

	if (myColorDialog.DoModal() == IDOK)
		starveSharkColor = myColorDialog.GetColor();
}

void Cprog4View::OnColorsTuna()
{
	CColorDialog myColorDialog(tunaColor);

	if (myColorDialog.DoModal() == IDOK)
		tunaColor = myColorDialog.GetColor();
}

void Cprog4View::OnUpdateStart(CCmdUI *pCmdUI)
{
	if (isStarted)
	{
		pCmdUI->SetText("Stop");	
	}
}

void Cprog4View::OnUpdateEditInitialization(CCmdUI *pCmdUI)
{
	if (m_bFirstStart)
		pCmdUI->Enable(FALSE);
}

void Cprog4View::OnUpdateEditParameters(CCmdUI *pCmdUI)
{
	if (isStarted)
		pCmdUI->Enable(FALSE);
}

void Cprog4View::OnUpdateColorsSharks(CCmdUI *pCmdUI)
{
}

void Cprog4View::OnUpdateColorsStarvingsharks(CCmdUI *pCmdUI)
{
}


void Cprog4View::OnUpdateColorsTuna(CCmdUI *pCmdUI)
{
	if (isStarted)
		pCmdUI->Enable(FALSE);
}

void Cprog4View::OnClose()
{
	CView::OnClose();
}
