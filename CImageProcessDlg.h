#pragma once

#include "afxdialogex.h"
#include "imageYUEE.h"

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
    afx_msg void OnBnClickedBtnLoad();
    afx_msg void OnBnClickedBtnApply();
    afx_msg void OnBnClickedBtnSave();
    afx_msg void OnBnClickedBtnReset();
    afx_msg void OnBnClickedBtnBack();
    afx_msg void OnBnClickedBtnExit();
    afx_msg void OnStnClickedPicResult();

private:
    CString m_strInputFile;
    CString m_strOutputFile;

    imageYUEE* m_imgOriginal = nullptr;    // 원본 이미지 포인터
	imageYUEE* m_imgProcessed = nullptr;   // 처리 이미지 포인터

    CStatic m_ctrlOriginalImage;
    CStatic m_ctrlResultImage;

    CButton m_checkInvert;
    CButton m_checkBinarize;
    CButton m_checkBrightness;
    CButton m_checkSharpen;
    virtual BOOL OnInitDialog();

   // CStatic m_staticFilterText;
    CStatic m_staticFilterInfo;
};