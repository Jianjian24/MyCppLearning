#include <iostream>
using namespace std;

struct AD
{
    virtual ~AD(){}
};

struct Data : public AD
{
    int A;
    double B;
    double Bb;

    Data()
    {
        A = 100;
        B = 100.123;
    }
};

int main()
{
    AD* ad = new Data;
    void* value = new Data;
    // ad->A = 100;
    // ad->B = 100;
    cout << sizeof(AD) << '\n';
    cout << sizeof(Data) << '\n';    
    cout << ((Data*)value)->A << '\n';
    cout << ((Data*)value)->B << '\n';

    cout << (int)9 / 0.7 <<'\n'; 
    cout << int((int)9 / 0.7) <<'\n'; 
    return 0;
}

//https://blog.csdn.net/longjialin93528/article/details/80160467


	CDC memDC;
	memDC.CreateCompatibleDC(&dc);


		Graphics graphics(memDC.GetSafeHdc());
		Pen *pNewPen = new Pen(Color::White);

			rect.X = (i)*(float)g_buttonWidth;
			rect.Y = 0;
			rect.Width = g_buttonWidth;
			rect.Height = g_buttonHeight;
			szTemp = G_ShootingColor2ButtonName((en_ShootingColor)m_vecShootColor[i]);
			graphics.FillRectangle(&highlightBrush, rect);
			WCHAR *pBuf = szTemp.GetBuffer(szTemp.GetLength());
			szTemp.ReleaseBuffer();
			int nTemp = std::min(rect.Width, rect.Height);

				pNewPen->SetWidth(1);
				graphics.DrawRectangle(pNewPen, rect);				//绘制分块边界线
				Font font(L"Times New Roman", nTemp / 3);
				RectF rcStr;
				graphics.MeasureString(pBuf, szTemp.GetLength(), &font, PointF(0, 0), &rcStr);
				graphics.DrawString(pBuf, szTemp.GetLength(), &font, PointF(rect.GetLeft() + (rect.Width - rcStr.Width) / 2, rect.GetTop() + (rect.Height - rcStr.Height) / 2), &strBrush);


BOOL CPhotoView::CalPixelOnClient(CRect cilentRect, CRect imageRect, std::vector<SPixelOnClient>& vPixelInfo)
{
	if (count929++ % 10 == 0)
	{
		CString str;
		str.Format(_T("m_ratio is %f\n"), m_ratio);
		TRACE(str);
		count929 = 1;
	}
	//1.判断放缩比是否达到需求；2.求两个Rect的交集；3.以交集部分计算每一个Pixel的Rect和坐标；4.将数据设置到vector里
	if (m_ratio < 60)
		return FALSE;

	CRect intersetRect;
	if (!IntersectRect(&intersetRect, &cilentRect, &imageRect))
		return FALSE;

	//求当前比例每个像素的宽高
	float pixelWidth = imageRect.Width() / (m_iScreenWidth - 0.5);//左边和右边都少了半个像素
	float pixelHeight = imageRect.Height() / (m_iScreenHeight - 0.5);

	//求左上角的点所在Pixel的Rect和相对坐标位置
	//由于缺少了像素，需要先平移imageRect
	imageRect.top -= pixelHeight / 2;
	imageRect.left -= pixelWidth / 2;
	//imageRect.right -= pixelWidth / 2;
	//imageRect.bottom -= pixelHeight / 2;

	//左上角是第几个
	int ltx, lty;
	ltx = (intersetRect.left - imageRect.left) / pixelWidth + 1;
	lty = (intersetRect.top - imageRect.top) / pixelHeight + 1;	

	//右下角是第几个
	int rbx, rby;
	rbx = (intersetRect.right - imageRect.left) / pixelWidth + 1;
	rby = (intersetRect.bottom - imageRect.top) / pixelHeight + 1;

	vPixelInfo.clear();
	SPixelOnClient pixelNow;
	int indexNowX = ltx, indexNowY = lty;
	for (int i = 0; i <= rbx - ltx; i++)
	{
		for (int j = 0; j <= rby - lty; j++)
		{
			pixelNow.pixelRect.left = imageRect.left + (indexNowX - 1)*pixelWidth;
			pixelNow.pixelRect.right = imageRect.left + indexNowX*pixelWidth;
			pixelNow.pixelRect.top = imageRect.top + (indexNowY - 1)*pixelHeight;
			pixelNow.pixelRect.bottom = imageRect.top + indexNowY*pixelHeight;

			pixelNow.x = indexNowX;
			pixelNow.y = indexNowY;

			vPixelInfo.push_back(pixelNow);
			indexNowY++;
		}
		indexNowX++;
		indexNowY = lty;
	}

	return TRUE;
}
