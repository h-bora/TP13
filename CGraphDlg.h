#pragma once

#include "afxdialogex.h"
#include <vector>

class CGraphDlg : public CDialogEx
{
    DECLARE_DYNAMIC(CGraphDlg)

public:
    CGraphDlg(CWnd* pParent = nullptr);
    virtual ~CGraphDlg();

    void SetData(const std::vector<double>& time, const std::vector<double>& values, const CString& title);

#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_GRAPH_DIALOG };
 
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);
    afx_msg void OnPaint();
    DECLARE_MESSAGE_MAP()

private:
    std::vector<double> m_time;
    std::vector<double> m_values;
    CString m_title;

    void DrawSimpleGraph(CDC* pDC);
};
