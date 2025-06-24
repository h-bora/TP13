
// TP13.cpp: 애플리케이션에 대한 클래스 동작을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "TP13.h"
#include "CSelectModeDlg.h"
#include "CStartDlg.h"
#include "TP13Dlg.h"
#include "CImageProcessDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTP13App

BEGIN_MESSAGE_MAP(CTP13App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CTP13App 생성

CTP13App::CTP13App()
{
	// 다시 시작 관리자 지원
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}


// 유일한 CTP13App 개체입니다.

CTP13App theApp;


// CTP13App 초기화

BOOL CTP13App::InitInstance()
{
    INITCOMMONCONTROLSEX InitCtrls;
    InitCtrls.dwSize = sizeof(InitCtrls);
    InitCtrls.dwICC = ICC_WIN95_CLASSES;
    InitCommonControlsEx(&InitCtrls);

    CWinApp::InitInstance();
    AfxEnableControlContainer();

    CShellManager* pShellManager = new CShellManager;
    CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));
    SetRegistryKey(_T("TP13"));

    CStartDlg dlg;
    m_pMainWnd = &dlg;
    dlg.DoModal();  

    if (pShellManager != nullptr)
        delete pShellManager;

#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
    ControlBarCleanUp();
#endif

    return FALSE;  
}




