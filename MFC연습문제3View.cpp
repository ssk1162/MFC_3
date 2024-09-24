
// MFC연습문제3View.cpp: CMFC연습문제3View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFC연습문제3.h"
#endif

#include "MFC연습문제3Doc.h"
#include "MFC연습문제3View.h"
#include "CInputDlg.h";
#include "MainFrm.h";

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC연습문제3View

IMPLEMENT_DYNCREATE(CMFC연습문제3View, CView)

BEGIN_MESSAGE_MAP(CMFC연습문제3View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC연습문제3View 생성/소멸

CMFC연습문제3View::CMFC연습문제3View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFC연습문제3View::~CMFC연습문제3View()
{
}

BOOL CMFC연습문제3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFC연습문제3View 그리기

void CMFC연습문제3View::OnDraw(CDC* pDC)
{
	CMFC연습문제3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.

	switch (pDoc->m_nDocColor)
	{
	case 0 :
		pDC->SetTextColor(RGB(0, 0, 0));
		pDC->TextOut(pDoc->m_nDocX, pDoc->m_nDocY, pDoc->m_strDocText);
		break;
	case 1:
		pDC->SetTextColor(RGB(255, 0, 0));
		pDC->TextOut(pDoc->m_nDocX, pDoc->m_nDocY, pDoc->m_strDocText);
		break;
	case 2:
		pDC->SetTextColor(RGB(0, 255, 0));
		pDC->TextOut(pDoc->m_nDocX, pDoc->m_nDocY, pDoc->m_strDocText);
		break;
	case 3:
		pDC->SetTextColor(RGB(0, 0, 255));
		pDC->TextOut(pDoc->m_nDocX, pDoc->m_nDocY, pDoc->m_strDocText);
		break;
	}

	
	
}


// CMFC연습문제3View 인쇄

BOOL CMFC연습문제3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFC연습문제3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFC연습문제3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMFC연습문제3View 진단

#ifdef _DEBUG
void CMFC연습문제3View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC연습문제3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC연습문제3Doc* CMFC연습문제3View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC연습문제3Doc)));
	return (CMFC연습문제3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC연습문제3View 메시지 처리기


void CMFC연습문제3View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CInputDlg* pDlg = new CInputDlg();
	if (pDlg->DoModal() == IDOK)
	{
		CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
		CMFC연습문제3Doc* pDoc = (CMFC연습문제3Doc*)pFrame->GetActiveDocument();

		UpdateData(TRUE);

		pDoc->m_nDocX = pDlg->m_nX;
		pDoc->m_nDocY = pDlg->m_nY;
		pDoc->m_strDocText = pDlg->m_strText;
		
		Invalidate();

	}

	CView::OnRButtonDown(nFlags, point);
}
