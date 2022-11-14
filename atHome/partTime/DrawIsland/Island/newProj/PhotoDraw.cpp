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
	m_enDrawType = enNone;
	m_enBtnStatus = enNormal;
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
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
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

	//Gdiplus::Graphics gh(memDC.GetSafeHdc()); //构造对象
	//gh.Clear(Color::White); //清除背景
	//gh.ResetClip();
	//FontFamily  fontFamily(L"Times New Roman");
	//Gdiplus::Font font(&fontFamily, 24, FontStyleRegular, UnitPixel);
	//Gdiplus::PointF pointF;
	//CPoint cpoint;
	//GetCursorPos(&cpoint);
	//ScreenToClient(&cpoint);
	//pointF.X = cpoint.x;
	//pointF.Y = cpoint.y; 
	//SolidBrush  solidBrush(Color(50, 0, 0, 255));
	//gh.DrawString(L"9", 4, &font, pointF, &solidBrush);

	//gh.DrawString(L"Hello", -1, &font, pointF, &solidBrush);

	//gh.DrawImage(img_bkg, rcClient.left, rcClient.top, rcClient.Width(), rcClient.Height()); //绘制背景图
	dc.BitBlt(0, 0, rcClient.Width(), rcClient.Height(), &memDC, 0, 0, SRCCOPY);

	memDC.SelectObject(pOldbmp);
	DeleteObject(&bitmap);			//删除位图
	memDC.DeleteDC();					//删除DC	
	DeleteObject(pOldbmp);			//删除备份位图
}


void CPhotoDraw::OnPaint()
{
	//CPaintDC dc(this);
	//Draw(dc);
}


void CPhotoDraw::OnMouseMove(UINT nFlags, CPoint point)
{
	TRACE(_T("point x %d, y %d\n"), point.x, point.y);
	// Sleep(100);
	//1.判断是否启用的绘图模式
	//2.判断是否开始绘图（若是绘制深点的话只用BtnDown就好了）
	//3.利用vector去存储点的数据，当当前模式绘图结束后，将资源添加到相应的对象，并开始绘图
	//4.在OnDraw中通过传入的参数（利用多态，以及绘图类型，将图像绘制出来）



	CWnd::OnMouseMove(nFlags, point);
}

void CPhotoDraw::DrawSoundingPoint(CDC& dc)
{
	SetBtnStatus(enNormal);
	CRect rcClient;
	GetClientRect(&rcClient);

	CBitmap bitmap;
	bitmap.CreateCompatibleBitmap(&dc, rcClient.Width(), rcClient.Height());
	CDC memDC;
	memDC.CreateCompatibleDC(&dc);
	CBitmap* pOldbmp = memDC.SelectObject(&bitmap);
	memDC.FillSolidRect(rcClient, RGB(152, 211, 237));

	Gdiplus::Graphics gh(memDC.GetSafeHdc()); //构造对象
	//gh.Clear(Color::White); //清除背景
	//gh.ResetClip();
	FontFamily  fontFamily(L"Times New Roman");
	Gdiplus::Font font(&fontFamily, 24, FontStyleRegular, UnitPixel);
	Gdiplus::PointF pointF;
	CPoint cpoint;
	GetCursorPos(&cpoint);
	ScreenToClient(&cpoint);
	pointF.X = cpoint.x;
	pointF.Y = cpoint.y;
	SolidBrush  solidBrush(Color(50, 0, 0, 255));
	gh.DrawString(L"9", -1, &font, pointF, &solidBrush);

	//gh.DrawImage(img_bkg, rcClient.left, rcClient.top, rcClient.Width(), rcClient.Height()); //绘制背景图
	dc.BitBlt(0, 0, rcClient.Width(), rcClient.Height(), &memDC, 0, 0, SRCAND);

	memDC.SelectObject(pOldbmp);
	DeleteObject(&bitmap);			//删除位图
	memDC.DeleteDC();					//删除DC	
	DeleteObject(pOldbmp);			//删除备份位图

}

void CPhotoDraw::DrawChannelLine(CDC& dc)
{
	SetBtnStatus(enNormal);
}

void CPhotoDraw::DrawContour(CDC& dc)
{
	SetBtnStatus(enNormal);
}

void CPhotoDraw::DrawIsland(CDC& dc)
{
	SetBtnStatus(enNormal);
}

void CPhotoDraw::OnLButtonDown(UINT nFlags, CPoint point)
{
	SetBtnStatus(enLBtnisDown);
	if (m_enDrawType == enSoundingPoint)
	{
		CPaintDC dc(this);
		DrawSoundingPoint(dc);
	}
}

void CPhotoDraw::OnLButtonUp(UINT nFlags, CPoint point)
{
	SetBtnStatus(enLBtnisUp);
}