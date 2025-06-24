// CResultImageDlg.cpp: 구현 파일
//

#include "pch.h"
#include "TP13.h"
#include "afxdialogex.h"
#include "CResultImageDlg.h" 


// CResultImageDlg 대화 상자

IMPLEMENT_DYNAMIC(CResultImageDlg, CDialogEx)

CResultImageDlg::CResultImageDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RESULT_IMAGE, pParent)
{

}

CResultImageDlg::~CResultImageDlg()
{
}

BOOL CResultImageDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    if (m_pImage)
    {
        CStatic* pImageCtrl = (CStatic*)GetDlgItem(IDC_STATIC_RESULT_VIEW);
        if (pImageCtrl && ::IsWindow(pImageCtrl->GetSafeHwnd()))
        {
            m_pImage->drawImage(pImageCtrl->GetSafeHwnd());
        }
        else
        {
            AfxMessageBox(_T("결과 이미지 컨트롤이 유효하지 않습니다."));
        }
    }

    return TRUE;
}

void CResultImageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CResultImageDlg, CDialogEx)
    ON_COMMAND(IDD_RESULT_IMAGE, &CResultImageDlg::OnIddResultImage)
    //ON_BN_CLICKED(IDC_BTN_RESULT, &CResultImageDlg::OnIddResultImage)
END_MESSAGE_MAP()

// CResultImageDlg 메시지 처리기

void CResultImageDlg::OnIddResultImage()
{
    // TODO: 여기에 명령 처리기 코드를 추가합니다.
    AfxMessageBox(_T("결과 이미지 다이얼로그입니다."));
}
