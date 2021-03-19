#include<iostream>
using namespace std;
class Heap{
    int heapSize{0};
    int last_heap_index{0};
    int *dataList;
    bool is_left_full{false};
    bool set_root = true;
    void swap(int& a,int& b){
        //cout<<"swaped : "<<a<<' '<<b<<endl;
        int temp = a;
        a = b;
        b = temp;
    }
    int parent_index(int index){
        if(1&index){
            return index/2;
        }else return (index/2)-1;
    }
public:
    Heap(int heapSize){
        this->heapSize = heapSize;
        dataList = (int*) new int[heapSize+2];
        if(dataList == nullptr){
            cout<<"memory size over follow."<<endl;
            return;
        }
    }
    Heap(int arr[],int arrSize){
        heapSize = arrSize;
        dataList = (int*) new int[heapSize];
        if(dataList == nullptr){
            cout<<"memory size over follow."<<endl;
            return;
        }
        for(int i=0;i<arrSize;i++){
            push(arr[i]);
            //cout<<"\nAfter Pushing : "<<arr[i]<<"\n";
            //print();
        }
    }
    void push(int data){
        if(set_root){
            dataList[0] = data;
            set_root = false;
        }
        else if(is_left_full){
            dataList[(2*last_heap_index)+2] = data;
            is_left_full = false;
            last_heap_index++;///Denoting parent heap node index
        }else{
            dataList[(2*last_heap_index)+1] = data;
            is_left_full = true;
        }//cout<<"Last heap index : "<<last_heap_index<<' '<<is_left_full<<endl;
    }
    void max_heapify(int index){
        //cout<<"Max h call by : "<<index<<endl;
        if(index<0||index>last_heap_index){
            //cout<<"returning from index : "<<index<<endl;
            return;
        }
        if(index == last_heap_index){
            if(is_left_full&&dataList[index]<dataList[(2*index)+1]){
                swap(dataList[index],dataList[(2*index)+1]);
                max_heapify(parent_index(index));
                return;
            }else return;
        }
        if(dataList[(2*index)+1] > dataList[(2*index)+2]){
            if(dataList[index] < dataList[(2*index)+1]){
                swap(dataList[index],dataList[(2*index)+1]);
                max_heapify(parent_index(index));
            }
        }else{
            if(dataList[index] < dataList[(2*index)+2]){
                swap(dataList[index],dataList[(2*index)+2]);
                max_heapify(parent_index(index));
            }
        }
        max_heapify((2*index)+1);
        max_heapify((2*index)+2);
    }
    void print(){
        int last_parent;
        if(is_left_full){
            last_parent = last_heap_index;
        }else{
            last_parent = last_heap_index-1;
        }
        for(int i=0;i<=last_parent;i++){
            cout<<"Parent : "<<dataList[i];
            cout<<" -> Left child : "<<dataList[(2*i)+1];
            if(i==last_parent && is_left_full){
                cout<<endl;
                return;
            }cout<<" Right child : "<<dataList[(2*i)+2]<<endl;
        }
    }
};

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10,11,12};
    Heap ob1(arr,12);
    Heap temp = ob1;
    //temp.maxHeapify(0);
    //cout<<"After max Heapify : \n"<<endl;
    //temp.print();
    //temp = ob1;
    temp.max_heapify(0);
    cout<<"After max_Heapify : \n"<<endl;
    temp.print();
    return 0;
}
