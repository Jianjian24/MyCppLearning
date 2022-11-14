#include "pch.h"
#include "CPhotoView.h"

CPhotoView::CPhotoView()
{
}

CPhotoView::~CPhotoView()
{
}


BOOL CPhotoView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	return 0;
}
void CPhotoView::Draw(CDC& dc)
{
	CRect rcClient;
	GetClientRect(&rcClient);

	CBitmap bitmap;
	bitmap.CreateCompatibleBitmap(&dc, rcClient.Width(), rcClient.Height());
	CDC memDC;
	memDC.CreateCompatibleDC(&dc);
	CBitmap* pOldbmp = memDC.SelectObject(&bitmap);
	memDC.FillSolidRect(rcClient, RGB(0, 0, 0));


	//rcPos.right = rcPos.left + width;
	//rcPos.bottom = rcPos.top + height;
	//Graphics graphics(memDC.GetSafeHdc());
	//graphics.SetInterpolationMode(InterpolationModeNearestNeighbor);
	//graphics.SetSmoothingMode(SmoothingModeHighSpeed);
	//graphics.SetCompositingQuality(CompositingQualityHighSpeed);
	//graphics.DrawImage(m_pCurLoadingImage, rcPos.left, rcPos.top, rcPos.Width(), rcPos.Height());

	dc.BitBlt(0, 0, rcClient.Width(), rcClient.Height(), &memDC, 0, 0, SRCCOPY);

	memDC.SelectObject(pOldbmp);
	DeleteObject(&bitmap);		//删除位图
	memDC.DeleteDC();		//删除DC	
	DeleteObject(pOldbmp);	//删除备份位图
}
