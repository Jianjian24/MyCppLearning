// PhotoDraw.cpp : implementation file
//

#include "pch.h"
#include "DrawChart.h"
#include "afxdialogex.h"
#include "PhotoDraw.h"


// CPhotoDraw dialog

IMPLEMENT_DYNAMIC(CPhotoDraw, CDialogEx)

CPhotoDraw::CPhotoDraw(CWnd* pParent /*=nullptr*/)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif



}

CPhotoDraw::~CPhotoDraw()
{
}

void CPhotoDraw::OnDraw()
{
	CPaintDC dc(this);
	Draw(dc);
}

void CPhotoDraw::SetDrawType(EnDrawType type)
{
	m_enDrawType = type;
}

//void CPhotoDraw::OnMouseMove(UINT nFlags, CPoint point)
//{
//	TRACE(_T("point x %d, y %d\n"), point.x, point.y);
//}

BOOL CPhotoDraw::OnInitDialog()
{
	TRACE("=====CPhotoDraw::OnInitDialog\n");
	//Invalidate(FALSE);
	//UpdateWindow();
	return 0;
}

void CPhotoDraw::DoDataExchange(CDataExchange* pDX)
{
	CWnd::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPhotoDraw, CWnd)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


BOOL CPhotoDraw::OnEraseBkgnd(CDC* pDC)
{
	return TRUE;
	//return CView::OnEraseBkgnd(pDC);
}

// CPhotoDraw message handlers
void CPhotoDraw::Draw(CDC& dc)
{
	CRect rcClient;
	GetClientRect(&rcClient);

	CBitmap bitmap;
	bitmap.CreateCompatibleBitmap(&dc, rcClient.Width(), rcClient.Height());
	CDC memDC;
	memDC.CreateCompatibleDC(&dc);
	CBitmap* pOldbmp = memDC.SelectObject(&bitmap);
	memDC.FillSolidRect(rcClient, RGB(152, 211, 237));

	//Graphics gh(memDC.GetSafeHdc()); //构造对象
	//gh.Clear(Color::White); //清除背景
	//gh.ResetClip();

	//gh.DrawImage(img_bkg, rcClient.left, rcClient.top, rcClient.Width(), rcClient.Height()); //绘制背景图
	dc.BitBlt(0, 0, rcClient.Width(), rcClient.Height(), &memDC, 0, 0, SRCCOPY);

	memDC.SelectObject(pOldbmp);
	DeleteObject(&bitmap);			//删除位图
	memDC.DeleteDC();					//删除DC	
	DeleteObject(pOldbmp);			//删除备份位图
}


void CPhotoDraw::OnPaint()
{
	CPaintDC dc(this);
	Draw(dc);
}


void CPhotoDraw::OnMouseMove(UINT nFlags, CPoint point)
{
	TRACE(_T("point x %d, y %d\n"), point.x, point.y);
	Sleep(100);
	//CWnd::OnMouseMove(nFlags, point);
}
