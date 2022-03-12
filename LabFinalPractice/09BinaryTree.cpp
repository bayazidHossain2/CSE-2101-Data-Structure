#include<iostream>
using namespace std;
template<typename type>
class Tree{
    static const int totalNode=1000;
    type arr[totalNode+1];
public:
    Tree(int root){
        arr[1]=root;
        for(int i=2;i<totalNode;i++){
            arr[i]=-1;
        }
    }
    int addLeft(int parInd,type value){
        if(2*parInd<totalNode){
            arr[2*parInd]=value;
        }return 2*parInd;
    }
    int addRight(int parInd,type value){
        if(2*parInd+1<totalNode){
            arr[2*parInd+1]=value;
        }return 2*parInd+1;
    }
    int getLeft(int parInd){
        return 2*parInd;
    }
    int getRight(int parInd){
        return 2*parInd+1;
    }
    int getParent(int chiInd){
        return chiInd/2;
    }
    type& at(int ind){
        return arr[ind];
    }
    void inorder(int ind){
        if(arr[2*ind]!=-1){
            inorder(2*ind);
        }cout<<arr[ind]<<' ';
        if(arr[2*ind+1]!=-1){
            inorder(2*ind+1);
        }
    }
    void preeorder(int ind){
        cout<<arr[ind]<<' ';
        if(arr[2*ind]!=-1){
            preeorder(2*ind);
        }
        if(arr[2*ind+1]!=-1){
            preeorder(2*ind+1);
        }
    }
    void postorder(int ind){
        if(arr[2*ind]!=-1){
            postorder(2*ind);
        }
        if(arr[2*ind+1]!=-1){
            postorder(2*ind+1);
        }
        cout<<arr[ind]<<' ';
    }
};

int main(){
    Tree<char> tree('A');
    int ind;
    ind=tree.addLeft(1,'B');
    ind=tree.addLeft(ind,'D');
    tree.addLeft(ind,'H');
    ind=tree.getParent(ind);
    tree.addRight(ind,'E');
    ind=tree.getParent(ind);
    ind=tree.addRight(ind,'C');
    ind=tree.addLeft(ind,'F');
    tree.addLeft(ind,'I');
    ind=tree.getParent(ind);
    ind=tree.addRight(ind,'G');
    tree.addRight(ind,'J');
    cout<<"Inorder : ";
    tree.inorder(1);
    cout<<endl;
    cout<<"Preeorder : ";
    tree.preeorder(1);
    cout<<endl;
    cout<<"Postorder : ";
    tree.postorder(1);
    cout<<endl;
}
