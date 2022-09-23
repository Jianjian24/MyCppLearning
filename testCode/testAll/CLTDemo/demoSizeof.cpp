#include <stdio.h>
#include <windows.h>

int main()
{
    int a=10;
    int arr[] = {1,2,3};
    char str[]="hello1111111111111111";
    char* str1 = str; 
    int len_a = sizeof(a);
    int len_arr = sizeof(arr);
    int len_str = sizeof(str);//22
    int len_str1 = strlen(str1);//21 sizeof(str1) == 8 
    
    printf("len_a=%d,len_arr=%d,len_str=%d,len_str1=%d\n",len_a,len_arr,len_str,len_str1);
    
    return 0;
}