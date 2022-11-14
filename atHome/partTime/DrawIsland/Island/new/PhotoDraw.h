#pragma once
#include "afxdialogex.h"


enum EnDrawType
{
	enSoundingPoint,
	enChannelLine,
	enContour, 
	enIsland
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
	BOOL	OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

private:
	EnDrawType m_enDrawType;

};
