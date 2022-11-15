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

//protected:
	CString m_name;				//名称 
	int m_sep;					//序号 
	enGraphyType m_graphyType;	//图元类型
	enLineType m_linetype;		//线形 

	int m_color;					//颜色
	int m_thickness;				//粗细程度

	//这里的经纬度代表绘制中的（x,y）
	double* m_longitude;			//经度坐标
	double* m_latitude;				//纬度坐标

	
	int m_size;						//记录随机数据的size
	int m_capacity;					//记录当前的最大数据容量，默认开1000，超过这个容量，则开辟一个比当前容量大两倍的空间，以此类推...
};

class SoundingPoint : public chartGraphy
{
//private:
public:
	int* m_depth;					//深度
	int  m_inputDepth;				//编辑框输入的深度
	SoundingPoint(/* args */);
	~SoundingPoint();
};

class ChannelLine : public chartGraphy
{
private:
public:
	int m_section;					//标识总共有几段航道
	std::vector<int> m_vecCountSection;
	ChannelLine(/* args */);
	~ChannelLine();
};

class Contour : public chartGraphy
{
private:
	/* data */
public:
	int m_section;					//标识总共有几段
	std::vector<int> m_vecCountSection;
	Contour(/* args */);
	~Contour();
};

class Island : public chartGraphy
{
private:
	/* data */
public:
	int m_section;					//标识总共有几段
	std::vector<int> m_vecCountSection;
	Island(/* args */);
	~Island();
};