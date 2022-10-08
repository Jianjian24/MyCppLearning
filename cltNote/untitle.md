1. 关于浮点数的对比，切记使用减法进行比较
2. 三思而后行，先做好程序的思路再去写代码！！
3. 最开始的我的message是在直接send给LogDlg的方法中，但并没有指明是哪个对象，导致最后编译器报错，应该传给在manager里面创建好的对象，之后调用相应的sendmessage加载函数，还sendmessage需要在LogDlg里面重载
4. 消息机制是MFC编程的重要机制之一，谁发送消息，谁接收，相应的消息处理函数和消息宏定义
5. extern 关键字用于在给一个变量或者函数声明，告诉编译器先别急着报错，这个变量或者函数是在其他地方被定义的，详见下图：
![图 1](../Bin/image/2022-09-19-externDemo.png)  
6. ``sizeof()``求出里面表达式的大小，以字节为单位，但是要注意传进去的是指针还是一整个空间
```C++
    CString strPWD = it->m_strPassword;
    CStringA strA(strPWD);
    //char* pBuf = nullptr;
    //int len = G_CString_TO_Char(strPWD, pBuf);
    char* pBuf = strA.GetBuffer();
    int len = strA.GetLength();
    bacCrypt.Encrypt((BYTE*)pBuf, strlen(pBuf));					//加密
    CString strEncrypt(pBuf);
    strA.ReleaseBuffer();
```
![图 4](../Bin/image/2022-09-21-sizeof.png)  
7. MFC的初始化：https://blog.csdn.net/Lirx_Tech/article/details/48178811
8. 初始化顺序，根据需要在对象实例化的时候利用外面的set对对象进行操作
9. //https://blog.csdn.net/crazygougou/article/details/9389867 vector iterators incompatible
10. 在线性搜索的应用场景下可以考虑使用二分法，寻找左右边界
11. WaitForSingleObject的效果就相当于一个关卡，只有返回给了WaitForSingleObject结果程序才能继续执行，当然线程不一定能正常执行结束，也可能会出现，提前结束的情况，原因是给的等待时间结束了，但这个线程还是没有执行完，可以将WaitForSingleObject的第二个参数设置为 INFINITE，就可以一直等待。