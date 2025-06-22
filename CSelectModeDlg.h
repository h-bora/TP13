#pragma once
#include "afxdialogex.h"


// CSelectModeDlg 대화 상자

class CSelectModeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSelectModeDlg)

public:
	CSelectModeDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CSelectModeDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SELECT_MODE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
protected:
	// RC 회로용 입력 컨트롤 변수
	CEdit m_editRcR;
	CEdit m_editRcC;
	CEdit m_editRcV;

	// RL 회로용 입력 컨트롤 변수
	CEdit m_editRlR;
	CEdit m_editRlL;
	CEdit m_editRlV;

public:
	afx_msg void OnBnClickedBtnImageprocess();
	afx_msg void OnBnClickedBtnGraphRC();  // RC 시뮬레이션 그래프 출력
	afx_msg void OnBnClickedBtnGraphRL();  // RL 시뮬레이션 그래프 출력
};
