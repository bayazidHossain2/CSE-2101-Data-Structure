#include<iostream>
using namespace std;
class priorityQueue{
private:
    class Node{
    public:
        int data;
        int prio;
        Node *prev;
        Node *next;
    };
    Node* Head;
    Node* createNode(int value,int priority){
        Node* newNode=new Node;
        newNode->prev=nullptr;
        newNode->next=nullptr;
        newNode->data=value;
        newNode->prio=priority;
        return newNode;
    }
public:
    priorityQueue(){
        Head=nullptr;
    }
    void enqueue(int value,int priority){
        if(Head==nullptr){
            Head=createNode(value,priority);
        }else if(Head->prio>priority){
            Node* nNode=createNode(value,priority);
            nNode->next=Head;
            Head->prev=nNode;
            Head=nNode;
        }else{
            Node* pre=Head;
            while(pre->next!=nullptr&&pre->prio<=priority){
                pre=pre->next;
            }
            Node* nNode=createNode(value,priority);
            if(pre->prio>priority){
                nNode->next=pre;
                nNode->prev=pre->prev;
                (pre->prev)->next=nNode;
                pre->prev=nNode;
            }else{
                nNode->prev=pre;
                pre->next=nNode;
            }
        }cout<<"enqueue finish"<<endl;
    }
    void dequeue(){
        Node* node=Head->next;
        node->prev=nullptr;
        delete(Head);
        Head=node;
    }
    int top(){
        return Head->data;
    }
    void print(){
        cout<<"Forword : ";
        Node* node=Head;
        cout<<Head->data<<' ';
        while(node->next!=nullptr){
            cout<<" ("<<(node->next)->data<<", "<<(node->next)->prio <<')'<<' ';
            node=node->next;
        }cout<<endl;
        cout<<"Backword : ";
        while(node!=nullptr){
            cout<<" ("<<node->data<<", "<<node->prio <<')'<<' ';
            node=node->prev;
        }cout<<endl;
    }
};

int main(){
    priorityQueue pq;
    pq.enqueue(12,2);
    //pq.print();
    pq.enqueue(112,0);
    pq.print();
    pq.enqueue(15,5);
    pq.enqueue(11,2);
    pq.enqueue(13,3);
    pq.enqueue(1,1);
    pq.print();

    cout<<"current top is : "<<pq.top()<<endl;
    cout<<"deque 2 time"<<endl;
    pq.dequeue();
    cout<<"After poping one value : "<<pq.top()<<endl;
    pq.dequeue();
    pq.print();
}
