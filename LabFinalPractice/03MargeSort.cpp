#include<iostream>
using namespace std;

void marge(int arr[],int left,int mid,int right){
    int l1=mid-left+1;
    int l2=right-mid;
    int arr1[l1],arr2[l2];
    for(int i=left;i<=mid;i++){
        arr1[i-left]=arr[i];
    }
    for(int i=mid+1;i<=right;i++){
        arr2[i-mid-1]=arr[i];
    }int i=0,j=0;
    while(i<l1&&j<l2){
        if(arr1[i]<arr2[j]){
            arr[left]=arr1[i];
            i++;
        }else{
            arr[left]=arr2[j];
            j++;
        }left++;
    }while(i<l1){
        arr[left]=arr1[i];
        left++;
        i++;
    }
    while(j<l2){
        arr[left]=arr2[j];
        left++;
        j++;
    }
}
void marge_sort(int arr[],int left,int right){
    if(left==right){
        return;
    }
    int mid = (left+right)/2;
    marge_sort(arr,left,mid);
    marge_sort(arr,mid+1,right);
    marge(arr,left,mid,right);
}
void print(int arr[],int size_){
    for(int i=0;i<size_;i++){
        cout<<arr[i]<<' ';
    }cout<<endl;
}
int main(){
    int arr[]={6,3,3,2,4,6,5,4,1};
    cout<<"Before sort : ";
    print(arr,9);
    marge_sort(arr,0,8);
    cout<<"After sort : ";
    print(arr,9);
}
