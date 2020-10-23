#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
};
Node *creat_node(int item,Node *next){
    Node *n_node=(Node*) new Node;
    if(n_node == NULL){
        cout<<"Error!! \n Could Not create new node"<<endl;
        exit(1);
    }
    n_node->data = item;
    n_node->next = next;
    return n_node;
}
Node *prepend(Node *head,int item){
    Node *new_node = creat_node(item,head);
    return new_node;
}
Node *append(Node *endp,int item){
    Node *new_node = creat_node(item,NULL);
    (*endp).next = new_node;
    return new_node;
}
void print(Node *head){
    cout<<(*head).data<<' ';
    while((*head).next != NULL){
        head = (*head).next;
        cout<<(*head).data<<' ';
    }cout<<endl;
}
int main(){
    Node *n ,*head,*endp;
    cout<<"Use of prepend function: "<<endl;
    n = creat_node(10,NULL);
    head = n;
    endp = n;
    head = prepend(head,20);
    head = prepend(head,30);
    head = prepend(head,40);
    print(head);
    cout<<"Use of append function: "<<endl;
    endp = append(endp,1);
    endp = append(endp,100);
    print(head);
    cout<<"Again prepend : "<<endl;
    head = prepend(head,50);
    print(head);
    return 0;
}

