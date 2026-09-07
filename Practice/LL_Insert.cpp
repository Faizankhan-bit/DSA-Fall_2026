#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

    node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

class Linked_list{
    node* head;

    public:
        Linked_list(){
            head = nullptr;
        }

    void insert(int data){
        node* newNode = new node(data);

        if(head == nullptr){
            head = newNode;
        }
        else{
            node* temp = head;

            while(temp->next != nullptr){
                temp = temp->next; 
            }
            
            temp->next = newNode;
        }
    }

    void display(){
        node* temp = head;

        while(temp != nullptr){
            cout<< temp->data << " ";
            temp = temp->next;
        }
    }
};

int main(){
    Linked_list ll;

    ll.insert(10);
    ll.insert(20);
    ll.insert(30);
    ll.insert(40);

    ll.display();
}