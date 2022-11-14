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
	CString m_name;				//名称 
	int m_sep;					//序号 
	enGraphyType m_graphyType;	//图元类型
	enLineType m_linetype;		//线形 

	int m_color;					//颜色
	int m_thickness;				//粗细程度

	//这里的经纬度代表绘制中的（x,y）
	double* m_longitude;			//经度坐标
	double* m_latitude;				//纬度坐标

	//记录随机数据的size
	int m_size;
};

class SoundingPoint : public chartGraphy
{
private:
	/* data */
public:
	SoundingPoint(/* args */);
	~SoundingPoint();
};

class ChannelLine : public chartGraphy
{
private:
	/* data */
public:
	ChannelLine(/* args */);
	~ChannelLine();
};

class Contour : public chartGraphy
{
private:
	/* data */
public:
	Contour(/* args */);
	~Contour();
};

class Island : public chartGraphy
{
private:
	/* data */
public:
	Island(/* args */);
	~Island();
};