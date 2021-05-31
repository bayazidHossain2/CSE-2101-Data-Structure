#include<iostream>
using namespace std;
///Total complexity id O(2n)
void marge(int arr[],int left,int mid,int right){
    int len1=mid-left+1;
    int len2=right-mid;
    int arr1[len1],arr2[len2];
    ///devide our main arr to temporary two arr1 and arr2
    ///arr1 get the value of (left to mid)
    for(int i=0;i<len1;i++){
        arr1[i]=arr[left+i];
    }
    ///arr2 get the value of (mid+1 to right)
    for(int i=0;i<len2;i++){
        arr2[i]=arr[mid+i+1];
    }
    ///concatinet tempory arr1 and arr2 to the main arr
    int i{0},j{0};
    while(i<len1&&j<len2){
        if(arr1[i]<arr2[j]){
            arr[left++]=arr1[i++];
        }else{
            arr[left++]=arr2[j++];
        }
    }
    ///another element of arr1
    while(i<len1){
        arr[left++]=arr1[i++];
    }
    ///another element of arr2
    while(j<len2){
        arr[left++]=arr2[j++];
    }
}
///Total complexity O(log(n)*2n) -> O(nlog(n))
void marge_sort(int arr[],int left,int right){
    if(left<right){
        int mid = left + (right-left)/2;
        ///divide the problem into two sub problem
        marge_sort(arr,left,mid);
        marge_sort(arr,mid+1,right);
        ///marge them together
        ///it run log(n) time
        marge(arr,left,mid,right);
    }
}
int main(){
    while(true){
        cout<<"Enter the number of element : ";
        int n;
        cin>>n;
        if(n<=0) break;
        int arr[n];
        cout<<"Enter the array : ";
        for(int i=0;i<n;i++) cin>>arr[i];
        marge_sort(arr,0,n-1);
        cout<<"After marge sort : ";
        for(int i=0;i<n;i++) cout<<arr[i]<<' ';
        cout<<endl;
    }return 0;
}
