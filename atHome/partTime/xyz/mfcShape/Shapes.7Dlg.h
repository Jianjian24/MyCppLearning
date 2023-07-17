
// Shapes.7Dlg.h : header file
//

#pragma once
#include "afxwin.h"


enum EnShape
{
	enSquare = 0,
	enRectangle,
	enCircle,
	enTriangle,
	enCube,
	enBox,
	enCylinder,
	enPrism
};

// CShapes7Dlg dialog
class CShapes7Dlg : public CDialogEx
{
// Construction
public:
	CShapes7Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHAPES7_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	string GetValueFromControl(UINT controlID);
	void  GetResultFromShape(EnShape curShape, std::vector<string>& vecStr);
public:
	afx_msg void OnCbnSelchangeComboShape();
private:
	CComboBox m_cbxShape;
public:
	afx_msg void OnBnClickedButtonCalc();
	afx_msg void OnBnClickedButtonClear();
};
