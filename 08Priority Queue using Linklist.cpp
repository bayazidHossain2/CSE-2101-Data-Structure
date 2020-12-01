#include<iostream>
using namespace std;
template<typename type>
class PriorityQueue{
    class Node{
    public:
        type data;
        int Priority;
        Node *next;
        Node *prev;
    };
    Node *Front,*Rare;
    int Queue_size{0};
    Node *prepend(){
        Node *newNode = (Node*) new Node;
        newNode->next = Front;
        newNode->prev = nullptr;
        Front->prev = newNode;
        return newNode;
    }
    Node *insert(Node* node){
        Node *newNode = (Node*)new Node;
        newNode->next = node->next;
        if(node->next != nullptr){
            (node->next)->prev = newNode;
        }
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
    PriorityQueue(){
        Front = (Node*) new Node;
        Rare = Front;
        if(Front == nullptr){
            cout<<"Space not found."<<endl;
        }
    }
    void enqueue(type item,int priority){
        if(Queue_size == 0){
            Rare->data = item;
            Rare->Priority = priority;
            Rare->next = nullptr;
            Rare->prev = nullptr;
        }else if(priority < Front->Priority){
            Front = prepend();
            Front->data = item;
            Front->Priority = priority;
        }
        else{
            Node *temp = Front;
            bool found = false;
            while(temp->next != nullptr){
                if(temp->Priority > priority){
                    found = true;
                    break;
                }temp = temp->next;
            }if(temp->Priority > priority){
                found = true;
            }Rare = temp;
            //cout<<"temp data while item is : "<<item<<": "<<temp->data<<' '<<found<<endl;
            if(Rare->prev != nullptr && found){
                Rare = Rare->prev;
            }//cout<<"Rare data while item("<<item<<") : "<<Rare->data<<endl;
            Rare = insert(Rare);
            Rare->data = item;
            Rare->Priority = priority;
        }Queue_size++;
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
    PriorityQueue<int> data;
    data.enqueue(123,3);
    data.enqueue(3,2);
    data.print();
    data.enqueue(1,3);
    data.enqueue(13,3);
    data.enqueue(2,1);
    data.enqueue(23,3);
    data.print();
    cout<<"POP data is : "<<data.dequeue()<<' ';
    cout<<data.dequeue()<<' ';
    cout<<data.dequeue()<<' '<<endl;
    cout<<"Now Queue size is : "<<data.queue_size()<<endl;
    data.enqueue(55,2);
    data.enqueue(99,3);
    data.enqueue(9,3);
    data.enqueue(9111,4);
    data.enqueue(11,10);
    data.enqueue(1112,9);
    cout<<"After again enqueue Queue size is : "<<data.queue_size()<<endl;
    cout<<"Queue data is : ";
    data.print();
    return 0;
}
/**
OUTPUT:
3 123
2 3 123 1 13 23
POP data is : 2 3 123
Now Queue size is : 3
After again enqueue Queue size is : 9
Queue data is : 55 1 13 23 99 9 9111 1112 11
*/

