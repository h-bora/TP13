// CCircuitSimulatorDlg.cpp: 구현 파일
//

#include "pch.h"
#include "TP13.h"
#include "afxdialogex.h"
#include "RCcircuit.h"
#include "RLcircuit.h"
#include "CCircuitSimulatorDlg.h"
#include <string>
#include <atlconv.h>


// CCircuitSimulatorDlg 대화 상자

IMPLEMENT_DYNAMIC(CCircuitSimulatorDlg, CDialogEx)

CCircuitSimulatorDlg::~CCircuitSimulatorDlg(){
}

void CCircuitSimulatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCircuitSimulatorDlg, CDialogEx)
	//ON_EN_CHANGE(IDC_EDIT1, &CCircuitSimulatorDlg::OnEnChangeEdit1)
	//ON_EN_CHANGE(IDC_EDIT4, &CCircuitSimulatorDlg::OnEnChangeEdit4)
	ON_STN_CLICKED(IDC_STATIC_DESC, &CCircuitSimulatorDlg::OnStnClickedStaticDesc)
	ON_EN_CHANGE(IDC_EDIT_RC_R, &CCircuitSimulatorDlg::OnEnChangeEditRcR)
	ON_EN_CHANGE(IDC_EDIT_RC_C, &CCircuitSimulatorDlg::OnEnChangeEditRcC)
	ON_EN_CHANGE(IDC_EDIT_RC_V, &CCircuitSimulatorDlg::OnEnChangeEditRcV)
	ON_EN_CHANGE(IDC_EDIT_RL_R, &CCircuitSimulatorDlg::OnEnChangeEditRlR)
	ON_EN_CHANGE(IDC_EDIT_RL_L, &CCircuitSimulatorDlg::OnEnChangeEditRlL)
	ON_EN_CHANGE(IDC_EDIT_RL_V, &CCircuitSimulatorDlg::OnEnChangeEditRlV)
	
	ON_BN_CLICKED(IDC_BTN_GRAPH_RC, &CCircuitSimulatorDlg::OnBnClickedBtnGraphRc)
	ON_BN_CLICKED(IDC_BTN_GRAPH_RL, &CCircuitSimulatorDlg::OnBnClickedBtnGraphRl)
	ON_BN_CLICKED(IDC_GROUP_SELECT, &CCircuitSimulatorDlg::OnBnClickedGroupSelect)
	ON_BN_CLICKED(IDC_GROUP_RL, &CCircuitSimulatorDlg::OnBnClickedGroupRl)
	ON_BN_CLICKED(IDC_GROUP_RC, &CCircuitSimulatorDlg::OnBnClickedGroupRc)
	ON_BN_CLICKED(IDC_BTN_RL, &CCircuitSimulatorDlg::OnBnClickedBtnRl)
	ON_BN_CLICKED(IDC_BTN_RC, &CCircuitSimulatorDlg::OnBnClickedBtnRc)
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

void CCircuitSimulatorDlg::OnEnChangeEditRlR()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCircuitSimulatorDlg::OnEnChangeEditRcR()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCircuitSimulatorDlg::OnEnChangeEditRcC()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCircuitSimulatorDlg::OnEnChangeEdit()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCircuitSimulatorDlg::OnEnChangeEditRlL()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCircuitSimulatorDlg::OnEnChangeEditRlV()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCircuitSimulatorDlg::OnEnChangeEditRcV()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CCircuitSimulatorDlg::OnBnClickedBtnGraphRl()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strR, strL, strVin;
	GetDlgItemText(IDC_EDIT_RL_R, strR);
	GetDlgItemText(IDC_EDIT_RL_L, strL);
	GetDlgItemText(IDC_EDIT_RL_V, strVin);

	USES_CONVERSION; // 🔺 CT2A 쓸 때 꼭 필요할 수 있음

	double R, L, Vin;

	try {
		R = std::stod(std::string(CT2A(strR)));
		L = std::stod(std::string(CT2A(strL)));
		Vin = std::stod(std::string(CT2A(strVin)));
	}
	catch (const std::exception&) {
		AfxMessageBox(_T("입력값이 숫자가 아닙니다. 예: 10, 1.2, 3.5e-2 같은 형식으로 입력해주세요."));
		return;
	}

	if (R <= 0 || L <= 0 || Vin <= 0) {
		AfxMessageBox(_T("R, L, Vin 값을 모두 양수로 입력해주세요."));
		return;
	}

	CString msg;
	msg.Format(_T("RL 시뮬레이션 실행:\nR=%.4f\nL=%.6f\nVin=%.3f"), R, L, Vin);
	AfxMessageBox(msg);

	m_rlCircuit.simulate(R, L, Vin);

	CGraphDlg dlg;
	dlg.SetData(m_rlCircuit.getTimeArray(), m_rlCircuit.getCurrentArray(), _T("RL 회로 결과"));
	dlg.DoModal();
}


void CCircuitSimulatorDlg::OnBnClickedBtnGraphRc()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strR, strC, strVin;
	GetDlgItemText(IDC_EDIT_RC_R, strR);
	GetDlgItemText(IDC_EDIT_RC_C, strC);
	GetDlgItemText(IDC_EDIT_RC_V, strVin);

	USES_CONVERSION;

	double R, C, Vin;

	try {
		R = std::stod(std::string(CT2A(strR)));
		C = std::stod(std::string(CT2A(strC)));
		Vin = std::stod(std::string(CT2A(strVin)));
	}
	catch (...) {
		AfxMessageBox(_T("숫자가 올바르지 않습니다. 예: 10, 2.5, 3.0e-2 형식으로 입력해주세요."));
		return;
	}

	if (R <= 0 || C <= 0 || Vin <= 0) {
		AfxMessageBox(_T("R, C, Vin 값을 모두 양수로 입력해주세요."));
		return;
	}

	CString msg;
	msg.Format(_T("RC 시뮬레이션 실행:\nR=%.4f\nC=%.6f\nVin=%.3f"), R, C, Vin);
	AfxMessageBox(msg);

	m_rcCircuit.simulate(R, C, Vin);

	CGraphDlg dlg;
	dlg.SetData(m_rcCircuit.getTimeArray(), m_rcCircuit.getCurrentArray(), _T("RC 회로 결과"));
	dlg.DoModal();
}


void CCircuitSimulatorDlg::OnBnClickedGroupSelect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCircuitSimulatorDlg::OnBnClickedGroupRl()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItem(IDC_GROUP_SELECT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_GROUP_RL)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_GROUP_RC)->ShowWindow(SW_HIDE);
}


void CCircuitSimulatorDlg::OnBnClickedGroupRc()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItem(IDC_GROUP_SELECT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_GROUP_RL)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_GROUP_RC)->ShowWindow(SW_SHOW);
}

BOOL CCircuitSimulatorDlg::OnInitDialog()
{
	// 기본 상태: 회로 선택 화면만 보여줌
	GetDlgItem(IDC_GROUP_SELECT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_GROUP_RL)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_GROUP_RC)->ShowWindow(SW_HIDE);

	if (m_modeSet) {
		if (m_isRLMode) {
			OnBnClickedBtnRl(); // 자동 전환
		}
		else {
			OnBnClickedBtnRc();
		}
	}

	return TRUE;
}
