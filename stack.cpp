#include <iostream>
using namespace std;
class node{
    int data;
    node *link;
    node(int n){
        this->data = n;
        this->link = NULL;
    }
};
class stack{
    node* top;
    public:
    stack(){
        top = NULL;
    }
    void push(int data){
        node  *temp= new node(data);
        if(!temp){
            cout << "Stack is overflowed";
            exit(1);
        }
        temp->data = data;
        temp->link = top;
        top = temp;
    }
    bool isEmpty(){
        return top ==NULL;
    }
    int peek(){
        if(!isEmtpy()){
            return top->data;
        }
        else{
            exit(1);
        }
    }
    void pop(){
        node *temp;
        if(top ==  NULL){
            cout << "stack underflow"<<endl;
            exit(1);
        }
        else{
            temp=top;
            top =  top->link;
            free(temp);
        }
    }
    void display(){
        node *Temp;
        if(top == NULL){
            cout << "Stack underflow"<<endl;
            exit(1);
        }
        else{
            temp = top;
            while(temp!=NULL){
                cout << temp->data;
                temp = temp->link;
                if(temp!=NULL){
                    cout << " -> ";
                }
            }
        }
    }
};
int main(){
    stack s;
    s.push(2);
    s.push(4);
    s.push(6);
    s.push(1);
    s.push(1234);
    s.display();
    cout << "\ntop element is  "<< s.peek()<<endl;
    s.pop();
    s.pop();
    s.display();
}