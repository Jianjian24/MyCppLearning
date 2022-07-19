# mfc学习笔记

## Day 1

### 底层实现窗口
1. sdk api 句柄
2. 消息处理机制
3. 头文件 windows.h
4. 程序入口

### 具体6个步骤 
1. 设计窗口 WNDCLASS wc
2. 注册窗口 RegisterClass
3. 创建窗口 createWindow
4. 显示和更新 showWindow updateWindow
5. 通过循环取消息 MSG msg
   1. 写循环 while（1）
   2. GetMessage == false 退出循环
   3. 翻译消息
   4. 分发消息
6. 窗口过程
   1. LRESULT CALLBACK WindowProc // WindowProc是窗口过程函数函数名
   2. 返回默认的处理 return DefWindowProc(hwnd, uMsg, wParam, lParam);
   3. 点击叉子	
   ```C++
    case WM_CLOSE :
        DestroyWindow(hwnd); // 发送另一条消息  WM_DESTROY 这条消息才是真正销毁程序的消息
        break;
    case WM_DESTROY :
        PostQuitMessage(0);
        break;
    ```
    4. 鼠标左键按下
    5. 绘图、文字

``` C++
wsprintf(buf, TEXT("x = %d, y = %d"), xPos, yPos);
// wsprintf 用来拼接字符串，其中buf是拼接好后的字符串存放的位置 
```
Ref:D:\code\mfcCode\testCode\Win32Project2\Win32Project2


### 利用mfc创建窗口
1. mfc头文件afxwin.h
2. 自定义类 继承于 CWinApp 应用程序类 // MyApp app 应用程序对象，有且仅有一个
3. 程序入口 InitInstance
4. 再入口里面创建窗口
5. 窗口类 MyFrame 继承于CFrameWnd
6. MyFrame 构造中 Create（NULL，标题名称）
7. 创建窗口对象
8. 显示和更新
9. m_pMainWnd = frame; // 保存指向应用程序的主窗口的指针
10. return TRUE;
11. 对项目进行设置，再共享DLL中使用mfc

### 消息映射机制
1. 声明宏 写到.h 中
2. 分界宏 写到.cpp 中 
3. 找消息宏 写到分界宏中
4. 把函数原型写到.h 中
5. 函数的实现写到.cpp 中
6. 鼠标、键盘、绘图

``` C++
	// mfc 中的字符串 CString
	CString str;
	str.Format(TEXT("x = %d,,,, y = %d"), point.x, point.y);
	MessageBox(str);
```

### windows 字符集
1. 多字节 字符产 转宽字节
2. 声明宽字节字符串 wchar_t
3. 统计宽字节字符串 wcslen
4. TEXT做了做了自适应编码转换
5. char* 和 CString 之间的转换
``` C++
    // 统计字符串的长度
	int num = 0;
	char * p = "aaaa";
	num = strlen(p);

	// 统计宽字节的字符串长度
	wchar_t * p2 = L"bbb";
	num = wcslen(p2);

	// char * 与 CString 之间的转换
	// char* -> CString
	char * p3 = "ccc";
	CString str = CString(p3);
	
	// CString -> char *
	CStringA tmp;
	tmp = str;
	char* pp = tmp.GetBuffer();
```

### 利用向导来创建mfc
1. view视类 相片 MainFrame类 相框
2. OnCreate Create WM_Craete 联系 （Create 创建一个窗口 发送一个WM_Create 这个消息 OnCreate来响应这个消息）
3. OnDraw OnPaint 如果同时存在 OnPaint会覆盖

**在MFC中，以Afx为前缀的函数都是全局函数，可以在程序的任何地方调用他**

### 基于对话框学习控件
1. 对话框 模态 非模态
2. 按钮 两个 模态 非模态（标题：cation 或者点击直接输入内容）
3. 点击触发事件的几种方法
   1. 右侧属性 闪电图标
   2. 右键按钮 添加事件处理程序
   3. 双击按钮
4. 插入一个窗口 窗口 右键添加类
5. 模态窗口创建 CDlgExec dlg
   1. dlg.DoModal()
6. 非模态创建
   1. CDlgShow dlg 写到.h成员
   2. dlg.Create 写到初始化oninitDialog 保证只创建一次
   3. dlg.showWindow()

**使用TRACE宏在输出对话框打印信息**

### 编辑框使用
1. EditCtrl 属性
   1. mutiline 多行
   2. want return
   3. 滚动条 无限横向 纵向
2. getWindowText set~
3. 默认那个编辑框回车回退出
   1. 重写OnOk这个method 注释掉或者重写它
4. 退出当前的对话框
   1. CDialog::OnOk || OnCancel
5. 添加变量时候选择Value
6. 本身关联的变量就是那个值（控件里面的东西，之前都是以控件的形式创建变量）
7. UpdateData(TRUE) // 将控件的内容同步到变量中
   1. FALSE反之

### clt第二阶段考试一 设计两位数的计算器软件
1. 设计界面
2. 赋予第一个显示编辑框为只读 作为公式和结果的展示
3. 赋予第二个输入编辑框为只可输入，作为输入数字的显示窗口
4. 按钮设计
   1. 数字按钮
      1. 如果原本数字为0，直接替换input里的内容
      2. 如果前面有数字，则获取之前的str然后追加在其后
   2. 运算符
      1. 加减乘除
         1. input有一组数据的话，获取input里的数据，将当前的str和点击的运算法保存到show里面
         2. 前面没有数据的话，报错
      2. 等于
         1. input有一组数据的话，获取input里的数据，将计算结果显示在show窗口里，input置空
            1. 计算方法，将之前输入的两个数字取出，以及对应保存的运算符号
         2. input没有数据的话，报错
      3. Del
         1. 删除input里面的数据
         2. 若只有一位或者为空，置0
      4. 一些bug
         1. 不能对0进行计算
         2. 浮点数计算不支持
   3. Radio
      1. 默认选中十进制
      2. 切换十六进制 只需要显示show窗口里的数字只有num1和最后的结果需要变为16进制
         1. 判断是否需要转换进制
         2. 若为十六进制，数字转换为十六进制打印输出
            1. 首先是将show框里的数据改变
            2. 之后将结果的输出结果改变
               1. 判断是否进制转换被按下
               2. 根据判断结果对输出结果进行改变
5. 反省
   1. 没有掌握好debug方法 注意切换到debug模式
      1. ASSERT(str.IsEmpty()); 不是这样的话，就会触发中断
      2. TRACE( L"This is a test of the TRACE macro that uses a UNICODE string: %s %d\n", L"The number is:", 2); // 利用TRACE跟踪输出结果
   2. C++基础知识不够扎实，很多地方可以更为合适的数据结构
   3. 看到要使用某个函数，但是网上解释不清楚，还是**先理解函数原本的官方文档**
   4. 尽量完善自己的功能，不要追求速度而忘记质量

m_edit.GetWindowText(str);  //获得编辑框中字符串
if (str.IsEmpty())  //判断是否为空
{
}



### 下拉框 CCombox
1. 属性中加入数据 data 用；分割
2. 默认排序 sort 修改为 false就不排序了
3. type 类型为DropList 就不可以编辑
4. 添加 AddString
5. 删除 DeleteString
6. 插入 InsertString
7. 设置默认选项 setCurset(index)
8. 获取当前索引 index = getCurSet()
9. 根据当前索引 获取内容  getLBText（index, str）
10. 控件事件 void CMy04_comboBoxCtrlDlg::OnCbnSelchangeCombo1()

### ListControl 列表控件
1. view 报表模式
2. 添加表头 InsertCol
3. 添加正文 从 0 索引
4. 添加第一行第一列 insertItem（0， “张三”）
5. 添加第一行的其他列 setItemText（行， 列， 具体风格）
6. 设置风格 整行选中 网格显示
   1. 	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_BORDERSELECT | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT); // 注意那个 | 代表或运算 然后这些格式东西，现在下载的文档里找，之后再去在线文档找

### MFC案例笔记
1. 创建项目
2. 配置项目
   1. 预处理器 的宏添加
   2. 图标的配置 引用资源 SetClassLong（窗口句柄，设置内容，具体图标的加载）
   3. 设置标题 分左右标题 Doc->OnNewDocument 右侧 Frame 中 OnCreate中设置
   4. 设置窗口大小 MoveWindow(0, 0, 800, 500);
   5. 居中显示 CenterWindow();
3. 登陆窗口
   1. 设计登陆窗口
      1. 可以选择很多部件然后对齐
      2. editText 设置为value
         1. 之后注意要updateData
   2. 添加类
   3. 功能实现 点击登陆进行验证
      1. 输入内容不能为空
      2. 判断是否有效
      3. 都成功后进入管理系统
      4. 几个按键点击，重写点击的函数
      5. 消息映射好好学习
         1. 在类的消息里查看
         2. 在类的重写里也重新构造
         3. ....
4. 静态拆分窗口


平时在控件编辑窗口按回车会被返回是因为CDialogEx::OnOK();的执行 


刚推应走后