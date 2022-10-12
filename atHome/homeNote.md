# 关于C++的移动语意
参考:https://www.bilibili.com/video/BV1V14y187Yd/?spm_id_from=333.880.my_history.page.click&vd_source=6c49303593f2a93ee4d2f71042c3c6eb
![图 1](../Bin/image/2022-10-07-%E5%B7%A6%E5%80%BC%E5%92%8C%E5%8F%B3%E5%80%BC.png)  




# 支线
## noexcept
noexcept 编译期完成声明和检查工作.noexcept 主要是解决的问题是减少运行时开销. 运行时开销指的是, 编译器需要为代码生成一些额外的代码用来包裹原始代码，当出现异常时可以抛出一些相关的堆栈stack unwinding错误信息, 这里面包含，错误位置, 错误原因, 调用顺序和层级路径等信息.当使用noexcept声明一个函数不会抛出异常候, 编译器就不会去生成这些额外的代码, 直接的减小的生成文件的大小, 间接的优化了程序运行效率.
ref: C++\cltNote\myDemo\throw.cpp