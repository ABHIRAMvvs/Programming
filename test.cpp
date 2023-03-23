#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node  *next;
};
void push(node **head_ref, int new_data){
    node *new_node = new node();
    new_node->data =new_data;
    new_node->next = (*head_ref);
    (*head_ref)  = new_node;
}
void insertafter(node* prev_node, int new_data){
    if(prev_node == NULL){
        cout << "The given previous node cannot be NULL";
        return;
    }
    node *new_node = new node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}
void append(node **head_ref, int new_data){
    node* new_node = new node();
    node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    while(last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
    return;
}
void printlist(node *node){
    while(node != NULL){
        cout << " "<<node->data;
        node=node->next;
    }
}
int main(){
    node *head= NULL;
    int n;
    cout << "Enter number of nodes";
    cin >> n;
    for(int i=0;i<n; i++){
        int x;
        cin >> x;
        append(&head, x);
    }
    cout << head->next;
    insertafter(head->next, 11);

    push(&head, 16);
    cout << "Created Linked list is: ";
    printlist(head);
    return 0;
}
