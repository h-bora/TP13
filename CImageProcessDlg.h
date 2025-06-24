#pragma once
#include "afxdialogex.h"
#include "imageYUEE.h"

class CImageProcessDlg : public CDialogEx
{
    DECLARE_DYNAMIC(CImageProcessDlg)

public:
    CImageProcessDlg(CWnd* pParent = nullptr);
    virtual ~CImageProcessDlg();
    void UncheckOtherFilters(int excludeID);
    void LoadImageFromFile();

#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_IMAGE_PROCESS };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);
    virtual BOOL OnInitDialog();
    imageYUEE m_image;       // 실제 이미지 데이터 처리
    bool m_bImageLoaded;    // 이미지 불러온거 체크
    DECLARE_MESSAGE_MAP()

public:
    afx_msg void OnBnClickedBtnLoad();
    afx_msg void OnBnClickedBtnApply();
    afx_msg void OnBnClickedBtnSave();
    afx_msg void OnBnClickedBtnReset();
    afx_msg void OnBnClickedBtnBack();
    afx_msg void OnBnClickedBtnExit();
    afx_msg void OnStnClickedPicResult();
    afx_msg void OnBnClickedBtnCancel();

    afx_msg void OnCheckInvert();
    afx_msg void OnCheckBinarize();
    afx_msg void OnCheckBrightness();
    afx_msg void OnCheckSharpen();
    afx_msg void OnBnClickedBtnLoadImage();

private:
    CString m_strInputFile;
    CString m_strOutputFile;

    imageYUEE* m_imgOriginal = nullptr;
    imageYUEE* m_imgProcessed = nullptr;

    CStatic m_ctrlOriginalImage;
    CStatic m_ctrlResultImage;

    CButton m_checkInvert;
    CButton m_checkBinarize;
    CButton m_checkBrightness;
    CButton m_checkSharpen;

    CStatic m_staticFilterInfo;
};
