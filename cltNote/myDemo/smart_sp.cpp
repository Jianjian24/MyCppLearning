#include <iostream>
#include <memory>
#include <cstring>

void fun(std::shared_ptr<int> sp)
{
	std::cout << "fun: sp.use_count() == " << sp.use_count() << '\n';
}
 
void test(int* ptr)
{
	std::shared_ptr<int> p1(ptr);
	int n = p1.use_count();
	std::cout << n << std::endl;
}
 
int main(int argc, char* argv[])
{
	auto sp1 = std::make_shared<int>(5);
 
	int* n3 = sp1.get();
	std::cout << *sp1 << '\n';;
	std::cout << "sp1.use_count() == " << sp1.use_count() << '\n';
	std::shared_ptr<int> p2(sp1);
	std::cout << "sp1.use_count() == " << sp1.use_count() << '\n';
 
	fun(sp1);
	fun(sp1);
 
	std::cout  <<"------------------"<< std::endl;
	std::cout << std::endl;
	int* p1 = new int[3];
	memset(p1, 0, sizeof(int) * 3);
 
	*p1 = 11;
	*(p1 + 1) = 22;
	*(p1 + 2) = 33;
    // std::shared_ptr<int> spMy = std::make_shared<int>({12,2,3,4,4});
    // *(spMy.get()) = 10;
    // *(spMy.get()+1) = 10;
    // *(spMy.get()+2) = 20;
    // *(spMy.get()+3) = 30;

        // 创建一个整形数组
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // 使用make_shared来存储数组 //C++17之后才支持，我这个版本不够
    // std::shared_ptr<int[]> arrPtr = std::make_shared<int[]>(arr, 10);
    // *(arrPtr.get()) = 10;
    // *(arrPtr.get()+1) = 10;
    // *(arrPtr.get()+2) = 20;
    // *(arrPtr.get()+3) = 30;

	// std::cout << *(arrPtr.get()+2) << ' ' << std::endl;

	std::shared_ptr<int> sp2(p1);
	int n = sp2.use_count();
	std::cout << n << std::endl;
 
	std::shared_ptr<int> ptr2(sp2);
	n = ptr2.use_count();
	std::cout << n << std::endl;
 
	std::shared_ptr<int> ptr3 = sp2;
	n = ptr3.use_count();
	std::cout << n << std::endl;
 
	
	//std::cout << sp2 << std::endl;
	std::cout << *(sp2.get()) << std::endl;
	std::cout << *(sp2.get()+1) << std::endl;
	std::cout << *(sp2.get() + 2) << std::endl;
	return 0;
}
 
 