#include <iostream>
#include <vector>
#include <list>

using std::cin;
using std::cout;
using std::vector;
using std::list;

typedef unsigned int        UINT;
typedef struct gap
{
    UINT senderCardId;
    UINT receiverCardId;
    UINT modualId;
    UINT lineNum;
    vector<double> pointGap;
    
    //不要输入index 小于0大于3 的数值！
    UINT& operator[] (int index)
    {
        if( index == 0) return this->senderCardId;
        if( index == 1) return this->receiverCardId;
        if( index == 2) return this->modualId;
        if( index == 3) return this->lineNum;
    }

}LEDGAP;

void initLEDGAP(LEDGAP& gap, 
                UINT senderCardId,
                UINT receiverCardId,
                UINT modualId,
                UINT lineNum,
                vector<double>& v1)
{
    gap.senderCardId = senderCardId;
    gap.receiverCardId = receiverCardId;
    gap.modualId = modualId;
    gap.lineNum = lineNum;
    gap.pointGap = v1;
}

void traverse(list<LEDGAP>& l)
{
    for (auto it = l.begin(); it != l.end(); it++) {
        for (int i = 0; i < it->lineNum; i++)
        {
            cout << it->senderCardId << "--" <<
                    it->receiverCardId << "--" <<
                    it->modualId << "--" <<
                    it->pointGap.at(i) << "\n";    
        }
    }
    cout << std::endl;
}

int main()
{
    LEDGAP gap1;
    LEDGAP gap2;
    LEDGAP gap3;

    vector<double> tempVector1(7,1.1);
    initLEDGAP(gap1, 1, 1, 1, 7,tempVector1);
    vector<double> tempVector2(6,1.2433);
    initLEDGAP(gap2, 1, 1, 2, 6, tempVector2);
    vector<double> tempVector3(7,0.9889);
    initLEDGAP(gap3, 1, 1, 3, 7, tempVector3);

    list<LEDGAP> ledList{gap1, gap2};

    auto it1 = ledList.end();
    std::advance(it1, -1);
    ledList.insert(ledList.end(), gap3);//在1 2 中间插入3

    traverse(ledList);

    // gap.pointGap.push_back(12);
    // gap.pointGap.push_back(12);
    // gap.pointGap.push_back(12);
    // gap.pointGap.push_back(12);
    // gap.pointGap.push_back(12);
    // gap.pointGap.push_back(12);
    // gap.pointGap.push_back(12);
    // // gap.pointGap.push_back(12);
    // cout << gap.pointGap.size() << "\n";
    // cout << sizeof(gap.pointGap) << "\n";
    // cout << sizeof(double) << "\n";

    LEDGAP gap4;
    vector<double> tempVector4(7,1.1);
    initLEDGAP(gap4, 1, 1, 1, 7,tempVector4);

    gap4[0] = 100;

    cout << gap4.senderCardId << "LLLLLLLLLL\n"; 

    return 0;
}
