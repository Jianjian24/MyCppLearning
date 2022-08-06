# 第三周 0725

*搬进了文苑，开启新的life style*

## 01
主要是熟悉校正的流程，熟悉工作流

## 02
1. 关于TRACE
   1. 在宏定义中代表的是字符串
``` C++  
    #define TRACE(sz)							\
	fwprintf(stdout, (const wchar_t *)sz);	\
	ATLTRACE(sz)
```
   2. 但是在用法上又类似于printf，可以使用可变参数去获取我想要输出的对象
   3. 在实际项目中碰到了TRACE输出结果不一样的情况，还不知道是什么原因，启示：多使用断电和编译器的调试方式
2. va和vs的快捷键熟悉，可以大大提高工作效率  

## 03
1. Unicode编码作为万国码或者唯一码被广泛使用，在MFC中一般利用CString.Format(_T"some text here")来将输入的字符转化为统一的宽字符Unicode编码

## 04
1. 明确消息之间传递的机理，去到各个定义的文件去找这个变量被拿去干什么了。。
2. 先做好整体的设计方案后，再开始动手

## 05
1. 想要知道某个变量的初始值，可以先去构造函数里看下其初值
2. 关于HDC，CDC，CWindowDC，CClientDC，CPaintDC
   1. 首先说一下什么是DC（设备描述表）解：Windows应用程序通过为指定设备（屏幕，打印机等）创建一个设备描述表**Device Context, DC**在DC表示的逻辑意义的“画布”上进行图形的绘制。DC是一种包含设备信息的数据结构，它包含了物理设备所需的各种状态信息。Win32程序在绘制图形之前需要获取DC的句柄HDC，并在不继续使用时释放掉。
   2. 在c++ 编程中常会见到HDC,CDC,CClientDC,CPaintDC,CWindowDC这样的类
      1. HDC是DC的句柄,API中的一个类似指针的数据类型.
      2. CDC是MFC的DC的一个类
      3. CDC等设备上下分类,都含有一个类的成员变量:m_nHdc;即HDC类型的句柄.
      4. CDC类定义了一个设备描述表相关的类，其对象提供成员函数操作设备描述表进行工作，如显示器，打印机，以及显示器描述表相关的窗口客户区域。通过CDC的成员函数可进行一切绘图操作。CDC提供成员函数进行设备描述表的基本操作，使用绘图工具， 选择类型安全的图形设备结构（GDI），以及色彩，调色板。除此之外还提供成员函数获取和设置绘图属性，映射，控制视口，窗体范围，转换坐标，区域操作，裁减，划线以及绘制简单图形（椭圆，多边形等）。成员函数也提供绘制文本，设置字体，打印机换码，滚动， 处理元文件。
         1. 其派生类:CPaintDC: 封装BeginPaint和EndPaint两个API的调用。
            1. 用于响应窗口重绘消息（WM_PAINT）是的绘图输出。
            2. CPaintDC在构造函数中调用BeginPaint()取得设备上下文，在析构函数中调用EndPaint()释放设备上下文。EndPaint()除了释放设备上下文外，还负责从消息队列中清除WM_PAINT消息。因此，在处理窗口重画时，必须使用CPaintDC，否则WM_PAINT消息无法从消息队列中清除，将引起不断的窗口重画。
            3. CPaintDC也只能用在WM_PAINT消息处理之中。
         2. CClientDC（客户区设备上下文）: 处理显示器描述表的相关的窗体客户区域。用于客户区的输出，与特定窗口关联，可以让开发者访问目标窗口中客户区，其构造函数中包含了GetDC,析构函数中包含了ReleaseDC。
         3. CWindowDC: 处理显示器描述表相关的整个窗体区域，包括了框架和控 件（子窗体）。
            1. 可在非客户区绘制图形，而CClientDC，CPaintDC只能在客户区绘制图形。
            2. 坐标原点是在屏幕，的左上角CClientDC，CPaintDC下坐标原点是在客户区的左上角。
            3. 关联一特定窗口，允许开发者在目标窗口的任何一部分进行绘图，包含边界与标题，这种DC同WM_NCPAINT消息一起发送。
         4. CMetaFileDC: 与元文件相关的设备描述表关联。

## 06
1. 一个父窗口里面是由很多个子窗口构成，单独写一个新的子窗口去添加到父窗口中去满足绘制多个不同图形的需求，例如在进度条对话框中绘制进度条。


## q
1. 关于mfc中坐标转换
``` C++
   CString str;
	CRect rc;
	GetClientRect(rc);
	str.Format(_T("left=%d,right=%d,top=%d,bottom=%d\n"), rc.left, rc.right, rc.top, rc.bottom);
	TRACE(str);

	ClientToScreen(rc);
	str.Format(_T("TRAN: left=%d,right=%d,top=%d,bottom=%d\n"), rc.left, rc.right, rc.top, rc.bottom);
	TRACE(str);
   SolidBrush solidBrush(Color(100, 0, 0, 255));
	CPaintDC dc(this); // device context for painting
	//HDC hdc;
	//hdc = ::GetDC(m_hWnd);
	//Graphics graphics(hdc);
	Graphics graphics(dc.GetSafeHdc());
	graphics.FillRectangle(&solidBrush, ZOOM(24), ZOOM(92), ZOOM(512), ZOOM(8));

```
2. 关于OnPaint不断被调用*https://blog.csdn.net/u013919153/article/details/99447045*
3. 父类能够直接调用子类的函数