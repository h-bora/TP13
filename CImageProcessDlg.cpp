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
    if (m_imgOriginal) delete m_imgOriginal;
    if (m_imgProcessed) delete m_imgProcessed;
}

void CImageProcessDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_CHECK_INVERT, m_checkInvert);
    DDX_Control(pDX, IDC_CHECK_BINARIZE, m_checkBinarize);
    DDX_Control(pDX, IDC_CHECK_BRIGHTNESS, m_checkBrightness);
    DDX_Control(pDX, IDC_CHECK_SHARPEN, m_checkSharpen);
    DDX_Control(pDX, IDC_STATIC_FILTERINFO, m_staticFilterInfo);
    DDX_Control(pDX, IDC_PIC_ORIGINAL, m_ctrlOriginalImage);
    DDX_Control(pDX, IDC_PIC_RESULT, m_ctrlResultImage);
}

BEGIN_MESSAGE_MAP(CImageProcessDlg, CDialogEx)
    ON_BN_CLICKED(IDC_BTN_LOAD, &CImageProcessDlg::OnBnClickedBtnLoad)
    ON_BN_CLICKED(IDC_BTN_APPLY, &CImageProcessDlg::OnBnClickedBtnApply)
    ON_BN_CLICKED(IDC_BTN_SAVE, &CImageProcessDlg::OnBnClickedBtnSave)
    ON_BN_CLICKED(IDC_BTN_RESET, &CImageProcessDlg::OnBnClickedBtnReset)
    ON_BN_CLICKED(IDC_BTN_BACK, &CImageProcessDlg::OnBnClickedBtnBack)
    ON_BN_CLICKED(IDC_BTN_EXIT, &CImageProcessDlg::OnBnClickedBtnExit)
    ON_STN_CLICKED(IDC_PIC_RESULT, &CImageProcessDlg::OnStnClickedPicResult)
    ON_BN_CLICKED(IDC_BTN_CANCEL, &CImageProcessDlg::OnBnClickedBtnCancel)
    ON_BN_CLICKED(IDC_CHECK_INVERT, &CImageProcessDlg::OnCheckInvert)
    ON_BN_CLICKED(IDC_CHECK_BINARIZE, &CImageProcessDlg::OnCheckBinarize)
    ON_BN_CLICKED(IDC_CHECK_BRIGHTNESS, &CImageProcessDlg::OnCheckBrightness)
    ON_BN_CLICKED(IDC_CHECK_SHARPEN, &CImageProcessDlg::OnCheckSharpen)
    ON_BN_CLICKED(IDC_BTN_LOADIMAGE, &CImageProcessDlg::OnBnClickedBtnLoadImage)
END_MESSAGE_MAP()

BOOL CImageProcessDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();
    m_strInputFile = _T("");
    m_bImageLoaded = false;
    return TRUE;
}

void CImageProcessDlg::OnBnClickedBtnLoad()
{
    CFileDialog dlg(TRUE);
    if (dlg.DoModal() == IDOK)
    {
        m_strInputFile = dlg.GetPathName();

        if (m_imgOriginal) delete m_imgOriginal;
        if (m_imgProcessed) delete m_imgProcessed;

        m_imgOriginal = new imageYUEE(m_strInputFile);
        m_imgProcessed = nullptr;  // 아직 필터 안 씌웠으므로 null 처리

        m_imgOriginal->drawImage(m_ctrlOriginalImage.GetSafeHwnd());

        // 결과 이미지 창 초기화 (흰 배경)
        CDC* pDC = m_ctrlResultImage.GetDC();
        CRect rect;
        m_ctrlResultImage.GetClientRect(&rect);
        pDC->FillSolidRect(&rect, RGB(255, 255, 255));
        m_ctrlResultImage.ReleaseDC(pDC);

        m_bImageLoaded = true;
        m_staticFilterInfo.SetWindowText(_T("적용 필터: 없음"));
    }
}

void CImageProcessDlg::OnBnClickedBtnApply()
{
    if (!m_bImageLoaded)
    {
        AfxMessageBox(_T("이미지를 불러온 뒤 필터를 적용해주세요."));
        return;
    }

    int mode = -1;
    if (m_checkInvert.GetCheck()) mode = 1;
    else if (m_checkBinarize.GetCheck()) mode = 0;
    else if (m_checkBrightness.GetCheck()) mode = 2;
    else if (m_checkSharpen.GetCheck()) mode = 3;

    if (mode == -1) {
        AfxMessageBox(_T("처리 기법을 선택해주세요."));
        return;
    }

    m_imgProcessed = new imageYUEE(*m_imgOriginal);  // 원본 복사해서 처리
    m_imgProcessed->imageProc(mode);
    m_imgProcessed->drawImage(m_ctrlResultImage.GetSafeHwnd());

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
    if (!m_imgProcessed) {
        AfxMessageBox(_T("저장할 이미지가 없습니다. 먼저 필터를 적용해주세요."));
        return;
    }

    CFileDialog dlg(FALSE, _T("pgm"), _T("output.pgm"),
        OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
        _T("PGM Files (*.pgm)|*.pgm||"));

    if (dlg.DoModal() == IDOK)
    {
        CString outputFile = dlg.GetPathName();
        if (m_imgProcessed->imageWrite(outputFile)) {
            AfxMessageBox(_T("이미지가 저장되었습니다."));
        }
        else {
            AfxMessageBox(_T("이미지 저장에 실패했습니다."));
        }
    }
}

void CImageProcessDlg::OnBnClickedBtnReset()
{
    m_checkInvert.SetCheck(BST_UNCHECKED);
    m_checkBinarize.SetCheck(BST_UNCHECKED);
    m_checkBrightness.SetCheck(BST_UNCHECKED);
    m_checkSharpen.SetCheck(BST_UNCHECKED);
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
    // 필요시 코드 작성
}

void CImageProcessDlg::OnBnClickedBtnCancel()
{
    OnOK();
}

void CImageProcessDlg::OnCheckInvert()
{
    UncheckOtherFilters(IDC_CHECK_INVERT);
}

void CImageProcessDlg::OnCheckBinarize()
{
    UncheckOtherFilters(IDC_CHECK_BINARIZE);
}

void CImageProcessDlg::OnCheckBrightness()
{
    UncheckOtherFilters(IDC_CHECK_BRIGHTNESS);
}

void CImageProcessDlg::OnCheckSharpen()
{
    UncheckOtherFilters(IDC_CHECK_SHARPEN);
}

void CImageProcessDlg::UncheckOtherFilters(int excludeID)
{
    CButton* filters[] = { &m_checkInvert, &m_checkBinarize, &m_checkBrightness, &m_checkSharpen };
    int ids[] = { IDC_CHECK_INVERT, IDC_CHECK_BINARIZE, IDC_CHECK_BRIGHTNESS, IDC_CHECK_SHARPEN };

    for (int i = 0; i < 4; ++i)
    {
        if (ids[i] != excludeID)
            filters[i]->SetCheck(BST_UNCHECKED);
    }
}

void CImageProcessDlg::LoadImageFromFile()
{
    // 파일 다이얼로그 열기: 이미지 확장자 필터 적용
    CFileDialog dlg(TRUE, _T("PGM"), NULL, OFN_FILEMUSTEXIST | OFN_HIDEREADONLY,
        _T("PGM Files (*.pgm)|*.pgm|모든 파일 (*.*)|*.*||"));

    if (dlg.DoModal() == IDOK)
    {
        CString filePath = dlg.GetPathName();
        // 이미지 로드 함수 호출 (예: drawImage 또는 loadPGMImage 등으로 구현되어 있어야 함)
        // 예: imageYUEE.loadPGM(filePath);
        // 또는 파일 경로 저장해두기
        AfxMessageBox(_T("선택된 파일: ") + filePath);
    }
}

void CImageProcessDlg::OnBnClickedBtnLoadImage()
{
    CFileDialog dlg(TRUE);
    if (dlg.DoModal() == IDOK)
    {
        m_strInputFile = dlg.GetPathName();

        if (m_imgOriginal) delete m_imgOriginal;
        if (m_imgProcessed) delete m_imgProcessed;

        m_imgOriginal = new imageYUEE(m_strInputFile);
        m_imgProcessed = nullptr; // 아직 필터 적용 안 했으므로 null

        m_imgOriginal->drawImage(m_ctrlOriginalImage.GetSafeHwnd());

        // 결과 이미지 창 초기화 (흰 배경)
        CDC* pDC = m_ctrlResultImage.GetDC();
        CRect rect;
        m_ctrlResultImage.GetClientRect(&rect);
        pDC->FillSolidRect(&rect, RGB(255, 255, 255));
        m_ctrlResultImage.ReleaseDC(pDC);

        m_bImageLoaded = true;
        m_staticFilterInfo.SetWindowText(_T("적용 필터: 없음"));
    }
} 