﻿// CInputDlg.cpp: 구현 파일
//

#include "pch.h"
#include "MFC연습문제3.h"
#include "afxdialogex.h"
#include "CInputDlg.h"
#include "MainFrm.h";
#include "MFC연습문제3Doc.h"


// CInputDlg 대화 상자

IMPLEMENT_DYNAMIC(CInputDlg, CDialogEx)

CInputDlg::CInputDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_INPUT, pParent)
	, m_nX(0)
	, m_nY(0)
	, m_strText(_T(""))
{
	m_nX = 30;
	m_nY = 30;
}

CInputDlg::~CInputDlg()
{
}

void CInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_X, m_nX);
	DDX_Text(pDX, IDC_EDIT_Y, m_nY);
	DDX_Text(pDX, IDC_EDIT_TEXT, m_strText);
	DDX_Control(pDX, IDC_COMBO_COLOR, m_cbColor);
}


BEGIN_MESSAGE_MAP(CInputDlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO_COLOR, &CInputDlg::OnSelchangeComboColor)
END_MESSAGE_MAP()


// CInputDlg 메시지 처리기


BOOL CInputDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	
	m_cbColor.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CInputDlg::OnSelchangeComboColor()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int index = m_cbColor.GetCurSel();

	if (index != CB_ERR)
	{
		CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
		CMFC연습문제3Doc* pDoc = (CMFC연습문제3Doc*)pFrame->GetActiveDocument();

		pDoc->m_nDocColor = index;

	}


}
