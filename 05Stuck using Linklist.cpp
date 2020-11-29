#include<iostream>
using namespace std;
template<typename type>
class Stuck{
    class Node{
    public:
        type data;
        Node *next;
        Node *prev;
    };
    Node *top;
    int Stuck_size_{0};
    Node *creat_node(type item,Node* node){
        Stuck_size_++;
        Node *newNode = (Node*)new Node;
        newNode->data = item;
        newNode->next = nullptr;
        newNode->prev = node;
        node->next = newNode;
        return newNode;
    }
    Node *remove_node(){
        Stuck_size_--;
        Node *temp = top->prev;
        if(temp == nullptr){
            return top;
        }
        temp->next = nullptr;
        delete(top);
        return temp;
    }
public:
    Stuck(){
        top = (Node*) new Node;
        if(top == nullptr){
            cout<<"Space not found."<<endl;
        }
    }
    void push(type item){
        if(Stuck_size_ == 0){
            top->data = item;
            top->next = nullptr;
            top->prev = nullptr;
            Stuck_size_++;
        }else{
            top = creat_node(item,top);
        }
    }
    bool is_Stuck_empty(){
        if(Stuck_size_ == 0) return true;
        else return false;
    }
    type pop(){
        if(is_Stuck_empty()){
            cout<<"Stuck is empty."<<endl;
        }else{
            type item = top->data;
            top = remove_node();
            return item;
        }return -1;
    }
    int Stuck_size(){
        return Stuck_size_;
    }
    void print(){
        cout<<"stuck size : "<<Stuck_size_<<endl;
        Node *cNode = top;
        while(cNode != nullptr){
            cout<<cNode->data<<' ';
            cNode = cNode->prev;
        }cout<<endl;
    }
};
int main(){
    Stuck<char> ss;
    cout<<ss.pop()<<endl;
    ss.push('U');
    ss.push('T');
    ss.push('L');
    ss.print();
    ss.push('A');
    ss.push('F');
    ss.print();
    cout<<ss.pop();
    cout<<ss.pop();
    cout<<ss.pop();
    ss.push(')');
    cout<<ss.pop();
    cout<<ss.pop()<<endl;
    cout<<ss.pop()<<endl;
    cout<<ss.pop()<<endl;
    cout<<ss.pop()<<endl;
    ss.push(')');
    ss.push(':');
    cout<<ss.pop()<<endl;
    ss.print();
    return 0;
}
