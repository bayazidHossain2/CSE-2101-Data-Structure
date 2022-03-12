#include<iostream>
#include<stack>
using namespace std;
int precident(char opera){
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
string infixToPostfix(string infix){
    stack<char> opstack;
    string postfix;
    for(char token : infix){
        if((token>='A'&&token<='Z')||(token>='0'&&token<='9')){
            postfix+=token;
        }else if(token=='('){
            opstack.push(token);
        }else if(token==')'){
            char topToken=opstack.top();
            opstack.pop();
            while(topToken!='('){
                postfix+=topToken;
                topToken=opstack.top();
                opstack.pop();
            }
        }else{
            while(!opstack.empty()&&precident(opstack.top())>=precident(token)){
                postfix+=opstack.top();
                opstack.pop();
            }opstack.push(token);
        }
    }while(!opstack.empty()){
        postfix+=opstack.top();
        opstack.pop();
    }
    return postfix;
}
string postfixToInfix(string postfix){
    stack<string> words;
    for(char token : postfix){
        cout<<token<<endl;
        if(token>='A'&&token<='Z'){
            string s="";
            s+=token;
            words.push(s);
            cout<<"Push : "<<s<<endl;
        }else{
            if(words.size()>=2){
                //cout<<words.size()<<' '<<words.top()<<'|'<<endl;
                string first,second;
                second=words.top();
                words.pop();
                first=words.top();
                words.pop();
                cout<<first<<'|'<<token<<'|'<<second<<endl;
                string op=(first+token+second);
                cout<<"Push again : "<<op<<endl;
                words.push(op);
            }else{
                cout<<"length is less than 2"<<endl;
            }
        }
    }return words.top();
}
int main(){
    cout<<infixToPostfix("A*B+C*D")<<endl;
    string str=infixToPostfix("(A+B)*C-(D-E*I-P)*(F+G)");
    cout<<str<<endl;
    cout<<postfixToInfix(str)<<endl;
}
