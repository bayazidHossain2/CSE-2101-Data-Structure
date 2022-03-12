#include<iostream>
using namespace std;

int parti(int arr[],int st,int en){
    int pivot=(en+st)/2;
    for(int i=pivot+1;i<=en;i++){
        if(arr[pivot]>=arr[i]){
            int temp=arr[pivot];
            arr[pivot]=arr[i];
            arr[i]=arr[pivot+1];
            arr[pivot+1]=temp;
            pivot++;
        }
    }
    for(int i=pivot-1;i>=0;i--){
        if(arr[pivot]<arr[i]){
            int temp=arr[pivot];
            arr[pivot]=arr[i];
            arr[i]=arr[pivot-1];
            arr[pivot-1]=temp;
            pivot--;
        }
    }return pivot;
}

void quickSort(int arr[],int st,int en){
    if(st>en){
        return;
    }
    int piv=parti(arr,st,en);
    quickSort(arr,st,piv-1);
    quickSort(arr,piv+1,en);
}
void print(int arr[],int s){
    for(int i=0;i<s;i++){
        cout<<arr[i]<<' ';
    }cout<<endl;
}
int main(){
    int arr[]={5,3,8,2,4,9,1,2,3};
    quickSort(arr,0,8);
    print(arr,9);
    return 0;
}
