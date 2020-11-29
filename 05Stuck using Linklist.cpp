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
    Node *Top;
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
        Node *temp = Top->prev;
        if(temp == nullptr){
            return Top;
        }
        temp->next = nullptr;
        delete(Top);
        return temp;
    }
public:
    Stuck(){
        Top = (Node*) new Node;
        if(Top == nullptr){
            cout<<"Space not found."<<endl;
        }
    }
    ~Stuck(){
        while(Top->next != nullptr){
            Node *temp = Top;
            Top = temp->prev;
            delete(temp);
        }delete(Top);
    }
    void push(type item){
        if(Stuck_size_ == 0){
            Top->data = item;
            Top->next = nullptr;
            Top->prev = nullptr;
            Stuck_size_++;
        }else{
            Top = creat_node(item,Top);
        }
    }
    bool is_stuck_empty(){
        if(Stuck_size_ == 0) return true;
        else return false;
    }
    type top(){
        return Top->data;
    }
    type pop(){
        if(is_stuck_empty()){
            cout<<"Stuck is empty."<<endl;
        }else{
            type item = Top->data;
            Top = remove_node();
            return item;
        }return -1;
    }
    int Stuck_size(){
        return Stuck_size_;
    }
    void print(){
        cout<<"stuck size : "<<Stuck_size_<<endl;
        Node *cNode = Top;
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
