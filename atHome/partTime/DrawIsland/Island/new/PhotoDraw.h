#pragma once
#include "afxdialogex.h"


enum EnDrawType
{
	enNone,
	enSoundingPoint,
	enChannelLine,
	enContour, 
	enIsland
};

enum EnBtnStatus
{
	enNormal,
	enLBtnisDown,
	enLBtnisUp, 
};

// CPhotoDraw dialog

class CPhotoDraw : public CWnd
{
	DECLARE_DYNAMIC(CPhotoDraw)

public:
	CPhotoDraw(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CPhotoDraw();
	void OnDraw();
	void SetDrawType(EnDrawType type);
	void SetBtnStatus(EnBtnStatus status)	{m_enBtnStatus = status;}
//// Dialog Data
//#ifdef AFX_DESIGN_TIME
//	enum { IDD = IDD_PHOTODRAW };
//#endif

protected:
	DECLARE_MESSAGE_MAP()
	//afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	void	Draw(CDC& dc);
	void	DrawSoundingPoint(CDC& dc);
	void	DrawChannelLine(CDC& dc);
	void	DrawContour(CDC& dc);
	void	DrawIsland(CDC& dc);
	BOOL	OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);

private:
	EnDrawType m_enDrawType;
	EnBtnStatus m_enBtnStatus;
};

//在外部的Dlg和绘图区域都响应鼠标左键按下和提起的消息作为绘图事件的开始和结束
//绘图之前看下数据有无再去绘制
//
//
//
//
//
//