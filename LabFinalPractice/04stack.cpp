#include<iostream>
using namespace std;
class Stack{
private:
    static const int stuckSize=1000;
    int data[stuckSize];
    int cind=0;
public:
    void push(int value){
        if(cind==stuckSize){
            cout<<"Stuck over follow"<<endl;
            return;
        }
        data[cind]=value;
        cind++;
    }
    int pop(){
        if(cind==0){
            cout<<"Stuck under follow"<<endl;
            return -1;
        }
        cind--;
        return data[cind];
    }
    bool isEmpty(){
        if(cind==0){
            return false;
        }return true;
    }
    void print(){
        for(int i=0;i<cind;i++){
            cout<<data[i]<<' ';
        }cout<<endl;
    }

};

int main(){
    Stack stuck;
    stuck.push(23);
    stuck.push(3);
    stuck.push(2);
    stuck.push(12);
    cout<<stuck.pop()<<endl;
    stuck.print();
    while(stuck.isEmpty()){
        cout<<stuck.pop()<<endl;
    }
    cout<<stuck.pop()<<endl;
}
