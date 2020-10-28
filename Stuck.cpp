#include<iostream>
using namespace std;
template <typename Type>
class Node{
public:
    Type data;
    Node *next;
};
template <typename Type>
class Stuck{
    Node<Type> *Top;
    int size{0};
    Node<Type> *creat_node(Type item,Node<Type> *next){
        Node<Type> *new_node=(Node<Type>*) new Node<Type>;
        if(new_node == NULL){
            cout<<"Error!! \n Could Not create new node"<<endl;
            exit(1);
        }
        new_node->data = item;
        new_node->next = next;
        return new_node;
    }
    Node<Type> *prepend(Node<Type> *head,int item){
        Node<Type> *new_node = creat_node(item,head);
        return new_node;
    }
    Node<Type> *append(Node<Type> *endp,int item){
        Node<Type> *new_node = creat_node(item,NULL);
        (*endp).next = new_node;
        return new_node;
    }
public:
    void push(Type item){
        if(size == 0){
            Top = creat_node(item,NULL);
        }else{
            Top = creat_node(item,Top);
            //cout<<(*Top).data<<endl;
        }size ++;
    }
    Type pop(){
        if(size != 0){
            Type data = (*Top).data;
            Top = Top->next;
            size--;
            return data;
        }else{
            cout<<"Stuck is empty!!"<<endl;
        }
        return -1;
    }
    int len(){
        return size;
    }
};
/*void print(Node *head){
    cout<<(*head).data<<' ';
    while((*head).next != NULL){
        head = (*head).next;
        cout<<(*head).data<<' ';
    }cout<<endl;
}*/
int main(){
    cout<<"Use of prepend function: "<<endl;
    Stuck<int> ob;
    ob.push(3);
    ob.push(5);
    ob.push(9);
    ob.push(0);
    ob.push(2);
    cout<<ob.len()<<endl;
    cout<<"pop 1 "<<ob.pop()<<endl;
    cout<<"pop 2 "<<ob.pop()<<endl;
    cout<<"pop 3 "<<ob.pop()<<endl;
    cout<<"pop 4 "<<ob.pop()<<endl;
    cout<<"pop 5 "<<ob.pop()<<endl;
    cout<<"pop 6 "<<ob.pop()<<endl;
    cout<<"Int Stuck finished"<<endl;
    Stuck<char> chob;
    chob.push('{');
    chob.push('[');
    chob.push('(');
    chob.push(')');
    chob.push('}');
    cout<<"pop 1 "<<chob.pop()<<endl;
    cout<<"pop 2 "<<chob.pop()<<endl;
    cout<<"pop 3 "<<chob.pop()<<endl;
    cout<<"pop 4 "<<chob.pop()<<endl;
    cout<<"pop 5 "<<chob.pop()<<endl;
    cout<<"pop 6 "<<chob.pop()<<endl;
    return 0;
}


