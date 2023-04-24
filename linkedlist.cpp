#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node  *next;
};
void insert(node **head, int data){
    node *temp =  new node();
    temp->data = data;
    temp->next = *head;
    *head = temp;
}
void append(node **head, int data){
    node *new_node = new node();
    new_node->data = data;
    new_node->next = NULL;
    node  *last = *head;
    if(*head == NULL){
        *head = new_node;
        return;
    }
    while(last->next != NULL){
        last  = last->next;
    }
    last->next = new_node;
    return;
}
void insertafter(node *prev_node, int data){
    node *new_node = new node();
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->next = prev_node->next;
}
void print(node *head){
    while(head != NULL){
        cout << head->data<<" ";
        head = head->next;
    }
}
int main(){
    node *head = NULL;
    append(&head, 1);
    append(&head, 12);
    insert(&head, 2);
    insert(&head, 0);
    insertafter(head->next, 18);
    print(head);
}
