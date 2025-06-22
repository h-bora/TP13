// CSelectModeDlg.cpp: 구현 파일

#include "pch.h"
#include "TP13.h"
#include "afxdialogex.h"
#include "CSelectModeDlg.h"
#include "CImageProcessDlg.h"
#include "CGraphDlg.h"
#include "RLcircuit.h"
#include "RCcircuit.h"

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
	DDX_Control(pDX, IDC_EDIT_RC_R, m_editRcR);
	DDX_Control(pDX, IDC_EDIT_RC_C, m_editRcC);
	DDX_Control(pDX, IDC_EDIT_RC_V, m_editRcV);

	// RL
	DDX_Control(pDX, IDC_EDIT_RL_R, m_editRlR);
	DDX_Control(pDX, IDC_EDIT_RL_L, m_editRlL);
	DDX_Control(pDX, IDC_EDIT_RL_V, m_editRlV);
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
	CString strR, strC, strV;
	m_editRcR.GetWindowTextW(strR);
	m_editRcC.GetWindowTextW(strC);
	m_editRcV.GetWindowTextW(strV);

	double R = _ttof(strR);
	double C = _ttof(strC);
	double V = _ttof(strV);

	if (R <= 0 || C <= 0 || V <= 0) {
		AfxMessageBox(_T("RC 회로 입력값을 확인해주세요."));
		return;
	}

	RCcircuit circuit;
	circuit.simulate(R, C, V);

	CGraphDlg dlg;
	dlg.SetData(circuit.getTimeArray(), circuit.getCurrentArray(), _T("RC 회로 전류"));
	dlg.DoModal();
}

// RL 회로 시뮬레이션 및 그래프 출력
void CSelectModeDlg::OnBnClickedBtnGraphRL()
{
	CString strR, strL, strV;
	m_editRlR.GetWindowTextW(strR);
	m_editRlL.GetWindowTextW(strL);
	m_editRlV.GetWindowTextW(strV);

	double R = _ttof(strR);
	double L = _ttof(strL);
	double V = _ttof(strV);

	if (R <= 0 || L <= 0 || V <= 0) {
		AfxMessageBox(_T("RL 회로 입력값을 확인해주세요."));
		return;
	}

	RLcircuit circuit;
	circuit.simulate(R, L, V);

	CGraphDlg dlg;
	dlg.SetData(circuit.getTimeArray(), circuit.getVoltageArray(), _T("RL 회로 전압"));
	dlg.DoModal();
}