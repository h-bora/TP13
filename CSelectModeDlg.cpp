// CSelectModeDlg.cpp: 구현 파일
//

#include "pch.h"
#include "TP13.h"
#include "afxdialogex.h"
#include "CSelectModeDlg.h"
#include "CImageProcessDlg.h"

// CSelectModeDlg 대화 상자

IMPLEMENT_DYNAMIC(CSelectModeDlg, CDialogEx)

CSelectModeDlg::CSelectModeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SELECT_MODE, pParent)
{

}

CSelectModeDlg::~CSelectModeDlg()
{
}

void CSelectModeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSelectModeDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_IMAGEPROCESS, &CSelectModeDlg::OnBnClickedBtnImageprocess)
END_MESSAGE_MAP()


// CSelectModeDlg 메시지 처리기

void CSelectModeDlg::OnBnClickedBtnImageprocess()
{
	CImageProcessDlg dlg;
	dlg.DoModal();
}
