#include <iostream>
#include <memory>
#include <string.h>
 
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

class share_ptr_Test
{
private:
    std::shared_ptr<int> sp1 = std::make_shared<int>(5);
public:
    share_ptr_Test(/* args */) = default;
    ~share_ptr_Test() = default;

    std::shared_ptr<int> get_sp1() { return sp1; }
};

 
int main()
{
    share_ptr_Test* t1 = new share_ptr_Test();
	// auto sp1 = std::make_shared<int>(5);
    auto sp1 = t1->get_sp1();
 
	int* n3 = sp1.get();
	std::cout << *sp1 << '\n';;
	std::cout << "sp1.use_count() == " << sp1.use_count() << '\n';
	std::shared_ptr<int> p2(sp1);
	std::cout << "sp1.use_count() == " << sp1.use_count() << '\n';
	std::shared_ptr<int> p3(sp1);
	std::cout << "sp1.use_count() == " << sp1.use_count() << '\n';
    delete(t1);
    sp1 = std::make_shared<int>(6);
	std::cout << *sp1 << '\n';;
	std::cout << "sp1.use_count() == " << sp1.use_count() << '\n';
	std::cout << "sp1.use_count() == " << p2.use_count() << '\n';
	std::cout << *p2 << '\n';;

	fun(sp1);
	fun(sp1);
 
	std::cout  <<"------------------"<< std::endl;
	std::cout << std::endl;
	int* p1 = new int[3];
	memset(p1, 0, sizeof(int) * 3);
 
	*p1 = 11;
	*(p1 + 1) = 22;
	*(p1 + 2) = 33;
 
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
    system("pause");
	return 0;
}