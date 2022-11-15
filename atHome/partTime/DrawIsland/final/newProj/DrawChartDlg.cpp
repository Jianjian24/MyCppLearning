// DrawChartDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "DrawChart.h"
#include "DrawChartDlg.h"
#include "afxdialogex.h"
#include "CPhotoView.h"
#include "PhotoDraw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CDrawChartDlg dialog

CDrawChartDlg::CDrawChartDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DRAWCHART_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDrawChartDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDrawChartDlg, CDialogEx)
	//ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_SOUNDINGPOINT, &CDrawChartDlg::OnBnClickedBtnSoundingpoint)
	ON_BN_CLICKED(IDC_BTN_CHANNELLINE, &CDrawChartDlg::OnBnClickedBtnChannelline)
	ON_BN_CLICKED(IDC_BTN_CONTOUR, &CDrawChartDlg::OnBnClickedBtnContour)
	ON_BN_CLICKED(IDC_BTN_ISLAND, &CDrawChartDlg::OnBnClickedBtnIsland)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()


// CDrawChartDlg message handlers

BOOL CDrawChartDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	if (!m_photoDraw.Create(NULL, NULL, WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), this, NULL))
		return -1;

	CWnd* pPosWnd = GetDlgItem(IDC_PIC_POS);
	if (pPosWnd == NULL || !::IsWindow(pPosWnd->GetSafeHwnd()))
		return FALSE;
	CRect posPictureRect;
	pPosWnd->GetWindowRect(&posPictureRect);
	ScreenToClient(&posPictureRect);
	if (::IsWindow(m_photoDraw.GetSafeHwnd()))
	{
		m_photoDraw.MoveWindow(posPictureRect);
		//CDC* pDc = pPosWnd->GetDC();
		TRACE("=====CDrawChartDlg::OnDraw\n");
		m_photoDraw.OnDraw();
	}

	return TRUE;  
}

HCURSOR CDrawChartDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CDrawChartDlg::OnEraseBkgnd(CDC* pDC)
{
	return CDialogEx::OnEraseBkgnd(pDC);
}

void CDrawChartDlg::OnBnClickedBtnSoundingpoint()
{
	CEdit* edit_control = NULL;
	edit_control = (CEdit*)GetDlgItem(IDC_EDIT_TIPS);
	CString str_set = _T("Sounding Point");
	edit_control->SetWindowTextW(str_set);

	CString strTmp;
	GetDlgItem(IDC_EDIT_SOUNDING)->GetWindowText(strTmp);
	m_photoDraw.SetDepth(_ttoi(strTmp));

	m_photoDraw.SetDrawType(enSoundingPoint);
	m_photoDraw.SetBtnStatus(enNormal);
}

void CDrawChartDlg::OnBnClickedBtnChannelline()
{
	CEdit* edit_control = NULL;
	edit_control = (CEdit*)GetDlgItem(IDC_EDIT_TIPS);
	CString str_set = _T("Channel Line");
	edit_control->SetWindowTextW(str_set);
	m_photoDraw.SetDrawType(enChannelLine);
	m_photoDraw.SetBtnStatus(enNormal);
}


void CDrawChartDlg::OnBnClickedBtnContour()
{
	CEdit* edit_control = NULL;
	edit_control = (CEdit*)GetDlgItem(IDC_EDIT_TIPS);
	CString str_set = _T("Contour");
	edit_control->SetWindowTextW(str_set);
	m_photoDraw.SetDrawType(enContour);
	m_photoDraw.SetBtnStatus(enNormal);
}

void CDrawChartDlg::OnBnClickedBtnIsland()
{
	CEdit* edit_control = NULL;
	edit_control = (CEdit*)GetDlgItem(IDC_EDIT_TIPS);
	CString str_set = _T("Island");
	edit_control->SetWindowTextW(str_set);
	m_photoDraw.SetDrawType(enIsland);
	m_photoDraw.SetBtnStatus(enNormal);
}

void CDrawChartDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_photoDraw.SetBtnStatus(enLBtnIsDown);
}

void CDrawChartDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_photoDraw.SetBtnStatus(enLBtnisUp);
	m_photoDraw.OnLButtonUp(nFlags, point);
}