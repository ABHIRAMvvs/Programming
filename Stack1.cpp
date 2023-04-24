#include <bits/stdc++.h>
using namespace std;
int main(){
    stack<int> stack;
    stack.push(10);
    stack.push(87);
    stack.push(76);
    cout << stack.top()<<endl;
    cout << stack.size()<<endl;
    if(stack.empty()){
        cout << "Stack is empty" << endl;
    }
    else{
        cout << "Stack is not empty"<< endl;
    }
    while(!stack.empty()){
        cout << stack.top()<<" ";
        stack.pop();
    }

}