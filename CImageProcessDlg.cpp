#include "pch.h"
#include "framework.h"
#include "TP13.h"
#include "CImageProcessDlg.h"
#include "afxdialogex.h"
#include "imageYUEE.h"

IMPLEMENT_DYNAMIC(CImageProcessDlg, CDialogEx)

CImageProcessDlg::CImageProcessDlg(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_IMAGE_PROCESS, pParent)
{
}

CImageProcessDlg::~CImageProcessDlg()
{
}

void CImageProcessDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    //DDX_Control(pDX, IDC_STATIC_ORIGINAL, m_ctrlOriginalImage);
    DDX_Control(pDX, IDC_PIC_ORIGINAL, m_ctrlOriginalImage);  
    DDX_Control(pDX, IDC_STATIC_RESULT, m_ctrlResultImage);     
    DDX_Control(pDX, IDC_CHECK_INVERT, m_checkInvert);          
    DDX_Control(pDX, IDC_CHECK_BRIGHTNESS, m_checkBrightness);  
    DDX_Control(pDX, IDC_CHECK_SHARPEN, m_checkSharpen);        
    DDX_Control(pDX, IDC_STATIC_FILTERINFO, m_staticFilterInfo); 
}

BEGIN_MESSAGE_MAP(CImageProcessDlg, CDialogEx)
    ON_BN_CLICKED(IDC_BTN_LOAD, &CImageProcessDlg::OnBnClickedBtnLoad)
    ON_BN_CLICKED(IDC_BTN_APPLY, &CImageProcessDlg::OnBnClickedBtnApply)
    ON_BN_CLICKED(IDC_BTN_SAVE, &CImageProcessDlg::OnBnClickedBtnSave)
    ON_BN_CLICKED(IDC_BTN_RESET, &CImageProcessDlg::OnBnClickedBtnReset)
    ON_BN_CLICKED(IDC_BTN_BACK, &CImageProcessDlg::OnBnClickedBtnBack)
    ON_BN_CLICKED(IDC_BTN_EXIT, &CImageProcessDlg::OnBnClickedBtnExit)
    ON_STN_CLICKED(IDC_PIC_RESULT, &CImageProcessDlg::OnStnClickedPicResult)
END_MESSAGE_MAP()

BOOL CImageProcessDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();
    m_strInputFile = _T("");
    return TRUE;
}

void CImageProcessDlg::OnBnClickedBtnLoad()
{
    CFileDialog dlg(TRUE);
    if (dlg.DoModal() == IDOK)
    {
        m_strInputFile = dlg.GetPathName();
        imageYUEE img(m_strInputFile);
        img.drawImage(m_ctrlOriginalImage.GetSafeHwnd());
    }
}

void CImageProcessDlg::OnBnClickedBtnApply()
{
    if (m_strInputFile.IsEmpty()) {
        AfxMessageBox(_T("먼저 이미지를 불러와 주세요."));
        return;
    }

    imageYUEE img(m_strInputFile);
    int mode = -1;

    if (m_checkInvert.GetCheck()) mode = 1;
    else if (m_checkBinarize.GetCheck()) mode = 0;
    else if (m_checkBrightness.GetCheck()) mode = 2;
    else if (m_checkSharpen.GetCheck()) mode = 3;

    if (mode == -1) {
        AfxMessageBox(_T("처리 기법을 선택해주세요."));
        return;
    }

    img.imageProc(mode);
    img.drawImage(m_ctrlResultImage.GetSafeHwnd());

    CString filterName;
    switch (mode) {
    case 0: filterName = _T("이진화"); break;
    case 1: filterName = _T("반전"); break;
    case 2: filterName = _T("밝기 조절"); break;
    case 3: filterName = _T("샤프닝"); break;
    }

    m_staticFilterInfo.SetWindowText(_T("적용 필터: ") + filterName);
}

void CImageProcessDlg::OnBnClickedBtnSave()
{
    CFileDialog dlg(FALSE);
    if (dlg.DoModal() == IDOK)
    {
        CString outputFile = dlg.GetPathName();
        imageYUEE img(m_strInputFile);
        img.imageProc(1); // 예시로 반전 처리 후 저장
        img.imageWrite(outputFile);
        AfxMessageBox(_T("이미지가 저장되었습니다."));
    }
}

void CImageProcessDlg::OnBnClickedBtnReset()
{
    m_checkInvert.SetCheck(BST_UNCHECKED);
    m_checkBinarize.SetCheck(BST_UNCHECKED);
    m_checkBrightness.SetCheck(BST_UNCHECKED);
    m_checkSharpen.SetCheck(BST_UNCHECKED);
   // m_staticFilterText.SetWindowText(_T("적용 필터: 없음"));
    m_staticFilterInfo.SetWindowText(_T("적용 필터: 없음"));

}

void CImageProcessDlg::OnBnClickedBtnBack()
{
    EndDialog(IDCANCEL);
}

void CImageProcessDlg::OnBnClickedBtnExit()
{
    OnOK();
}

void CImageProcessDlg::OnStnClickedPicResult()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
