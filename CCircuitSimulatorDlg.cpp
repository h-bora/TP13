// CCircuitSimulatorDlg.cpp: 구현 파일
//

#include "pch.h"
#include "TP13.h"
#include "afxdialogex.h"
#include "CCircuitSimulatorDlg.h"


// CCircuitSimulatorDlg 대화 상자

IMPLEMENT_DYNAMIC(CCircuitSimulatorDlg, CDialogEx)

CCircuitSimulatorDlg::CCircuitSimulatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CIRCUIT_SIMULATOR, pParent)
{

}

CCircuitSimulatorDlg::~CCircuitSimulatorDlg()
{
}

void CCircuitSimulatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCircuitSimulatorDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CCircuitSimulatorDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT4, &CCircuitSimulatorDlg::OnEnChangeEdit4)
	ON_STN_CLICKED(IDC_STATIC_DESC, &CCircuitSimulatorDlg::OnStnClickedStaticDesc)
END_MESSAGE_MAP()


// CCircuitSimulatorDlg 메시지 처리기

void CCircuitSimulatorDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// ENM_CHANGE가 있으면 마스크에 ORed를 플래그합니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CCircuitSimulatorDlg::OnEnChangeEdit4()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// ENM_CHANGE가 있으면 마스크에 ORed를 플래그합니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CCircuitSimulatorDlg::OnStnClickedStaticDesc()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
