#include<iostream>
#include<stack>
using namespace std;
string func(string braketed){
    string str;
    stack<char> braket;
    bool makerev=0;
    for(int i=1;i<braketed.size();i++){
        //cout<<braketed[i]<<' '<<makerev<<endl;
        if(braketed[i]=='('){
            if(braketed[i-1]=='-'){
                //cout<<"braket before is a minous"<<endl;
                makerev=1;
                braket.push('-');
            }else{
                //cout<<"Braket before is a plus"<<endl;
                makerev=0;
                braket.push('+');
            }
        }else if(makerev&&braketed[i]=='-'){
            braketed[i]='+';
        }else if(makerev&&braketed[i]=='+'){
            braketed[i]='-';
        }
        else if(braketed[i]==')'){
            if(braket.size()>=2){
                braket.pop();
                if(braket.top()=='-'){
                    makerev=1;
                }else{
                    makerev=0;
                }
            }else{
                makerev=0;
                //cout<<"Invalid."<<endl;
            }
        }
        //cout<<"A : "<<braketed[i]<<' '<<makerev<<endl;
    }
    //cout<<braketed<<endl;
    string bless="";
    for(char ch : braketed){
        if(ch=='('||ch==')'){}
        else {
            bless=bless+ch;
        }
    }
    return bless;
}

int main(){
    string st="a-(b-c-(d+e))-f";
    cout<<st<<endl;
    st=func(st);
    cout<<"Result is : "<<st<<endl;
    cout<<endl;

    st="a-(b-c-(d+e)+x-y+z)-f";
    cout<<st<<endl;
    st=func(st);
    cout<<"Result is : "<<st<<endl;
}
