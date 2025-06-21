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
public:
	afx_msg void OnBnClickedBtnImageprocess();
};
