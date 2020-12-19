#include<iostream>
using namespace std;

template<typename type>
class BSTree{
    class Node{
    public:
        type data;
        Node *parent;
        Node *Left;
        Node *Right;
    };
    Node *Root;
    void connect(Node *node,Node *to){
        if(node->data < to->data){
            if(to->Left == nullptr){
                to->Left = node;
                node->parent = to;
            }else{
                connect(node, to->Left);
            }
        }else if(node->data > to->data){
            if(to->Right == nullptr){
                to->Right = node;
                node->parent = to;
            }else{
                connect(node,to->Right);
            }
        }
    }
    void swap_(Node *node1,Node *node2){
        type temp = node1->data;
        node1->data = node2->data;
        node2->data = temp;
    }
    void print(Node *node){
        cout<<"Data : "<<node->data<<endl;
        if(node->parent!=nullptr){
            cout<<"parent : "<<(node->parent)->data<<endl;
        if(node->Left!=nullptr){
            cout<<"Left : "<<(node->Left)->data<<endl;
        }
        }if(node->Right!=nullptr){
            cout<<"Right : "<<(node->Right)->data<<endl;
        }
    }
public:
    BSTree(type root){
        Root = (Node*) new Node;
        Root->parent = nullptr;
        Root->Left = nullptr;
        Root->Right = nullptr;
        Root->data = root;
    }
    void insert_item(type data){
        Node* new_node = (Node*) new Node;
        new_node->data = data;
        new_node->Left = nullptr;
        new_node->Right = nullptr;
        connect(new_node,Root);
    }
    Node *root(){
        return Root;
    }
    Node* find_node(type data){
        Node *temp = Root;
        while(temp->data != data){
            if(data < temp->data){
                temp = temp->Left;
            }else{
                temp = temp->Right;
            }
        }return temp;
    }
    void delete_item(type data){
        Node* node = find_node(data);
        if(node != nullptr){
            Node* parent = node->parent;
            Node* child;
            check_again:
            if(node->Left == nullptr && node->Right == nullptr){
                child = nullptr;
            }else if(node->Left == nullptr){
                child = node->Right;
            }else if(node->Right == nullptr){
                child = node->Left;
            }else{
                ///Most Right Child
                child = node;
                while(child->Right != nullptr){
                    child = child->Right;
                }
                swap_(child,node);
                parent = child->parent;
                node = child;
                goto check_again;
            }
            if(parent->Right == node){
                parent->Right = child;
            }else{
                parent->Left = child;
            }if(child != nullptr){
                child->parent = parent;
            }
        }else cout<<"Not found"<<endl;
    }
    void postorder(Node *node){
        if(node->Left != nullptr){
            postorder(node->Left);
        }
        if(node->Right != nullptr){
            postorder(node->Right);
        }cout<<node->data<<' ';
    }
};
/**
             ---5----
            /        \
          -3-       --9--
         /   \     /     \
        1-    4   6-     -11
          \         \   /
           2         7 10


Preeorder Travers : A B D H E C F I G J
In order Travers : H D B E A I F C G J
Postorder Travers : H D E B I F J G C A
Postorder Travers : 2 1 4 3 6 10 11 9 5

*/
int main(){
    BSTree<int> tree1(5);
    tree1.insert_item(3);
    tree1.insert_item(9);
    tree1.insert_item(11);
    tree1.insert_item(4);
    tree1.insert_item(1);
    tree1.insert_item(6);
    tree1.insert_item(2);
    tree1.insert_item(10);
    tree1.insert_item(7);
    cout<<"Post Order : ";
    tree1.postorder(tree1.root());
    tree1.delete_item(2);
    cout<<"\nAfter deleting 2 (no child) : ";
    tree1.postorder(tree1.root());
    tree1.insert_item(2);
    tree1.delete_item(6);
    cout<<"\nAfter deleting 6 (one child) : ";
    tree1.postorder(tree1.root());
    tree1.insert_item(6);
    tree1.delete_item(9);
    cout<<"\nAfter deleting 9 (two child) : ";
    tree1.postorder(tree1.root());
    tree1.insert_item(9);
    return 0;
}

