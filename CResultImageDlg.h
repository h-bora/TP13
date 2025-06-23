#pragma once

#include "afxdialogex.h"

class CResultImageDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CResultImageDlg)

public:
	CResultImageDlg(const CString& filePath, int mode, CWnd* pParent = nullptr);
	virtual ~CResultImageDlg();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RESULT_IMAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()

private:
	CString m_filePath;
	int m_mode;

	CStatic m_ctrlOriginal;
	CStatic m_ctrlProcessed;

public:
	afx_msg void OnBnClickedBtnClose();
	afx_msg void OnBnClickedButton4();
};