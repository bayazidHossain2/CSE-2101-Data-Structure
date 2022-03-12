#include<iostream>
#include<stack>
using namespace std;
string func(string braketed){
    stack<char> opstack;
    bool makerev=0;
    for(int i=1;i<braketed.size();i++){
        //cout<<braketed[i]<<' '<<makerev<<endl;
        if(braketed[i]=='('){
            if(braketed[i-1]=='-'){
                //cout<<"braket before is a minous"<<endl;
                makerev=1;
                opstack.push('-');
            }else{
                //cout<<"Braket before is a plus"<<endl;
                makerev=0;
                opstack.push('+');
            }
        }else if(makerev&&braketed[i]=='-'){
            braketed[i]='+';
        }else if(makerev&&braketed[i]=='+'){
            braketed[i]='-';
        }
        else if(braketed[i]==')'){
            if(opstack.size()>=2){
                opstack.pop();
                if(opstack.top()=='-'){
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

/*

a-(b-c-(d+e))-f
Result is : a-b+c+d+e-f

a-(b-c-(d+e)+x-y+z)-f
Result is : a-b+c+d+e-x+y-z-f

*/
