#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

//LRU 算法练习
//用两个数据结构，以实现高效

struct Node
{
    int key;
    int value;

    Node()
    {
        key = 0;
        value = 0;
    }
};

class LRUCache
{
    list<Node> LRUList;
    unordered_map<int, int> LRUHashMap;
    int capacity;

    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    //put将节点数据放到哈希表里面并且以这个将数据放到链表队头
    void put(Node node);
    //get传入key值，根据key值返回value，并将这个key值所在的节点放到链表首位 
    int get(int key);

};

void put(Node node)
{
    //若节点中数据已满，那么根据链表最后一个位置去找key值，在两个表都是先删完再添加，这也是为什么链表中要存储key的的意义所在
    
    //判断原本的哈希表内有没有这个节点（根据key值去判断）若有，在list中将对应节点移动到链表首尾
}

int get(int key)
{
    //根据哈希表中有没有这个节点，有则返回value，没有则返回一个错误码
}

int main()
{

    return 0;
}
