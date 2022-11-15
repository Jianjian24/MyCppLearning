#pragma once
#include "afxdialogex.h"
#include "MyData.h"


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
	enLBtnIsDown,
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
	void SetBtnStatus(EnBtnStatus status) { m_enBtnStatus = status; }
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	void SetDepth(int depth)	{ m_sp.m_inputDepth = depth; }

protected:
	DECLARE_MESSAGE_MAP()

	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	void	Draw(CDC& dc);
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

private:
	EnDrawType m_enDrawType;
	EnBtnStatus m_enBtnStatus;
	SoundingPoint m_sp;
	ChannelLine m_cl;
	Contour m_ct;
	Island m_island;
};