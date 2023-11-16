#include <iostream>
#include <mutex>
#include <thread>

// 定义一个共享资源
int shared_resource = 0;

// 定义一个线程函数，用于修改共享资源
void update_shared_resource() {
std::mutex mtx;
std::lock_guard<std::mutex> lock(mtx);  // 使用std::lock_guard确保在执行完同步操作后，锁会被自动释放
shared_resource++;
}

int main()
{
    // 创建多个线程
    std::thread threads[10];

    // 启动线程
    for (int i = 0; i < 10; ++i) {
    threads[i] = std::thread(update_shared_resource);
    }

    // 等待所有线程完成
    for (int i = 0; i < 10; ++i) {
    threads[i].join();
    }

    std::cout << "Shared resource value: " << shared_resource << std::endl;
}
