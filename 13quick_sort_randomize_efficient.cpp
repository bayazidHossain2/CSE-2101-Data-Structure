#include<iostream>
using namespace std;
int nn;
pair<int,int> partitions(int arr[],int first,int last){
    int pivot1 = first + (rand()%(last-first));
    int pivot2=pivot1,spivot=pivot1;
    for(int i=pivot1+1;i<=last;i++){
        nn++;
        if(arr[pivot1]==arr[i]){
            swap(arr[pivot1+1],arr[i]);
            pivot1++;
        }
        else if(arr[pivot1]>arr[i]){
            int temp=arr[pivot2];
            arr[pivot2]=arr[i];
            arr[i]=arr[pivot1+1];
            arr[pivot1+1]=temp;
            pivot1++;
            pivot2++;
        }
    }
    for(int i=spivot-1;i>=first;i--){
        nn++;
        if(arr[pivot2]==arr[i]){
            swap(arr[pivot2-1],arr[i]);
            pivot2--;
        }
        if(arr[pivot2]<arr[i]){
            int temp=arr[pivot1];
            arr[pivot1]=arr[i];
            arr[i]=arr[pivot2-1];
            arr[pivot2-1]=temp;
            pivot1--;
            pivot2--;
        }
    }return make_pair(pivot2,pivot1);
}
void quick_sort(int arr[],int first,int last){
    if(first<last){
        pair<int,int> pivot=partitions(arr,first,last);
        quick_sort(arr,first,pivot.first-1);
        quick_sort(arr,pivot.second+1,last);
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

