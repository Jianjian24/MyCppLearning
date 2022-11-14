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

	if (!m_photoDraw.Create(NULL, NULL, WS_CHILD|WS_VISIBLE, CRect(0,0,0,0),this, NULL))
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
		CDC* pDc = pPosWnd->GetDC();
		m_photoDraw.OnDraw();
	}

	//CWnd* pwnd = GetDlgItem(IDC_PIC_POS);
	//CDC* pDC = pwnd->GetWindowDC();//获取控件dc
	//CDC dcMen, dcBkgnd;
	//CBitmap bitmapTemp, * pOldBitmap;
	//bitmapTemp.LoadBitmap(IDB_BMP_PIC);
	//dcMen.CreateCompatibleDC(pDC);
	//pOldBitmap = dcMen.SelectObject(&bitmapTemp);

	////绘图代码移到这

	//pDC->BitBlt(0, 0, Imgrc.Width(), Imgrc.Height(), &dcMen, 0, 0, SRCCOPY);//绘制图片到主DC
	//dcMen.SelectObject(pOldBitmap);//内存复位
	//bitmapTemp.DeleteObject();
	//ReleaseDC(pDC);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

HCURSOR CDrawChartDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CDrawChartDlg::OnEraseBkgnd(CDC* pDC)
{
	return TRUE;
}

void CDrawChartDlg::OnBnClickedBtnSoundingpoint()
{
	m_photoDraw.SetDrawType(enSoundingPoint);
}

void CDrawChartDlg::OnBnClickedBtnChannelline()
{
	m_photoDraw.SetDrawType(enChannelLine);
}


void CDrawChartDlg::OnBnClickedBtnContour()
{
	m_photoDraw.SetDrawType(enContour);
}

void CDrawChartDlg::OnBnClickedBtnIsland()
{
	m_photoDraw.SetDrawType(enIsland);
}

void CDrawChartDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_photoDraw.SetBtnStatus(enLBtnisDown);
}

void CDrawChartDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_photoDraw.SetBtnStatus(enLBtnisUp);
}