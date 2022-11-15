#pragma once
#include <afxwin.h>

class CPhotoView : public CWnd
{
	CPhotoView();
	~CPhotoView();
public:	
	virtual BOOL Create(LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect,
		CWnd* pParentWnd, UINT nID,
		CCreateContext* pContext = NULL);
protected:
	void Draw(CDC& dc);
};

