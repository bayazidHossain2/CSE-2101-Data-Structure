#include<iostream>
using namespace std;
template<typename Type>
class stuck{
    Type *data;
    int size;
    int index;
public:
    stuck(){
        data = new Type;
        if(data == NULL){
            cout<<"Space not found..."<<endl;
        }
        size = 0;
        index = 0;
    }
    void push(Type item){
        data[index] = item;
        index++;
        size++;
    }
    Type pop(){
        if(index == 0){
            cout<<"Stuck is empty..."<<endl;
            return NULL;
        }index--;
        size--;
        return data[index];
    }
};
int main(){
    stuck<char> st;
    st.push('(');
    st.push(')');
    st.push('}');
    st.push('{');
    char data = st.pop();
    while(data != NULL){
        cout<<data<<endl;
        data = st.pop();
    }
    return 0;
}
