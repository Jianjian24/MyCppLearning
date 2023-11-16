#include "../../../jian.h"

class Node
{
    public:
    int a = 9;
    float b = 8.2;

    ~Node()
    {
        cout << "Node deleted\n";
    }
};

void testDel()
{
    vector<Node*> vecPNode;

    Node* newNode = new Node;
    vecPNode.push_back(newNode);

    newNode = new Node;
    vecPNode.push_back(newNode);

    newNode = new Node;
    vecPNode.push_back(newNode);

        newNode = new Node;
    vecPNode.push_back(newNode);    newNode = new Node;
    vecPNode.push_back(newNode);    newNode = new Node;
    vecPNode.push_back(newNode);    newNode = new Node;
    vecPNode.push_back(newNode);    newNode = new Node;
    vecPNode.push_back(newNode);

    for(auto iter=vecPNode.begin();iter!=vecPNode.end(); ){
        delete (*iter);
        iter = vecPNode.erase(iter);
    }
}


int main()
{

    testDel();

    cout << "Node Ended\n";

    return 0;
}