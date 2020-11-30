#include<iostream>
using namespace std;
template<typename type>
class Queue{
    class Node{
    public:
        type data;
        Node *next;
        Node *prev;
    };
    Node *Front,*Rare;
    int Queue_size{0};
    Node *creat_node(type item,Node* node){
        Queue_size++;
        Node *newNode = (Node*)new Node;
        newNode->data = item;
        newNode->next = nullptr;
        newNode->prev = node;
        node->next = newNode;
        return newNode;
    }
    Node *remove_node(){
        Queue_size--;
        Node *temp = Front;
        Front = Front->next;
        if(Front == nullptr){
            return temp;
        }
        Front->prev = nullptr;
        delete(temp);
        return Front;
    }
public:
    Queue(){
        Front = (Node*) new Node;
        Rare = Front;
        if(Front == nullptr){
            cout<<"Space not found."<<endl;
        }
    }
    void enqueue(type item){
        if(Queue_size == 0){
            Rare->data = item;
            Rare->next = nullptr;
            Rare->prev = nullptr;
            Queue_size++;
        }else{
            Rare = creat_node(item,Rare);
        }
    }
    bool is_queue_empty(){
        if(Queue_size == 0) return true;
        else return false;
    }
    type dequeue(){
        if(is_queue_empty()){
            cout<<"Queue is empty."<<endl;
        }else{
            type item = Front->data;
            Front = remove_node();
            return item;
        }return -1;
    }
    type front(){
        return Front;
    }
    int queue_size(){
        return Queue_size;
    }
    void print(){
        Node *cNode = Front;
        while(cNode != nullptr){
            cout<<cNode->data<<' ';
            cNode = cNode->next;
        }cout<<endl;
    }
};
int main(){
    Queue<int> data;
    data.enqueue(123);
    data.enqueue(3);
    data.enqueue(1);
    data.enqueue(13);
    data.enqueue(2);
    data.enqueue(23);
    data.print();
    cout<<"POP data is : "<<data.dequeue()<<' ';
    cout<<data.dequeue()<<' ';
    cout<<data.dequeue()<<' '<<endl;
    cout<<"Now Queue size is : "<<data.queue_size()<<endl;
    data.enqueue(55);
    data.enqueue(99);
    cout<<"After again enqueue Queue size is : "<<data.queue_size()<<endl;
    cout<<"Queue data is : ";
    data.print();
    return 0;
}

