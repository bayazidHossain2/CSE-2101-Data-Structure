#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
};
Node *headp,*endp;
Node* create_node(int item,Node* prev){
    Node* new_node=(Node*)new Node;
    if(new_node==nullptr){
        cout<<"Fail to create node"<<endl;
        return nullptr;
    }
    new_node->data=item;
    new_node->next=nullptr;
    if(prev!=nullptr){
        prev->next=new_node;
    }
    return new_node;
}
///-----------Traverse----------------/
int list_size(){
    int l_size{0};
    Node* node=headp;
    while(node!=nullptr){
        l_size++;
        node=node->next;
    }return l_size;
}
void print(){
    Node* node=headp;
    while(node!=nullptr){
        cout<<node->data<<' ';
        node = node->next;
    }cout<<endl;
}
bool is_present(int item){
    Node* node=headp;
    while(node!=nullptr){
        if(node->data==item) return true;
    }return false;
}
Node* get_node_by_item(int item){
    Node* node=headp;
    while(node!=nullptr){
        if(node->data==item) return node;
        node=node->next;
    }return nullptr;
}
Node* get_node_by_position(int pos){
    if(pos<0||pos>=list_size()){
        cout<<"Invalid position"<<endl;
        return nullptr;
    }
    Node* node=headp;
    while(pos-->0){
        node=node->next;
    }return node;
}
Node* get_previous_node(Node* node,Node* start=headp){
    while(start!=nullptr){
        if(start->next==node){
            return start;
        }start=start->next;
    }return nullptr;
}
///---------------Insertion---------------------/
void prepend(int item){
    Node* new_node=create_node(item,nullptr);
    new_node->next=headp;
    headp=new_node;
}
void append(int item){
    endp=create_node(item,endp);
}
void insert_after_node(Node* node,int item){
    Node* node_next=node->next;
    Node* new_node=create_node(item,node);
    new_node->next=node_next;
}
void insert_at_position(int pos,int item){
    if(pos>list_size()||pos<0){
        cout<<"Invalid position"<<endl;
    }else if(pos==0){
        prepend(item);
    }else if(pos==list_size()){
        cout<<"apending"<<endl;
        append(item);
    }else{
        Node* node=headp;
        pos--;
        while(pos-->0){
            node=node->next;
        }insert_after_node(node,item);
    }
}
///----------------Deletion-------------------/
void remove_node(Node *node){
    if(node==headp){
        headp=node->next;
        delete(node);
        return;
    }
    Node* prev=headp;
    while(prev!=nullptr){
        if(prev->next==node){
            break;
        }prev=prev->next;
    }if(prev==nullptr){
        cout<<"node not found"<<endl;
        return;
    }
    if(prev->next==endp){
        endp=prev;
    }
    prev->next=node->next;
    delete(node);
}
void remove_at_position(int pos){
    if(pos>=list_size()||pos<0){
        cout<<"Invalid position"<<endl;
    }else{
        Node* node=headp;
        while(pos-->0){
            node=node->next;
        }remove_node(node);
    }
}
void pop_front_(){
    remove_at_position(0);
}
void pop_back_(){
    remove_at_position(list_size()-1);
}
void remove_item(int item){
    Node* node=get_node_by_item(item);
    if(node==nullptr){
        cout<<"Item : "<<item<<" not found"<<endl;
    }else{
        remove_node(node);
    }
}
void remove_all_item(int item){
    Node* node=get_node_by_item(item);
    if(node==nullptr){
        return;
    }else{
        remove_node(node);
        remove_all_item(item);
    }
}
///---------------Operation---------/
void swap_data(Node* n1,Node* n2){
    int temp=n1->data;
    n1->data=n2->data;
    n2->data=temp;
}
void swap_node(Node* n1,Node* n2){
    Node* prev1,*prev2,*temp;
    if(n1==headp){
        //cout<<"n1 is head"<<endl;
        prev2=get_previous_node(n2);
        //cout<<"prev of n2 : "<<prev2->data<<endl;
        prev2->next=n1;
        temp=n1->next;
        n1->next=n2->next;
        n2->next=temp;
        headp=n2;
    }else if(n2==headp){
        //cout<<"n2 is head"<<endl;
        prev1=get_previous_node(n1);
        prev1->next=n2;
        temp=n2->next;
        n2->next=n1->next;
        n1->next=temp;
        headp=n1;
    }else{
        prev1=get_previous_node(n1);
        prev2=get_previous_node(n2);
        prev1->next=n2;
        temp=n2->next;
        n2->next=n1->next;
        n1->next=temp;
        prev2->next=n1;
    }
}
void reverse_all(){
    Node *node=headp->next,*node_next=headp,*temp;
    endp=headp;
    endp->next=nullptr;
    while(node!=nullptr){
        temp=node->next;
        node->next=node_next;
        node_next=node;
        node=temp;
    }headp=node_next;
}
void sort_all(){
    for(Node* n1=headp;n1!=nullptr;n1=n1->next){
        Node* min_node=n1;
        for(Node* n2=n1->next;n2!=nullptr;n2=n2->next){
            if(n2->data<min_node->data) min_node=n2;
        }if(n1!=min_node){
            swap_data(n1,min_node);
        }
    }
}
int main(){
    headp=create_node(10,nullptr);
    endp=headp;
    Node* node1,*node2;
    endp=create_node(11,endp);
    endp=create_node(12,endp);
    node2=endp;
    endp=create_node(13,endp);
    node1=endp;
    endp=create_node(14,endp);
    print();
    prepend(9);
    cout<<"After prepend 9 :"<<endl;
    print();
    prepend(8);
    cout<<"After prepend 8 :"<<endl;
    print();
    append(15);
    cout<<"After append 15 :"<<endl;
    print();
    append(16);
    cout<<"After append 16 :"<<endl;
    print();
    insert_after_node(node1,133);
    cout<<"Insert after : "<<node1->data<<endl;
    print();
    insert_after_node(node2,122);
    cout<<"Insert after : "<<node2->data<<endl;
    print();
    remove_node(headp);
    cout<<"After remove head :"<<endl;
    print();
    remove_node(headp);
    cout<<"After remove head :"<<endl;
    print();
    cout<<"After remove "<<node1->data<<" :"<<endl;
    remove_node(node1);
    print();
    cout<<"After remove "<<node2->data<<" :"<<endl;
    remove_node(node2);
    print();
    if(node1==nullptr){
        cout<<"node1 is free now"<<endl;
    }else{
        cout<<"node data : "<<node1->data<<endl;
    }
    cout<<"After remove "<<endp->data<<" :"<<endl;
    remove_node(endp);
    print();
    cout<<"present end : "<<endp->data<<endl;
    cout<<"After remove "<<endp->data<<" :"<<endl;
    remove_node(endp);
    print();
    cout<<"present end : "<<endp->data<<endl;
    insert_at_position(2,6);
    cout<<"insert 6 at position 2 : "<<endl;
    print();
    remove_at_position(0);
    cout<<"After remove at position 0 :"<<endl;
    print();
    prepend(19);
    cout<<"After prepend 19 :"<<endl;
    print();
    remove_at_position(5);
    cout<<"After remove at position 5 :"<<endl;
    print();
    append(21);
    cout<<"After append 21 :"<<endl;
    print();
    cout<<"List size : "<<list_size()<<endl;
    pop_back_();
    cout<<"after pop back : "<<endl;
    print();
    remove_item(133);
    cout<<"after remove 133 : "<<endl;
    print();
    insert_at_position(3,12);
    append(12);
    prepend(12);
    print();
    remove_all_item(12);
    cout<<"After removing all 12 :"<<endl;
    print();
    prepend(13);
    append(15);
    print();
    swap_data(headp,endp);
    cout<<"After swap : "<<endl;
    print();
    reverse_all();
    cout<<"After reverse all :"<<endl;
    print();
    append(11);
    prepend(20);
    print();
    sort_all();
    cout<<"After sort :"<<endl;
    print();
    node1=get_node_by_position(3);
    node2=get_node_by_position(5);
    cout<<"Swap "<<node1->data<<" and "<<node2->data<<" :"<<endl;
    swap_node(node1,node2);
    print();
}
