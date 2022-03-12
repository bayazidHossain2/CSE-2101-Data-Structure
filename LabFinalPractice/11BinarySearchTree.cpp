#include<iostream>
#define maxSize 1000
using namespace std;
class bst{
    int arr[maxSize+1];
    int numberofelement;
public:
    bst(){
        for(int i=0;i<maxSize;i++){
            arr[i]=-1;
        }
        numberofelement=0;
    }
    void push(int value,int ind=0){
        //cout<<"push "<<value<<endl;
        if(value<arr[ind]){
            //cout<<"    goto left"<<endl;
            push(value,(2*ind+1));
        }else if(arr[ind]!=-1){
            //cout<<"    goto right"<<endl;
            push(value,(2*ind+2));
        }else{
            //cout<<"    value insert at : "<<ind<<endl;
            arr[ind]=value;
            numberofelement++;
        }
    }
    void print(){
        int nele{0};
        for(int i=0;i<maxSize;i++){
            if(arr[i]!=-1){
                cout<<'('<<arr[i]<<", "<<i<<") ";
                nele++;
                if(nele==numberofelement){
                    break;
                }
            }
        }cout<<endl;
    }
    int max_(int ind=0){
        if(arr[2*ind+2]==-1){
            return arr[ind];
        }else{
            return max_(2*ind+2);
        }
    }
    int min_(int ind=0){
        if(arr[2*ind+1]==-1){
            return arr[ind];
        }else{
            return min_(2*ind+1);
        }
    }
    int min_valueind(int ind=0){
        if(arr[2*ind+1]==-1){
            return ind;
        }else{
            return min_valueind(2*ind+1);
        }
    }
    void deletebyind(int ind){
        if(arr[2*ind+1]==-1&&arr[2*ind+2]==-1){
            cout<<"0 child"<<endl;
            arr[ind]=-1;
        }else if(arr[2*ind+1]==-1){
            cout<<"1 right child"<<endl;
            arr[ind]=arr[2*ind+2];
            deletebyind(2*ind+2);
        }else if(arr[2*ind+2]==-1){
            cout<<"1 left child"<<endl;
            arr[ind]=arr[2*ind+1];
            deletebyind(2*ind+1);
        }else{
            cout<<"2 child"<<endl;
            cout<<"min call by "<<2*ind+2<<endl;
            int mind=min_valueind(2*ind+2);
            cout<<ind<<" Min ind from right"<<mind<<endl;
            arr[ind]=arr[mind];
            deletebyind(mind);
        }
    }
    void delete_(int value){
        int nele=0;
        for(int i=0;i<maxSize&&nele<numberofelement;i++){
            if(arr[i]!=-1){
                nele++;
                if(arr[i]==value){
                    cout<<value<<" found at : "<<i<<endl;
                    deletebyind(i);
                    numberofelement--;
                    return;
                }
            }
        }
    }
    bool count_(int value,int ind=0){
        if(arr[ind]==value){
            return true;
        }else if(arr[ind]==-1){
            return false;
        }else if(value>arr[ind]){
            return count_(value,2*ind+2);
        }else{
            return count_(value,2*ind+1);
        }
    }
    void inorder(int ind=0){
        if(arr[ind]==-1){
            return;
        }
        inorder(2*ind+1);
        cout<<arr[ind]<<' ';
        inorder(2*ind+2);
    }
    void preorder(int ind=0){
        if(arr[ind]==-1){
            return;
        }
        cout<<arr[ind]<<' ';
        preorder(2*ind+1);
        preorder(2*ind+2);
    }
    void postorder(int ind=0){
        if(arr[ind]==-1){
            return;
        }
        postorder(2*ind+1);
        postorder(2*ind+2);
        cout<<arr[ind]<<' ';
    }
};

int main(){
    bst bt;
    bt.push(7);
    bt.push(2);
    bt.push(5);
    bt.push(9);
    bt.push(3);
    cout<<"Now min is : "<<bt.min_()<<endl;
    bt.push(0);
    bt.push(1);
    bt.push(8);
    bt.push(4);
    cout<<"Now max is : "<<bt.max_()<<endl;
    bt.push(17);
    bt.push(11);
    bt.push(13);
    cout<<"Now max is : "<<bt.max_()<<endl;
    cout<<"Now min is : "<<bt.min_()<<endl;
    bt.print();
    cout<<"After deleting 2"<<endl;
    bt.delete_(2);
    bt.print();
    cout<<"is there 13 : "<<bt.count_(13)<<endl;
    cout<<"is there 12 : "<<bt.count_(12)<<endl;
    cout<<"preorder of your tree : ";
    bt.preorder();
    cout<<"\ninorder of your tree : ";
    bt.inorder();
    cout<<"\npostorder of your tree : ";
    bt.postorder();
    cout<<endl;
}
