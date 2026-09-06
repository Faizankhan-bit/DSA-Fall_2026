#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
};

int main(){
    
    node* head = new node();
    node* first = new node();
    node* second = new node();

    head->data = 10;
    first->data = 20;
    second->data = 30;

    head->next = first;
    first->next = second;
    second->next = NULL;

    //cout<<head->data <<" "<<first->data<<" "<<second->data;

    node* temp = head;

    while(temp != NULL){
        cout<<temp->data << " ";
        temp = temp->next;
    }
}