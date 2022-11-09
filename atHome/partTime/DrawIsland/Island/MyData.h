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