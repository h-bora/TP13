#pragma once

#include "afxdialogex.h"

class CStartDlg : public CDialogEx
{
    DECLARE_DYNAMIC(CStartDlg)         
    DECLARE_MESSAGE_MAP()

public:
    CStartDlg(CWnd* pParent = nullptr);   // 생성자
    virtual ~CStartDlg(); // 소멸자 

#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_TP13_DIALOG };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원

public:
    afx_msg void OnBnClickedBtnStart();    // START 버튼 클릭 핸들러
};
