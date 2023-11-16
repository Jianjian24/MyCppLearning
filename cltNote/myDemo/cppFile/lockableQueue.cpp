#include <mutex>
#include <list>
#include <thread>
#include <iostream>
#include "concurrentqueue.h"

template <typename T>
class LockableQueue {
public:
   LockableQueue() = default;

   void push(T value) {
       std::unique_lock<std::mutex> lock(m_mutex);
       m_queue.push_back(value);
   }

   T pop() {
       std::unique_lock<std::mutex> lock(m_mutex);
       T value = m_queue.front();
       m_queue.pop_front();
       return value;
   }

   bool empty() const {
       std::unique_lock<std::mutex> lock(m_mutex);
       return m_queue.empty();
   }

private:
   std::list<T> m_queue;
   mutable std::mutex m_mutex;
};

LockableQueue<int> queue;

void producer() {
   for (int i = 0; i < 10; ++i) {
       std::cout << "Producing: " << i << std::endl;
       queue.push(i);
       std::this_thread::sleep_for(std::chrono::milliseconds(100));
   }
}

void consumer() {
   for (int i = 0; i < 10; ++i) {
       std::cout << "Consuming: " << queue.pop() << std::endl;
       std::this_thread::sleep_for(std::chrono::milliseconds(150));
   }
}

int main() {
//     std::cout << "Consuming: \n" ;
//    std::thread producerThread(producer);
//     std::cout << "Consuming: \n" ;
//    std::thread consumerThread(consumer);
//     std::cout << "Consuming: \n" ;

//    producerThread.join();
//    consumerThread.join();

//    system("pause");
    moodycamel::ConcurrentQueue<int> q;
    q.enqueue(25);
    int item;
    bool found = q.try_dequeue(item);
    assert(found && item == 25);


   return 0;
}