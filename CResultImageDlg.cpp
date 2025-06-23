#include "pch.h"
#include "CResultImageDlg.h"
#include "imageYUEE.h"
#include "afxdialogex.h"

IMPLEMENT_DYNAMIC(CResultImageDlg, CDialogEx)

CResultImageDlg::CResultImageDlg(const CString& filePath, int mode, CWnd* pParent)
	: CDialogEx(IDD_RESULT_IMAGE, pParent), m_filePath(filePath), m_mode(mode)
{
}

CResultImageDlg::~CResultImageDlg()
{
}

void CResultImageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_ORIGINAL_VIEW, m_ctrlOriginal);
	DDX_Control(pDX, IDC_STATIC_PROCESSED_VIEW, m_ctrlProcessed);
}

BEGIN_MESSAGE_MAP(CResultImageDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_CLOSE, &CResultImageDlg::OnBnClickedBtnClose)
	ON_BN_CLICKED(IDC_BUTTON4, &CResultImageDlg::OnBnClickedButton4)
END_MESSAGE_MAP()

BOOL CResultImageDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	imageYUEE imgOriginal(m_filePath);
	imgOriginal.drawImage(m_ctrlOriginal.GetSafeHwnd());

	imageYUEE imgProcessed(m_filePath);
	imgProcessed.imageProc(m_mode);
	imgProcessed.drawImage(m_ctrlProcessed.GetSafeHwnd());

	return TRUE;
}

void CResultImageDlg::OnBnClickedBtnClose()
{
	EndDialog(IDCANCEL);
}
void CResultImageDlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
