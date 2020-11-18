#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
};
Node *head,*endp;
Node *creat_node(int item,Node *next){
    Node *new_node=(Node*) new Node;
    if(new_node == NULL){
        cout<<"Error!! \n Could Not create new node"<<endl;
        exit(1);
    }
    new_node->data = item;
    new_node->next = next;
    return new_node;
}
void prepend(int item){
    Node *new_node = creat_node(item,head);
    head = new_node;
}
void append(int item){
    Node *new_node = creat_node(item,nullptr);
    (*endp).next = new_node;
    endp = new_node;
}
void remove_node(Node *node){
    if(node == head){
        head = node->next;
        delete(node);
        return;
    }
    Node *current_node = head;
    while(current_node != nullptr){
        if(current_node->next == node){
            break;
        }current_node = current_node->next;
    }
    if(node == endp){
        endp = current_node;
        delete(node);
        return;
    }
    current_node->next = node->next;
    delete(node);
}
void print(Node *head){
    cout<<(*head).data<<' ';
    while((*head).next != NULL){
        head = (*head).next;
        cout<<(*head).data<<' ';
    }cout<<endl;
}
int main(){
    Node *n;
    cout<<"Use of prepend function: "<<endl;
    n = creat_node(10,NULL);
    head = n;
    endp = n;
    prepend(20);
    prepend(30);
    prepend(40);
    print(head);
    cout<<"Use of append function: "<<endl;
    append(1);
    append(100);
    print(head);
    cout<<"Again prepend : "<<endl;
    prepend(50);
    print(head);
    cout<<"Delete some node"<<endl;
    remove_node(head);
    cout<<head->data<<endl;
    cout<<"After delete first node : ";
    print(head);

    Node *any_node = head->next;
    any_node = any_node->next;
    cout<<"Delete "<<any_node->data<<" from the data set : "<<endl;
    remove_node(any_node);
    print(head);
    remove_node(endp);
    cout<<"After deleting last element : ";
    print(head);
    cout<<"Again append 11 and prepend 13 : ";
    append(11);
    prepend(13);
    print(head);
    return 0;
}

