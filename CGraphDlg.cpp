// CGraphDlg.cpp: 구현 파일
//

#include "pch.h"
#include "TP13.h"
#include "CGraphDlg.h"
#include "afxdialogex.h"
#include <algorithm>

// 동적 클래스 선언
IMPLEMENT_DYNAMIC(CGraphDlg, CDialogEx)

CGraphDlg::CGraphDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GRAPH_DIALOG, pParent)
{
}

CGraphDlg::~CGraphDlg()
{
}

void CGraphDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGraphDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()

void CGraphDlg::SetData(const std::vector<double>& time, const std::vector<double>& values, const CString& title)
{
	m_time = time;
	m_values = values;
	m_title = title;
}

void CGraphDlg::OnPaint()
{
	CPaintDC dc(this);
	DrawSimpleGraph(&dc);
}

void CGraphDlg::DrawSimpleGraph(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);

	// 여백 설정
	int margin = 40;
	int graphWidth = rect.Width() - 2 * margin;
	int graphHeight = rect.Height() - 2 * margin;

	// 축 그리기
	pDC->MoveTo(margin, rect.bottom - margin);
	pDC->LineTo(rect.right - margin, rect.bottom - margin); // x축
	pDC->MoveTo(margin, rect.bottom - margin);
	pDC->LineTo(margin, margin); // y축

	// 데이터가 없을 경우 리턴
	if (m_time.empty() || m_values.empty()) return;

	// 값의 범위 계산
	double xMin = m_time.front();
	double xMax = m_time.back();
	double yMin = *std::min_element(m_values.begin(), m_values.end());
	double yMax = *std::max_element(m_values.begin(), m_values.end());
	//if (yMin == yMax) yMax += 1.0; // 같은 값만 있을 경우 대비
	if (yMax - yMin < 1e-5) {       // y축 범위가 너무 좁을 경우
		yMin -= 0.5;
		yMax += 0.5;
	}
    
	// 좌표 변환 후 선 그리기
	for (size_t i = 1; i < m_time.size(); ++i)
	{
		int x1 = margin + static_cast<int>((m_time[i - 1] - xMin) / (xMax - xMin) * graphWidth);
		int y1 = rect.bottom - margin - static_cast<int>((m_values[i - 1] - yMin) / (yMax - yMin) * graphHeight);
		int x2 = margin + static_cast<int>((m_time[i] - xMin) / (xMax - xMin) * graphWidth);
		int y2 = rect.bottom - margin - static_cast<int>((m_values[i] - yMin) / (yMax - yMin) * graphHeight);
		pDC->MoveTo(x1, y1);
		pDC->LineTo(x2, y2);
	}

	// 제목 출력
	pDC->TextOutW(margin, margin / 2, m_title);
	// X축 라벨
	pDC->TextOutW(rect.right / 2, rect.bottom - margin + 5, _T("시간 (s)"));
    // Y축 라벨 (세로로 회전 안 하고 그냥 위쪽에 )
	pDC->TextOutW(5, margin / 2, _T("전류 (A)"));
}
