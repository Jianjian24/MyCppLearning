
// DrawChartDlg.h : header file
//

#pragma once
#include "PhotoDraw.h"


// CDrawChartDlg dialog
class CDrawChartDlg : public CDialogEx
{
// Construction
public:
	CDrawChartDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DRAWCHART_DIALOG };
#endif
protected:
	//CPhotoView m_photoView;
	CPhotoDraw m_photoDraw;

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	//afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	BOOL	OnEraseBkgnd(CDC* pDC);
	DECLARE_MESSAGE_MAP()
protected:
	afx_msg void OnBnClickedBtnSoundingpoint();
	afx_msg void OnBnClickedBtnChannelline();
	afx_msg void OnBnClickedBtnContour();
	afx_msg void OnBnClickedBtnIsland();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};
