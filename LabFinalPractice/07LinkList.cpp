#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
};
Node* head;
Node* createNode(int value){
    Node* newNode = new Node;
    newNode->data=value;
    newNode->next=nullptr;
    return newNode;
}
void append(int value){
    Node* tail=head;
    while(tail->next!=nullptr){
        tail=tail->next;
    }
    tail->next=createNode(value);
}
void prepend(int value){
    Node* newNode=createNode(value);
    newNode->next=head;
    head=newNode;
}
int listSize(){
    int lsize{0};
    Node* node=head;
    while(node!=nullptr){
        lsize++;
        node=node->next;
    }return lsize;
}
void insertAtPosition(int value,int position){
    if(position==0){
        prepend(value);
    }
    else if(position<listSize()){
        Node* node=head;
        for(int i=1;i<position;i++){
            node=node->next;
        }
        Node* newNode=createNode(value);
        newNode->next=node->next;
        node->next=newNode;
    }else{
        append(value);
    }
}
void popFront(){
    Node* node=head;
    if(head==nullptr){
        cout<<"List under follow."<<endl;
        return;
    }
    head=head->next;
    delete(node);
}
void popBack(){
    if(listSize()==0){
        cout<<"List under follow."<<endl;
    }else if(listSize()==1){
        head=nullptr;
    }else{
        Node* node=head;
        while((node->next)->next!=nullptr){
            node=node->next;
        }
        Node* delNode=node->next;
        node->next=nullptr;
        delete(delNode);
    }
}
void removeAt(int position){
    if(position<0||position>=listSize()){
        cout<<"Index not found."<<endl;
    }else if(position==0){
        popFront();
    }else{
        Node* node=head;
        for(int i=1;i<position;i++){
            node=node->next;
        }Node* delNode=node->next;
        node->next=delNode->next;
        delete(delNode);
    }
}
Node* reverselist(){
    Node* newHead=createNode(head->data);
    Node* node=head->next;
    while(node!=nullptr){
        Node* newNode=createNode(node->data);
        newNode->next=newHead;
        newHead=newNode;
        node=node->next;
    }return newHead;
}
void print(Node* head){
    Node* node=head;
    while(node!=nullptr){
        cout<<node->data<<' ';
        node=node->next;
    }cout<<endl;
}
int main(){
    head=createNode(5);
    prepend(4);
    append(3);
    prepend(7);
    append(1);
    insertAtPosition(11,6);
    print(head);
    popFront();
    cout<<"After removing from front : ";
    print(head);
    popBack();
    cout<<"After removing from back : ";
    print(head);
    removeAt(4);
    print(head);
    Node *rHead=reverselist();
    cout<<"reverse is : ";
    print(rHead);
}
