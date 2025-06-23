// CSelectModeDlg.cpp: 구현 파일

#include "pch.h"
#include "TP13.h"
#include "afxdialogex.h"
#include "CSelectModeDlg.h"
#include "CImageProcessDlg.h"
#include "CGraphDlg.h"
#include "RLcircuit.h"
#include "RCcircuit.h"
#include "CCircuitSimulatorDlg.h"

// CSelectModeDlg 대화 상자

IMPLEMENT_DYNAMIC(CSelectModeDlg, CDialogEx)

CSelectModeDlg::CSelectModeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SELECT_MODE, pParent)
{
}

CSelectModeDlg::~CSelectModeDlg()
{
}

void CSelectModeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	// RC
	//DDX_Control(pDX, IDC_EDIT_RC_R, m_editRcR);
	//DDX_Control(pDX, IDC_EDIT_RC_C, m_editRcC);
	//DDX_Control(pDX, IDC_EDIT_RC_V, m_editRcV);

	// RL
	//DDX_Control(pDX, IDC_EDIT_RL_R, m_editRlR);
	//DDX_Control(pDX, IDC_EDIT_RL_L, m_editRlL);
	//DDX_Control(pDX, IDC_EDIT_RL_V, m_editRlV);
}

BEGIN_MESSAGE_MAP(CSelectModeDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_IMAGEPROCESS, &CSelectModeDlg::OnBnClickedBtnImageprocess)
	ON_BN_CLICKED(IDC_BTN_GRAPH_RC, &CSelectModeDlg::OnBnClickedBtnGraphRC)
	ON_BN_CLICKED(IDC_BTN_GRAPH_RL, &CSelectModeDlg::OnBnClickedBtnGraphRL)
END_MESSAGE_MAP()

// 이미지 처리 버튼
void CSelectModeDlg::OnBnClickedBtnImageprocess()
{
	CImageProcessDlg dlg;
	dlg.DoModal();
}

// RC 회로 시뮬레이션 및 그래프 출력
void CSelectModeDlg::OnBnClickedBtnGraphRC()
{
	CCircuitSimulatorDlg simdlg;
	simdlg.SetMode(false); // RC
	simdlg.DoModal();
}

// RL 회로 시뮬레이션 및 그래프 출력
void CSelectModeDlg::OnBnClickedBtnGraphRL()
{
	CCircuitSimulatorDlg simdlg;
	simdlg.SetMode(true); // RL
	simdlg.DoModal();
	
}

void CSelectModeDlg::OnBnClickedBtnImage()
{
	// 이미지 처리 버튼 클릭 시 동작
	m_isCircuitMode = false;
	EndDialog(IDOK);
}

void CSelectModeDlg::OnBnClickedBtnCircuit()
{
	// 회로 시뮬레이터 버튼 클릭 시 동작
	m_isCircuitMode = true;
	EndDialog(IDOK);
}
