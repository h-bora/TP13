// CImageProcessDlg.h
#pragma once

#include "afxdialogex.h"

class CImageProcessDlg : public CDialogEx
{
    DECLARE_DYNAMIC(CImageProcessDlg)

public:
    CImageProcessDlg(CWnd* pParent = nullptr);
    virtual ~CImageProcessDlg();

#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_IMAGE_PROCESS };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);
    DECLARE_MESSAGE_MAP()

public:
    afx_msg void OnBnClickedBtnLoadImage();
    afx_msg void OnBnClickedBtnApply();
    afx_msg void OnBnClickedBtnSave();
    afx_msg void OnBnClickedBtnReset();
    afx_msg void OnBnClickedBtnBack();

private:
    CString inputFilePath;
    CString outputFilePath;
};
