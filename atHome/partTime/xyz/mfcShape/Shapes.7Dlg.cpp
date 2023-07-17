
// Shapes.7Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Shapes.7.h"
#include "Shapes.7Dlg.h"
#include "afxdialogex.h"
#include "pShapes.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAboutDlg dialog used for App About
class OutputBuffer : public std::streambuf {
public:
	OutputBuffer() {
		setp(0, 0);
	}

	int_type overflow(int_type c) override {
		if (c != EOF) {
			m_buffer += static_cast<char>(c);
		}
		return c;
	}

	std::string GetOutput() const {
		return m_buffer;
	}

private:
	std::string m_buffer;
};

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CShapes7Dlg dialog



CShapes7Dlg::CShapes7Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SHAPES7_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShapes7Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_SHAPE, m_cbxShape);
}

BEGIN_MESSAGE_MAP(CShapes7Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO_SHAPE, &CShapes7Dlg::OnCbnSelchangeComboShape)
	ON_BN_CLICKED(IDC_BUTTON_CALC, &CShapes7Dlg::OnBnClickedButtonCalc)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CShapes7Dlg::OnBnClickedButtonClear)
END_MESSAGE_MAP()


// CShapes7Dlg message handlers

BOOL CShapes7Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	//
	m_cbxShape.AddString(L"Square");
	m_cbxShape.AddString(L"Rectangle");
	m_cbxShape.AddString(L"Circle");
	m_cbxShape.AddString(L"Triangle");
	m_cbxShape.AddString(L"Cube");
	m_cbxShape.AddString(L"Box");
	m_cbxShape.AddString(L"Cylinder");
	m_cbxShape.AddString(L"Prism");

	m_cbxShape.SetCurSel(enSquare);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CShapes7Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CShapes7Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CShapes7Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



std::string CShapes7Dlg::GetValueFromControl(UINT controlID)
{
	CString cstr;
	GetDlgItem(controlID)->GetWindowTextW(cstr);
	CStringA cstrA(cstr.GetString());
	std::string str(cstrA);

	return str;
}

void CShapes7Dlg::OnCbnSelchangeComboShape()
{
	UpdateData(TRUE);

	EnShape index = EnShape(m_cbxShape.GetCurSel());

	switch (index)
	{
	case enSquare:
		GetDlgItem(IDC_STATIC_P1)->SetWindowText(L"sideLength");
		GetDlgItem(IDC_STATIC_P2)->SetWindowText(L"N/A");
		GetDlgItem(IDC_STATIC_P3)->SetWindowText(L"N/A");
		break;
	case enRectangle:
		GetDlgItem(IDC_STATIC_P1)->SetWindowText(L"length");
		GetDlgItem(IDC_STATIC_P2)->SetWindowText(L"width");
		GetDlgItem(IDC_STATIC_P3)->SetWindowText(L"N/A");
		break;
	case enCircle:
		GetDlgItem(IDC_STATIC_P1)->SetWindowText(L"radius");
		GetDlgItem(IDC_STATIC_P2)->SetWindowText(L"N/A");
		GetDlgItem(IDC_STATIC_P3)->SetWindowText(L"N/A");
		break;
	case enTriangle:
		GetDlgItem(IDC_STATIC_P1)->SetWindowText(L"sideLength");
		GetDlgItem(IDC_STATIC_P2)->SetWindowText(L"N/A");
		GetDlgItem(IDC_STATIC_P3)->SetWindowText(L"N/A");
		break;
	case enCube:
		GetDlgItem(IDC_STATIC_P1)->SetWindowText(L"sideLength");
		GetDlgItem(IDC_STATIC_P2)->SetWindowText(L"N/A");
		GetDlgItem(IDC_STATIC_P3)->SetWindowText(L"N/A");
		break;
	case enBox:
		GetDlgItem(IDC_STATIC_P1)->SetWindowText(L"length");
		GetDlgItem(IDC_STATIC_P2)->SetWindowText(L"width");
		GetDlgItem(IDC_STATIC_P3)->SetWindowText(L"height");
		break;
	case enCylinder:
		GetDlgItem(IDC_STATIC_P1)->SetWindowText(L"radius");
		GetDlgItem(IDC_STATIC_P2)->SetWindowText(L"height");
		GetDlgItem(IDC_STATIC_P3)->SetWindowText(L"N/A");
		break;
	case enPrism:
		GetDlgItem(IDC_STATIC_P1)->SetWindowText(L"sideLength");
		GetDlgItem(IDC_STATIC_P2)->SetWindowText(L"height");
		GetDlgItem(IDC_STATIC_P3)->SetWindowText(L"N/A");
		break;
	default:
		break;
	}
}

void CShapes7Dlg::GetResultFromShape(EnShape curShape, std::vector<string>& vecStr)
{
	vecStr.clear();

	switch (curShape)
	{
	case enSquare:
		vecStr.push_back("Square");
		vecStr.push_back(GetValueFromControl(IDC_STATIC_P1));
		break;
	case enRectangle:
		vecStr.push_back("Rectangle");
		vecStr.push_back(GetValueFromControl(IDC_STATIC_P1));
		vecStr.push_back(GetValueFromControl(IDC_STATIC_P2));
		break;
	case enCircle:
		vecStr.push_back("Circle");
		vecStr.push_back(GetValueFromControl(IDC_STATIC_P1));
		break;
	case enTriangle:
		vecStr.push_back("Triangle");
		vecStr.push_back(GetValueFromControl(IDC_STATIC_P1));
		break;
	case enCube:
		vecStr.push_back("Cube");
		vecStr.push_back(GetValueFromControl(IDC_STATIC_P1));
		break;
	case enBox:
		vecStr.push_back("Box");
		vecStr.push_back(GetValueFromControl(IDC_STATIC_P1));
		vecStr.push_back(GetValueFromControl(IDC_STATIC_P2));
		vecStr.push_back(GetValueFromControl(IDC_STATIC_P3));
		break;
	case enCylinder:
		vecStr.push_back("Cylinder");
		vecStr.push_back(GetValueFromControl(IDC_STATIC_P1));
		vecStr.push_back(GetValueFromControl(IDC_STATIC_P2));
		break;
	case enPrism:
		vecStr.push_back("Prism");
		vecStr.push_back(GetValueFromControl(IDC_STATIC_P1));
		vecStr.push_back(GetValueFromControl(IDC_STATIC_P2));
		break;
	default:
		break;
	}
}

void CShapes7Dlg::OnBnClickedButtonCalc()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	EnShape index = EnShape(m_cbxShape.GetCurSel());
	std::vector<string> vecResult;
	GetResultFromShape(index, vecResult);

	comsc::Shape* curShape = NULL;

	switch (index)
	{
	case enSquare:
		curShape = new comsc::Square(vecResult);
		break;
	case enRectangle:
		curShape = new comsc::Rectangle(vecResult);
		break;
	case enCircle:
		curShape = new comsc::Circle(vecResult);
		break;
	case enTriangle:
		curShape = new comsc::Triangle(vecResult);
		break;
	case enCube:
		curShape = new comsc::Cube(vecResult);
		break;
	case enBox:
		curShape = new comsc::Box(vecResult);
		break;
	case enCylinder:
		curShape = new comsc::Cylinder(vecResult);
		break;
	case enPrism:
		curShape = new comsc::Prism(vecResult);
		break;
	default:
		break;
	}

	OutputBuffer buffer; // �����Զ����OutputBuffer
	std::streambuf* oldBuffer = std::cout.rdbuf(&buffer); // �ض���std::cout��OutputBuffer

	curShape->output(std::cout); // ������ض���std::cout��������OutputBuffer��

	std::cout.rdbuf(oldBuffer); // �ָ�std::cout��ԭʼstreambuf

	CString output(buffer.GetOutput().c_str()); // ��OutputBuffer������ת��ΪCString

	GetDlgItem(IDC_EDIT_RESULT)->SetWindowTextW(output);

}


void CShapes7Dlg::OnBnClickedButtonClear()
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_EDIT_RESULT)->SetWindowTextW(L"");
}
