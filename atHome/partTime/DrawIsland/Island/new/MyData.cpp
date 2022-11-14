#include "pch.h"
#include "MyData.h"

chartGraphy::chartGraphy()
:m_sep(0)					//序号 
,m_graphyType(enPoint)		//图元类型
,m_linetype(enSolid)		//线形 
,m_color(0)					//颜色
,m_thickness(0)				//粗细程度
,m_longitude(NULL)			//经度坐标
,m_latitude(NULL)			//纬度坐标
,m_size(0)
{

}

chartGraphy::~chartGraphy()
{
}

SoundingPoint::SoundingPoint()
{
	m_name = L"SoundingPoint";
}

SoundingPoint::~SoundingPoint()
{
}

Contour::Contour()
{
	m_name = L"Contour";
}

Contour::~Contour()
{
}

Island::Island()
{
	m_name = L"Island";
}

Island::~Island()
{
}

ChannelLine::ChannelLine()
{
	m_name = L"ChannelLine";
}

ChannelLine::~ChannelLine()
{
}
