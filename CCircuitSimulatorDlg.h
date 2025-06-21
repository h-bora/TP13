#pragma once
#include "afxdialogex.h"


// CCircuitSimulatorDlg 대화 상자

class CCircuitSimulatorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCircuitSimulatorDlg)

public:
	CCircuitSimulatorDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CCircuitSimulatorDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CIRCUIT_SIMULATOR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnStnClickedStaticDesc();
};
