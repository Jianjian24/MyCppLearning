# sample

## 单元测试简单宏封装（可用于同样的类模型替换）
``` C++
// 简单测试的宏定义
#define TEST(testcase_name) \
  MYTINYSTL_TEST_(testcase_name)

// 使用宏定义掩盖复杂的测试样例封装过程，把 TEXT 中的测试案例放到单元测试中
#define MYTINYSTL_TEST_(testcase_name)                        \
class TESTCASE_NAME(testcase_name) : public TestCase {        \
public:                                                       \
    TESTCASE_NAME(testcase_name)(const char* case_name)       \
        : TestCase(case_name) {};                             \
    virtual void Run();                                       \
private:                                                      \
    static TestCase* const testcase_;                         \
};                                                            \
                                                              \
TestCase* const TESTCASE_NAME(testcase_name)                  \
    ::testcase_ = UnitTest::GetInstance()->RegisterTestCase(  \
        new TESTCASE_NAME(testcase_name)(#testcase_name));    \
void TESTCASE_NAME(testcase_name)::Run()

// 下面是一个简单的用法例子
// algobase test:
TEST(copy_test)
{
  int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
  int exp[5], act[5];
  std::copy(arr1, arr1 + 5, exp);
  mystl::copy(arr1, arr1 + 5, act);
  EXPECT_CON_EQ(exp, act);
  std::copy(arr1 + 5, arr1 + 10, exp);
  mystl::copy(arr1 + 5, arr1 + 10, act);
  EXPECT_CON_EQ(exp, act);
}
```

# tips
## 关于do while(0)
1. 控制只执行一次
```C
#define DOSOMETHING() 
do{ 
          foo1();
          foo2();
  }while(0)
```
2. 避免使用goto控制程序流
```C
int foo()
{
    somestruct *ptr = malloc(...);
    do
    {
        dosomething...;
        if(error)
            break;
        dosomething...;
        if(error)
            break;
        dosomething...;
    }
    while(0);
 
    free(ptr);
    return0;
}
```
* 使用break来代替goto，后续的清理工作在while之后，现在既能达到同样的效果，而且代码的可读性、可维护性都要比上面的goto代码好的多了


