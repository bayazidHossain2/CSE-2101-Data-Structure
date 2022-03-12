#include<iostream>
using namespace std;

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }cout<<endl;
}
int main(){
    int arr[]={2,0,0,0,0,2};
    int size_=6;
    bool isSwaped=false;
    int last=size_;
    do{
        isSwaped=false;
        for(int i=0;i<last-1;i++){
            if(arr[i]>arr[i+1]){
                swap(arr[i],arr[i+1]);
                isSwaped = true;
            }
        }last--;
    }while(isSwaped);
    cout<<"After sort : ";
    print(arr,size_);
}
