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
int main(){
    Node *n ;
    Node Head;
    n = creat_node(10,NULL);
    n = creat_node(12,n);
    n = creat_node(16,n);
    n = creat_node(123,n);
    n = creat_node(1612,n);
    n = creat_node(116,n);
    Head = *n;
    cout<<"You Last assign data = "<<(*n).data<<endl;
    n = (*n).next;
    cout<<"Previous data = "<<(*n).data<<endl;
    n = (*n).next;
    cout<<"Previous data = "<<(*n).data<<endl;
    n = (*n).next;
    cout<<"Previous data = "<<(*n).data<<endl;
    n = (*n).next;
    cout<<"Previous data = "<<(*n).data<<endl;
    n = (*n).next;
    cout<<"Previous data = "<<(*n).data<<endl;
    n = &Head;
    cout<<"Last you Entered = "<<(*n).data<<endl;
    n = creat_node(1234,n);
    Head = (*n);
    cout<<"Finally append = "<<(*n).data<<endl;
    return 0;
}
