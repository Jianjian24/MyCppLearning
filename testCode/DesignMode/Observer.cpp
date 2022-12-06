//
// Created by 刘春雷 on 2020/3/28.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

class ObserverInterface{
public:
    virtual void dosomething()=0;

    //virtual ~ObserverInterface(){}
};

using pObserverInterface=std::shared_ptr<ObserverInterface>;
class SubjectInterface{
public:
    virtual void Add(pObserverInterface obr)=0;
    virtual void Remove(pObserverInterface obr)=0;
    virtual void Notify()=0;

    //virtual ~SubjectInterface(){}
};


class Me:public SubjectInterface{
public:
    void Add(pObserverInterface obr) override{
        observers.push_back(obr);
    }

    void Remove(pObserverInterface obr) override{
        auto pos=std::find(observers.begin(),observers.end(),obr);
        if(pos!=observers.end()){//找到了
            observers.erase(pos);
        }
    }

    void Notify() override{
        for(const auto& obs:observers){
            obs->dosomething();
        }
    }

private:
    std::vector<pObserverInterface> observers;
};


class Wife:public ObserverInterface{
public:
    void dosomething() override{
        std::cout<<"cooking"<<std::endl;
    }

};

class Son:public  ObserverInterface{
public:
    void dosomething() override {
        std::cout<<"not play"<<std::endl;
    }
};


int main(){
    Me me;
    auto wife=std::make_shared<Wife>();
    auto son=std::make_shared<Son>();
    me.Add(wife);
    me.Add(son);

    //下班了 发消息
    me.Notify();
    me.Notify();
    me.Notify();

}