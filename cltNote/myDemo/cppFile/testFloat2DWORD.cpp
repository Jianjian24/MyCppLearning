#include "../../../jian.h"
typedef unsigned long DWORD;

int main()
{
    // float f = 10003.14159f;
    // DWORD d;
    // //将f转为DWORD类型
    // memcpy(&d, &f, sizeof(float));

    // float f2;
    // memcpy(&f2, &d, sizeof(DWORD));

    // printf("f=%f, f2=%f\n", f, f2);

       float f = 3.14159;
   DWORD d = *(DWORD*)&f;
   float f2 = *(float*)&d;

   std::cout << "float: " << f << std::endl;
   std::cout << "DWORD: " << d << std::endl;
   std::cout << "float: " << f2 << std::endl;
    return 0;
}