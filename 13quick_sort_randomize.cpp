#include<iostream>
using namespace std;
int nn;
int partitions(int arr[],int first,int last){
    int pivot = first + (rand()%(last-first));
    int spivot=pivot;
    for(int i=pivot+1;i<=last;i++){
        nn++;
        if(arr[pivot]>arr[i]){
            int temp=arr[pivot];
            arr[pivot]=arr[i];
            arr[i]=arr[pivot+1];
            arr[pivot+1]=temp;
            pivot++;
        }
    }
    for(int i=spivot-1;i>=first;i--){
        nn++;
        if(arr[pivot]<arr[i]){
            int temp=arr[pivot];
            arr[pivot]=arr[i];
            arr[i]=arr[pivot-1];
            arr[pivot-1]=temp;
            pivot--;
        }
    }return pivot;
}
void quick_sort(int arr[],int first,int last){
    if(first<last){
        int pivot=partitions(arr,first,last);
        quick_sort(arr,first,pivot-1);
        quick_sort(arr,pivot+1,last);
    }
}
void print(int arr[],int n){
    for(int i=0;i<=n;i++) cout<<arr[i]<<' ';
}
int main(){
    int arr[]={ 3, 5, 2, 3, 2, 2, 2, 1, 0, 9, 4, 2, 2, 2, 2, 2, 2, 2};
    quick_sort(arr,0,17);
    print(arr,17);
    cout<<"Count : "<<nn<<endl;
}
