#pragma once
#include <afxstr.h>

//图元类型
enum enGraphyType
{
	enPoint,		 //点
	enLine,			 //线
	enPolygon		 //多边形
};

//线形
enum enLineType
{
	enSolid,		  //实线
	enDash,			  //虚线
	enDot,			  //点
};

class chartGraphy
{
public:
	chartGraphy();
	~chartGraphy();

protected:
	CString name;				//名称 
	int sep;					//序号 
	enGraphyType graphyType;	//图元类型
	enLineType linetype;		//线形 

	int color;					//颜色
	int thickness;				//粗细程度

	double* longitude;			//经度坐标
	double* latitude;			//纬度坐标
};

class MyData
{
private:
	/* data */
public:
	MyData(/* args */);
	~MyData();
};

MyData::MyData(/* args */)
{
}

MyData::~MyData()
{
}


//增加photoView绘制类，将绘制操作放在里面
//绘制的区域则是在外部计算
//===============================
void CPhotoView::Draw(CDC& dc)
{
	CRect rcClient;
	GetClientRect(&rcClient);

	CBitmap bitmap;
	bitmap.CreateCompatibleBitmap(&dc, rcClient.Width(), rcClient.Height());
	CDC memDC;
	memDC.CreateCompatibleDC(&dc);
	CBitmap *pOldbmp = memDC.SelectObject(&bitmap);
	memDC.FillSolidRect(rcClient, RGB(0,0,0));
	

			rcPos.right = rcPos.left + width;
			rcPos.bottom = rcPos.top + height;
			Graphics graphics(memDC.GetSafeHdc());
			graphics.SetInterpolationMode(InterpolationModeNearestNeighbor);
			graphics.SetSmoothingMode(SmoothingModeHighSpeed);
			graphics.SetCompositingQuality(CompositingQualityHighSpeed);
			graphics.DrawImage(m_pCurLoadingImage, rcPos.left, rcPos.top, rcPos.Width(), rcPos.Height());		

	dc.BitBlt(0, 0, rcClient.Width(), rcClient.Height(), &memDC, 0, 0, SRCCOPY);

	memDC.SelectObject(pOldbmp);
	DeleteObject(&bitmap);		//删除位图
	memDC.DeleteDC();		//删除DC	
	DeleteObject(pOldbmp);	//删除备份位图
}

BOOL CWSC_BrightAnalysis::OnInitDialog()
{
	CDialog::OnInitDialog();

	g_translate.TranslateDialog(this, IDD, _T("Calibration_"));

	CWnd *pPosWnd = GetDlgItem(IDC_S_POS);
	if(pPosWnd ==  NULL || !::IsWindow(pPosWnd->GetSafeHwnd()))
		return FALSE;
	CRect posPictureRect;
	pPosWnd->GetWindowRect(&posPictureRect);
	ScreenToClient(&posPictureRect);
	if(::IsWindow(m_photoView.GetSafeHwnd()))
	{
		m_photoView.MoveWindow(posPictureRect);
		m_photoView.SetDrawLine(m_bShowLine);
		m_photoView.SetEnableManualRepair(TRUE);
		m_photoView.SetIsShowRBMenu(TRUE);
	}
}

int CWSC_BrightAnalysis::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	if(!m_photoView.Create(NULL,NULL,WS_CHILD|WS_VISIBLE,CRect(0,0,0,0),this,NULL))
		return -1;

	m_photoView.SetModuleWidth(m_pScreenCalibration->GetScreenSettingData()->GetModuleWidth());
	m_photoView.SetModuleHeight(m_pScreenCalibration->GetScreenSettingData()->GetModuleHeight());
	m_photoView.SetPrjData(m_pScreenCalibration);
	return 0;
}