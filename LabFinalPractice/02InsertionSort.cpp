#include<iostream>
#include<sstream>
#include<string>
using namespace std;
void print(int arr[],int size_){
    for(int i=0;i<size_;i++){
        cout<<arr[i]<<' ';
    }cout<<endl;
}
int main(){
    int n;
    //cin>>n;
    string str;
    getline(cin,str);
    stringstream ss(str);
    int num;
    int arr[1000];
    n=0;
    while(ss>>num){
        cout<<num<<endl;
        arr[n]=num;
        n++;
    }
    cout<<" Array is : ";
    print(arr,n);

    /*for(int i=0;i<n;i++){
        cin>>arr[i];
    }*/
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
            int t=arr[i],j;
            for(j=i-1;arr[j]>t&&j>=0;j--){
                arr[j+1]=arr[j];
            }arr[j+1]=t;
        }
    }print(arr,n);
}
