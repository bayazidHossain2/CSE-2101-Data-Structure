#include<iostream>
using namespace std;
int binarySearch(int arr[],int left,int right,int value){
    int mid=(left+right)/2;
    if(arr[mid]==value){
        return mid;
    }else if(left>right){

        return -1;
    }else if(value>arr[mid]){
        return binarySearch(arr,mid+1,right,value);
    }else{
        return binarySearch(arr,left,mid-1,value);
    }
}
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }cout<<endl;
}
int main(){
    int arr[]={1,3,4,5,6,6,6,8};
    int size_=8;
    cout<<"Array is : ";
    print(arr,size_);
    int searchValue=4;
    while(cin>>searchValue&&searchValue!=-1){
        int ind = binarySearch(arr,0,size_,searchValue);
        if(ind==-1){
            cout<<searchValue<<" not found."<<endl;
        }else{
            cout<<searchValue<<" is found at : "<<ind<<endl;
        }
    }return 0;
}
