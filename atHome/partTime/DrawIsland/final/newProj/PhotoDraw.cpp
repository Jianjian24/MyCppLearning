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
	Invalidate();
}

void CPhotoDraw::SetDrawType(EnDrawType type)
{
	m_enDrawType = type;
}

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


// CPhotoDraw message handlers
void CPhotoDraw::Draw(CDC& dc)
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

	//绘制等深点
	for (int i = 0; i < m_sp.m_size; ++i)
	{
		FontFamily  fontFamily(L"Times New Roman");
		Gdiplus::Font font(&fontFamily, 12, FontStyleRegular, UnitPixel);
		Gdiplus::PointF pointF;

		pointF.X = m_sp.m_longitude[i];
		pointF.Y = m_sp.m_latitude[i];
		SolidBrush  solidBrush(Color(200, 0,0 ,0));
		CString szTemp;
		szTemp.Format(_T("%d"), m_sp.m_depth[i]);
		WCHAR *pBuf = szTemp.GetBuffer(szTemp.GetLength());
		szTemp.ReleaseBuffer();
		gh.DrawString(pBuf, szTemp.GetLength(), &font, pointF, &solidBrush);
	}
	//绘制航道线
	Gdiplus::Pen clPen(Color(200, 0, 0, 0));
	clPen.SetDashStyle(DashStyleDash);
	int indexNow = 0;
	Gdiplus::Point *clPoint = nullptr;

	for (auto it = m_cl.m_vecCountSection.begin(); it != m_cl.m_vecCountSection.end(); ++it)
	{
		if (clPoint)
			delete[] clPoint;

		clPoint = new Point[*it];
		for (int i = 0; i < *it; ++i)
		{
			clPoint[i].X = m_cl.m_longitude[indexNow];
			clPoint[i].Y = m_cl.m_latitude[indexNow];
			indexNow++;
		}

		gh.DrawCurve(&clPen, clPoint, *it);
	}

	//绘制等深线
	Gdiplus::Pen ctPen(Color(200, 255, 242, 157));
	clPen.SetDashStyle(DashStyleDash);
	indexNow = 0;
	Gdiplus::Point *ctPoint = nullptr;
	for (auto it = m_ct.m_vecCountSection.begin(); it != m_ct.m_vecCountSection.end(); ++it)
	{
		if (ctPoint)
			delete[] ctPoint;

		ctPoint = new Point[*it];
		for (int i = 0; i < *it; ++i)
		{
			ctPoint[i].X = m_ct.m_longitude[indexNow];
			ctPoint[i].Y = m_ct.m_latitude[indexNow];
			indexNow++;
		}
		TRACE(_T("====indexNow : %d\n"), indexNow);
		TRACE(L"run here!====@@@@@@@@@@@@@@@@@@@@======\n");

		gh.DrawCurve(&ctPen, ctPoint, *it);
	}

	//绘制小岛
	indexNow = 0;
	SolidBrush islandBrush(Color(200, 203, 199, 131)); //在GDI+中颜色值，没有RGB（）构造，只能用Color（）构造
	Gdiplus::Point *islandPoint = nullptr;
	for (auto it = m_island.m_vecCountSection.begin(); it != m_island.m_vecCountSection.end(); ++it)
	{
		if (islandPoint)
			delete[] islandPoint;

		islandPoint = new Point[*it];
		for (int i = 0; i < *it; ++i)
		{
			islandPoint[i].X = m_island.m_longitude[indexNow];
			islandPoint[i].Y = m_island.m_latitude[indexNow];
			indexNow++;
		}
		gh.FillClosedCurve(&islandBrush, islandPoint, *it);
	}


	//gh.DrawImage(img_bkg, rcClient.left, rcClient.top, rcClient.Width(), rcClient.Height()); //绘制背景图
	dc.BitBlt(0, 0, rcClient.Width(), rcClient.Height(), &memDC, 0, 0, SRCCOPY);

	memDC.SelectObject(pOldbmp);
	DeleteObject(&bitmap);				//删除位图
	memDC.DeleteDC();					//删除DC	
	DeleteObject(pOldbmp);				//删除备份位图
}


void CPhotoDraw::OnPaint()
{
	//CPaintDC dc(this);
	//Draw(dc);
}

void CPhotoDraw::OnLButtonDown(UINT nFlags, CPoint point)
{
	//::SetFocus(m_hWnd);
	SetBtnStatus(enLBtnIsDown);

	if (m_enDrawType == enSoundingPoint)
	{
		Gdiplus::PointF pointF;
		CPoint cpoint;
		GetCursorPos(&cpoint);
		ScreenToClient(&cpoint);
		if (m_sp.m_size >= m_sp.m_capacity)
		{
			//开辟一个两倍大小的内存，拷贝之前的数据，释放之前的数据
			m_sp.m_capacity *= 2;
			double* tempX = new double[m_sp.m_capacity]();
			double* tempY = new double[m_sp.m_capacity]();
			int* tempDepth = new int[m_sp.m_capacity]();
			for (int i = 0; i < m_sp.m_size; ++ i)
			{
				tempX[i] = m_sp.m_longitude[i];
				tempY[i] = m_sp.m_latitude[i];
				tempDepth[i] = m_sp.m_depth[i];
			}

			delete[] m_sp.m_longitude;
			delete[] m_sp.m_latitude;
			delete[] m_sp.m_depth;

			m_sp.m_longitude = tempX;
			m_sp.m_latitude = tempY;
			m_sp.m_depth = tempDepth;
		}
		m_sp.m_longitude[m_sp.m_size] = cpoint.x;
		m_sp.m_latitude[m_sp.m_size] = cpoint.y;
		m_sp.m_depth[m_sp.m_size] = m_sp.m_inputDepth;//todo:get input
		m_sp.m_size++;

		OnDraw();
	}
}

void CPhotoDraw::OnMouseMove(UINT nFlags, CPoint point)
{
	//1.判断是否启用的绘图模式
	//2.判断是否开始绘图（若是绘制深点的话只用BtnDown就好了）
	//3.利用vector去存储点的数据，当当前模式绘图结束后，将资源添加到相应的对象，并开始绘图
	//4.在OnDraw中通过传入的参数（利用多态，以及绘图类型，将图像绘制出来）

	if (m_enBtnStatus == enLBtnIsDown && m_enDrawType == enChannelLine)
	{
		TRACE(L"run here!====OnMouseMove======\n");

		if (m_cl.m_size >= m_cl.m_capacity)
		{
			//开辟一个两倍大小的内存，拷贝之前的数据，释放之前的数据
			m_cl.m_capacity *= 2;
			double* tempX = new double[m_cl.m_capacity]();
			double* tempY = new double[m_cl.m_capacity]();
			int* tempDepth = new int[m_cl.m_capacity]();
			for (int i = 0; i < m_cl.m_size; ++i)
			{
				tempX[i] = m_cl.m_longitude[i];
				tempY[i] = m_cl.m_latitude[i];
			}

			delete[] m_cl.m_longitude;
			delete[] m_cl.m_latitude;

			m_cl.m_longitude = tempX;
			m_cl.m_latitude = tempY;
		}
		m_cl.m_longitude[m_cl.m_size] = point.x;
		m_cl.m_latitude[m_cl.m_size] = point.y;
		m_cl.m_size++;
		m_cl.m_section++;
	}

	if (m_enBtnStatus == enLBtnIsDown && m_enDrawType == enIsland)
	{
		TRACE(L"run here!====OnMouseMove======\n");

		if (m_island.m_size >= m_island.m_capacity)
		{
			//开辟一个两倍大小的内存，拷贝之前的数据，释放之前的数据
			m_island.m_capacity *= 2;
			double* tempX = new double[m_island.m_capacity]();
			double* tempY = new double[m_island.m_capacity]();
			int* tempDepth = new int[m_island.m_capacity]();
			for (int i = 0; i < m_island.m_size; ++i)
			{
				tempX[i] = m_island.m_longitude[i];
				tempY[i] = m_island.m_latitude[i];
			}

			delete[] m_island.m_longitude;
			delete[] m_island.m_latitude;

			m_island.m_longitude = tempX;
			m_island.m_latitude = tempY;
		}
		m_island.m_longitude[m_island.m_size] = point.x;
		m_island.m_latitude[m_island.m_size] = point.y;
		m_island.m_size++;
		m_island.m_section++;
	}

	if (m_enBtnStatus == enLBtnIsDown && m_enDrawType == enContour)
	{
		TRACE(L"run here!====OnMouseMove======\n");

		if (m_ct.m_size >= m_ct.m_capacity)
		{
			//开辟一个两倍大小的内存，拷贝之前的数据，释放之前的数据
			m_ct.m_capacity *= 2;
			double* tempX = new double[m_ct.m_capacity]();
			double* tempY = new double[m_ct.m_capacity]();
			int* tempDepth = new int[m_ct.m_capacity]();
			for (int i = 0; i < m_ct.m_size; ++i)
			{
				tempX[i] = m_ct.m_longitude[i];
				tempY[i] = m_ct.m_latitude[i];
			}

			delete[] m_ct.m_longitude;
			delete[] m_ct.m_latitude;

			m_ct.m_longitude = tempX;
			m_ct.m_latitude = tempY;
		}
		m_ct.m_longitude[m_ct.m_size] = point.x;
		m_ct.m_latitude[m_ct.m_size] = point.y;
		m_ct.m_size++;
		m_ct.m_section++;
	}

	CWnd::OnMouseMove(nFlags, point);
}

void CPhotoDraw::OnLButtonUp(UINT nFlags, CPoint point)
{
	SetBtnStatus(enLBtnisUp);
	switch (m_enDrawType)
	{
	case enNone:
		break;
	case enSoundingPoint:
		break;
	case enChannelLine:
	{
		if (m_cl.m_size >= m_cl.m_capacity)
		{
			//开辟一个两倍大小的内存，拷贝之前的数据，释放之前的数据
			m_cl.m_capacity *= 2;
			double* tempX = new double[m_cl.m_capacity]();
			double* tempY = new double[m_cl.m_capacity]();
			int* tempDepth = new int[m_cl.m_capacity]();
			for (int i = 0; i < m_cl.m_size; ++i)
			{
				tempX[i] = m_cl.m_longitude[i];
				tempY[i] = m_cl.m_latitude[i];
			}

			delete[] m_cl.m_longitude;
			delete[] m_cl.m_latitude;

			m_cl.m_longitude = tempX;
			m_cl.m_latitude = tempY;
		}

		m_cl.m_vecCountSection.push_back(m_cl.m_section);
		m_cl.m_section = 0;
		OnDraw();
		break;
	}
	case enContour:
	{
		if (m_ct.m_size >= m_ct.m_capacity)
		{
			//开辟一个两倍大小的内存，拷贝之前的数据，释放之前的数据
			m_ct.m_capacity *= 2;
			double* tempX = new double[m_ct.m_capacity]();
			double* tempY = new double[m_ct.m_capacity]();
			int* tempDepth = new int[m_ct.m_capacity]();
			for (int i = 0; i < m_ct.m_size; ++i)
			{
				tempX[i] = m_ct.m_longitude[i];
				tempY[i] = m_ct.m_latitude[i];
			}

			delete[] m_ct.m_longitude;
			delete[] m_ct.m_latitude;

			m_ct.m_longitude = tempX;
			m_ct.m_latitude = tempY;
		}

		m_ct.m_vecCountSection.push_back(m_ct.m_section);
		m_ct.m_section = 0;
		OnDraw();
		break;
	}
	case enIsland:
	{
		if (m_island.m_size >= m_island.m_capacity)
		{
			//开辟一个两倍大小的内存，拷贝之前的数据，释放之前的数据
			m_island.m_capacity *= 2;
			double* tempX = new double[m_island.m_capacity]();
			double* tempY = new double[m_island.m_capacity]();
			int* tempDepth = new int[m_island.m_capacity]();
			for (int i = 0; i < m_island.m_size; ++i)
			{
				tempX[i] = m_island.m_longitude[i];
				tempY[i] = m_island.m_latitude[i];
			}

			delete[] m_island.m_longitude;
			delete[] m_island.m_latitude;

			m_island.m_longitude = tempX;
			m_island.m_latitude = tempY;
		}

		m_island.m_vecCountSection.push_back(m_island.m_section);
		m_island.m_section = 0;
		OnDraw();
		break;
	}
	default:
		break;
	}
}