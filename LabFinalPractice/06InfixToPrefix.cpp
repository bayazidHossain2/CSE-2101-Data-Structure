#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
int precedence(char opera){
    switch(opera){
    case '*':
    case '/':
        return 3;
    case '+':
    case '-':
        return 2;
    case '(':
        return 1;
    }return 0;
}
string infixToprefix(string infix){
    string prefix;
    stack<char> opstack;
    reverse(infix.begin(),infix.end());
    cout<<"\nNow infix is : "<<infix<<endl;
    for(char token : infix){
        if((token>='A'&&token<='Z')||(token>='0'&&token<='9')){
            prefix+=token;
        }else if(token==')'){
            opstack.push(token);
        }else if(token=='('){
            char topToken=opstack.top();
            opstack.pop();
            while(topToken!=')'){
                prefix+=topToken;
                topToken=opstack.top();
                opstack.pop();
            }
        }else{
            while(!opstack.empty()&&precedence(opstack.top())>=precedence(token)){
                prefix+=opstack.top();
                opstack.pop();
            }opstack.push(token);
        }
    }while(!opstack.empty()){
        prefix+=opstack.top();
        opstack.pop();
    }
    reverse(prefix.begin(),prefix.end());
    return prefix;
}

int main(){
    string str="(A+B)+C-(D-E)*F";
    cout<<str<<" prefix is : "<<infixToprefix(str)<<endl;
    return 0;
}
