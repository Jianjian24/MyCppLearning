#include "pch.h"
#include "MyData.h"

chartGraphy::chartGraphy()
: m_sep(0)					//序号 
, m_graphyType(enPoint)		//图元类型
, m_linetype(enSolid)		//线形 
, m_color(0)				//颜色
, m_thickness(0)			//粗细程度
//, m_longitude(NULL)			//经度坐标
//, m_latitude(NULL)			//纬度坐标
, m_size(0)
, m_capacity(1000)
{
	m_longitude = new double[m_capacity]();
	m_latitude = new double[m_capacity]();
}

chartGraphy::~chartGraphy()
{
	TRACE(L"chartGraphy::~chartGraphy\n");
	if (m_longitude)
		delete[] m_longitude;
	if (m_latitude)
		delete[] m_latitude;
}

SoundingPoint::SoundingPoint()
{
	m_name = L"SoundingPoint";
	m_depth = new int[m_capacity]();
}

SoundingPoint::~SoundingPoint()
{
	if (m_depth)
	{
		delete[] m_depth;
	}
}

Contour::Contour()
{
	m_name = L"Contour";
	m_section = 0;
}

Contour::~Contour()
{
}

Island::Island()
{
	m_name = L"Island";
	m_section = 0;
}

Island::~Island()
{
}

ChannelLine::ChannelLine()
{
	m_name = L"ChannelLine";
	m_section = 0;
}

ChannelLine::~ChannelLine()
{
}
