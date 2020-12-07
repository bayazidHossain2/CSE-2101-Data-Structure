#include<iostream>
using namespace std;
#define MaxNode 1000
template<typename type>
class Tree{
    type arr[MaxNode+1];
public:
    Tree(type root){
        arr[1] = root;
        for(int i = 2;i < MaxNode;i++){
            arr[i] = -1;
        }
    }
    int addLeft(int index,type data){
        if(2*index < MaxNode){
            arr[2*index] = data;
        }return 2*index;
    }
    int addRight(int index,type data){
        if((2*index)+1<MaxNode){
            arr[(2*index)+1] = data;
        }return (2*index)+1;
    }
    int parent(int index){
        return index/2;
    }
    int left(int index){
        return 2*index;
    }
    int right(int index){
        return (2*index)+1;
    }
    type &at(int index){
        return arr[index];
    }
    void inorder(int index){
        if(arr[left(index)] != -1){
            inorder(left(index));
        }cout<<arr[index]<<' ';
        if(arr[right(index)] != -1){
            inorder(right(index));
        }
    }
    void preeorder(int index){
        cout<<arr[index]<<' ';
        if(arr[left(index)] != -1){
            //cout<<" lc " << arr[left(index)] <<' ';
            preeorder(left(index));
        }
        if(arr[right(index)] != -1){
            //cout<<" rc ";
            preeorder(right(index));
        }
    }
    void postorder(int index){
        if(arr[left(index)] != -1){
            postorder(left(index));
        }
        if(arr[right(index)] != -1){
            postorder(right(index));
        }cout<<arr[index]<<' ';
    }
};
/**
             ---A---
            /       \
          -B-       -C-
         /   \     /   \
       -D     E   -F    G-
      /          /        \
     H          I          J

Preeorder Travers : A B D H E C F I G J
In order Travers : H D B E A I F C G J
Postorder Travers : H D E B I F J G C A

*/
int main(){
    Tree<char> tree1('A');
    cout<<"Root node : "<<tree1.at(1)<<endl;
    int index = tree1.addLeft(1,'B');
    cout<<tree1.at(index)<<" child of "<<tree1.at(tree1.parent(index))<<endl;
    index = tree1.addLeft(index,'D');
    cout<<tree1.at(index)<<" child of "<<tree1.at(tree1.parent(index))<<endl;
    index = tree1.addLeft(index,'H');
    cout<<tree1.at(index)<<" child of "<<tree1.at(tree1.parent(index))<<endl;
    index = tree1.addRight(tree1.parent(tree1.parent(index)),'E');
    cout<<tree1.at(index)<<" child of "<<tree1.at(tree1.parent(index))<<endl;
    index = tree1.addRight(tree1.parent(tree1.parent(index)),'C');
    cout<<tree1.at(index)<<" child of "<<tree1.at(tree1.parent(index))<<endl;
    index = tree1.addLeft(index,'F');
    cout<<tree1.at(index)<<" child of "<<tree1.at(tree1.parent(index))<<endl;
    index = tree1.addLeft(index,'I');
    cout<<tree1.at(index)<<" child of "<<tree1.at(tree1.parent(index))<<endl;
    index = tree1.addRight(tree1.parent(tree1.parent(index)),'G');
    cout<<tree1.at(index)<<" child of "<<tree1.at(tree1.parent(index))<<endl;
    index = tree1.addRight(index,'J');
    cout<<tree1.at(index)<<" child of "<<tree1.at(tree1.parent(index))<<endl;
    cout<<"\nPreeorder Travers : ";
    tree1.preeorder(1);
    cout<<"\nIn order Travers : ";
    tree1.inorder(1);
    cout<<"\nPostorder Travers : ";
    tree1.postorder(1);

    return 0;
}
