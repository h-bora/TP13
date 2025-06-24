
// TP13Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "TP13.h"
#include "TP13Dlg.h"
#include "CSelectModeDlg.h"
#include "CImageProcessDlg.h"
#include "afxdialogex.h"
#include "CCircuitSimulatorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTP13Dlg 대화 상자



 CTP13Dlg::CTP13Dlg(CWnd* pParent /*=nullptr*/)	: CDialogEx(IDD_TP13_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}



void CTP13Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTP13Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_START, &CTP13Dlg::OnBnClickedBtnStart)
END_MESSAGE_MAP()


// CTP13Dlg 메시지 처리기

BOOL CTP13Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CSelectModeDlg dlg;
	dlg.m_isCircuitMode = false;  // 초기화 보장
	INT_PTR result = dlg.DoModal();

	return TRUE;
}


	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.

void CTP13Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.


// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CTP13Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void CTP13Dlg::OnBnClickedStartButton()
{
	//CSelectModeDlg dlg;
	//dlg.DoModal();

	ShowWindow(SW_HIDE);

	CImageProcessDlg dlg(this);
	dlg.DoModal();

	ShowWindow(SW_SHOW); // 되돌아올 경우 다시 보여줌
}

CCircuitSimulatorDlg::CCircuitSimulatorDlg(CWnd* pParent)
	: CDialogEx(IDD_CIRCUIT_SIMULATOR, pParent)
{
}

void CCircuitSimulatorDlg::SetMode(bool isRL)
{
	m_isRLMode = isRL;
	m_modeSet = true;
}
void CCircuitSimulatorDlg::OnBnClickedBtnRl()
{
	GetDlgItem(IDC_GROUP_SELECT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_GROUP_RL)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_GROUP_RC)->ShowWindow(SW_HIDE);
}

void CCircuitSimulatorDlg::OnBnClickedBtnRc()
{
	GetDlgItem(IDC_GROUP_SELECT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_GROUP_RL)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_GROUP_RC)->ShowWindow(SW_SHOW);
}

void CTP13Dlg::OnPaint()
{
	CPaintDC dc(this); // 그리기용 DC 객체

	// 여기에 필요한 그림 그리기 작업을 넣을 수 있음
	// 지금은 기본 그림 동작만 처리
}


void CTP13Dlg::OnBnClickedBtnStart()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CSelectModeDlg selectDlg;
	selectDlg.DoModal();

	// 이후 종료
	EndDialog(IDOK);

}
