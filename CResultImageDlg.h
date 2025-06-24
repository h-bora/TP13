#pragma once
#include "afxdialogex.h"
#include "imageYUEE.h"  
#include "CImageProcessDlg.h"

// CResultImageDlg 대화 상자

class CResultImageDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CResultImageDlg)

public:
	CImagoprocessDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CResultImageDlg();

	enum { IDD = IDD_IMAGE_PROCESS};

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()

private:
	imageYUEE* m_pImage = nullptr;  // 이미지 객체를 저장할 포인터

public:
	void SetImage(imageYUEE* pImage) { m_pImage = pImage; }  // 외부에서 포인터 세팅
	afx_msg void OnIddResultImage();
};
