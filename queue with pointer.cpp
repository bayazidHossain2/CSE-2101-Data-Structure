#include<iostream>
using namespace std;
template<typename Type>
class my_queue{
    Type *data;
    int first;
    int last;
public:
    my_queue(){
        data = new Type;
        if(data == NULL){
            cout<<"Space not found..."<<endl;
        }
        first = 0;
        last = 0;
    }
    void push(Type item){
        data[last] = item;
        last++;
    }
    Type pop(){
        if(last-first == 0){
            cout<<"My_queue is empty..."<<endl;
            return -1;
        }
        return data[first++];
    }
    int size(){
        return last-first;
    }
};
int main(){
    my_queue<char> qu;
    qu.push('(');
    qu.push(')');
    qu.push('}');
    qu.push('{');
    char data = qu.pop();
    while(data != -1){
        cout<<data<<endl;
        data = qu.pop();
    }
    cout<<"Program terminate successfully.."<<endl;
    return 0;
}

