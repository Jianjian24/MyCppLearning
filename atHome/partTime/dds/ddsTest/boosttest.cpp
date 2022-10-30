// boosttest.cpp : 定义控制台应用程序的入口点。
//
 
#include "afxres.h"
 
// #include <boost/lexical_cast.hpp>       
#include <iostream>
// #include <boost/interprocess/shared_memory_object.hpp>
// #include <boost/interprocess/mapped_region.hpp>
 
using namespace std;
using namespace boost::interprocess;
 
int main(int argc,char *argv[])
{
	cout << "argc" << argc<<argv[0];
	if (argc == 1) {//父进程
		//1 删除共享内存
		struct  shm_remove
		{
			shm_remove() { shared_memory_object::remove("SharedMemory"); }
			~shm_remove() { shared_memory_object::remove("SharedMemory"); }
		}remover;
 
 
	//2 创建共享内存段
	shared_memory_object shm(create_only, "SharedMemory", read_write);
 
	//3 设置共享内存大小
	shm.truncate(100);
 
	//4 映射共享内存片段
	mapped_region region(shm, read_write);
 
	//5 初始化为1
	std::memset(region.get_address(), 1, region.get_size());
	
	//运行子进程
	std::string s(argv[0]);
	s += " child ";
	if (0 != std::system(s.c_str()))
		return 1;
	}
	else
	{
		//1 创建共享内存
		shared_memory_object shm(open_only, "SharedMemory", read_only);
 
		//2 映射共享内存
		mapped_region region(shm, read_only);
 
		//3 检查共享内存是否被初始化为1
		char* mem = static_cast<char*>(region.get_address());
		for (std::size_t i = 0; i < region.get_size(); ++i) {
			if (*mem++ != 1)
				return 1;
			else
			{
				printf("mem:%d   ", *mem);
			}
		}
	}
 
	system("pause");
	return 0;
}