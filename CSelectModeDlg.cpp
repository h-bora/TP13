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

}

BEGIN_MESSAGE_MAP(CSelectModeDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_IMAGEPROCESS, &CSelectModeDlg::OnBnClickedBtnImageprocess)
	ON_BN_CLICKED(IDC_BTN_GRAPH_RC, &CSelectModeDlg::OnBnClickedBtnGraphRC)
	ON_BN_CLICKED(IDC_BTN_GRAPH_RL, &CSelectModeDlg::OnBnClickedBtnGraphRL)
	ON_BN_CLICKED(IDC_BTN_Circuit, &CSelectModeDlg::OnBnClickedBtnCircuit)
	ON_BN_CLICKED(IDC_BTN_Image, &CSelectModeDlg::OnBnClickedBtnImage)
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
	//CCircuitSimulatorDlg simdlg;
	//simdlg.SetMode(false); // RC
	//simdlg.DoModal();
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
	CImageProcessDlg dlg;
	dlg.DoModal();
	EndDialog(IDCANCEL);  // 종료
}

void CSelectModeDlg::OnBnClickedBtnCircuit()
{
	CCircuitSimulatorDlg dlg;
	dlg.DoModal();
	EndDialog(IDCANCEL);
}

