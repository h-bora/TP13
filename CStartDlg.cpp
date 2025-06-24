#include "pch.h"
#include "TP13.h"
#include "CStartDlg.h"
#include "afxdialogex.h"
#include "CSelectModeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNAMIC(CStartDlg, CDialogEx)

CStartDlg::CStartDlg(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_TP13_DIALOG, pParent)
{
}
CStartDlg::~CStartDlg()
{
}

void CStartDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CStartDlg, CDialogEx)
    ON_BN_CLICKED(IDC_BTN_START, &CStartDlg::OnBnClickedBtnStart)
END_MESSAGE_MAP()

void CStartDlg::OnBnClickedBtnStart()
{
    ShowWindow(SW_HIDE);

    CSelectModeDlg dlg;
    dlg.DoModal();

    EndDialog(IDCANCEL);
}
