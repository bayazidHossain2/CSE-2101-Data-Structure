#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};
Node *head,*endp;
///Insertion
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
void insert(Node *node,int item){
    Node *new_node = creat_node(item,node->next);
    node->next = new_node;
}
///Deletion
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
    if(current_node->next == endp){
        endp = current_node;
        endp->next = nullptr;
        delete(node);
    }
    current_node->next = node->next;
    delete(node);
}
void remove_item(int item){
    Node *current_node = head;
    while(current_node != nullptr){
        if(current_node->data == item){
            break;
        }current_node = current_node->next;
    }if(current_node == nullptr){
        cout<<item<<" not found."<<endl;
    }else{
        remove_node(current_node);
    }
}
void removeall_item(int item){
    Node *current_node = head;
    while(current_node != nullptr){
        if(current_node->data == item){
            remove_node(current_node);
        }current_node = current_node->next;
    }
}
///Traversing
void print(){
    Node *current_node = head;
    cout<<current_node->data<<' ';
    while((*current_node).next != NULL){
        current_node = (*current_node).next;
        cout<<(*current_node).data<<' ';
    }cout<<endl;
}
int list_size(){
    int lsize = 0;
    Node *current_node = head;
    while(current_node != nullptr){
        lsize++;
        current_node = current_node->next;
    }return lsize;
}
///Searching
Node *find_item(int item){
    Node *current_node = head;
    while(current_node != nullptr){
        if(current_node->data == item){
            return current_node;
        }current_node = current_node->next;
    }return nullptr;
}
bool is_present(int item){
    if(find_item(item) == nullptr) return false;
    return true;
}
///Sorting
void swap(Node *n1,Node *n2){
    Node *temp = n1;
    n1 = n2;
    n2 = temp;
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
    print();
    cout<<"Use of append function: "<<endl;
    append(1);
    append(100);
    print();
    cout<<"Again prepend : "<<endl;
    prepend(50);
    print();
    cout<<"Delete some node"<<endl;
    remove_node(head);
    cout<<"After delete first node : ";
    print();
    cout<<"List size : "<<list_size()<<endl;

    Node *any_node = head->next;
    any_node = any_node->next;
    cout<<"Delete "<<any_node->data<<" from the data set : "<<endl;
    remove_node(any_node);
    print();
    remove_node(endp);
    cout<<"After deleting last element : ";
    print();
    cout<<"Next element "<<head->data<<' '<<endp->data<<endl;
    cout<<"Again append 11 and prepend 13 : ";
    append(11);
    prepend(13);
    print();
    cout<<"Delete "<<30<<" from list : ";
    remove_item(30);
    print();
    cout<<"Delete first item : ";
    remove_item(head->data);
    print();
    cout<<"Delete last item : ";
    remove_item(endp->data);
    print();
    cout<<"Delete a item which is not included on the list : ";
    remove_item(19);
    print();
    cout<<"Again append 110 and prepend 103 : ";
    append(110);
    prepend(103);
    print();
    cout<<"Insert item after head : ";
    insert(head,34);
    print();
    append(34);
    prepend(34);
    print();
    removeall_item(34);
    print();
    cout<<"Again append 11 and prepend 99 : ";
    append(11);
    prepend(99);
    print();
    cout<<"List size : "<<list_size()<<endl;

    any_node = find_item(50);
    if(any_node != nullptr){
        cout<<any_node->data<<endl;
    }else cout<<"Not found."<<endl;
    if(is_present(1)) cout<<"1 ia present."<<endl;
    else cout<<"1 is not present."<<endl;

    return 0;
}
