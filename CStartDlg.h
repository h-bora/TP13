#pragma once

#include "afxdialogex.h"

class CStartDlg : public CDialogEx
{
    DECLARE_DYNAMIC(CStartDlg)         
    DECLARE_MESSAGE_MAP()

public:
    CStartDlg(CWnd* pParent = nullptr);   // ������
    virtual ~CStartDlg(); // �Ҹ��� 

#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_TP13_DIALOG };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ����

public:
    afx_msg void OnBnClickedBtnStart();    // START ��ư Ŭ�� �ڵ鷯
};
