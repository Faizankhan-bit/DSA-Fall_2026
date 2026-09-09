#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

    node(int data){
        this->data = data;
        next = NULL;
    }
};

class list{
    node* head;
    node* tail;

    public:
        list(){
            head = tail = NULL;
        }

    void push_front(int data){
        node* newNode = new node(data);

        if(head == NULL){
            head = tail = newNode;
            return;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int data){
        node* newNode = new node(data);

         if(head == NULL){
            head =  tail = newNode;
            return;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }

    }

    void pop_front(){
        if(head == NULL){
            return;
        }else{
            node* temp = head;
            head = head->next;
            temp->next = NULL;

            delete temp;
        }
    }

    void pop_back(){
        if(head == NULL){
            return ;

        }else{
            node* temp = head;

            while(temp->next != tail){
                temp = temp->next;
            }

            temp->next = NULL;
            delete tail;
            tail = temp;

        }
    }

    void insert_at_middle(int data, int pos){
        if(pos < 0){
            cout<<"Invalid pos\n";
            return;
        }

        if(pos == 0){
            push_front(data);
        }

        node* newNode = new node(data);

        node* temp = head;
        for(int i = 0; i < pos - 1; i++){
            if(temp == NULL){
                cout<<"Invalid pos\n";
                return;
            }
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;

    }

    int search(int key){
        node* temp = head;

        int idx = 0;

        while(temp != NULL){
            if(temp->data == key){
                return idx;
            }
            temp = temp->next;
            idx++;
        }

        return -1;
    }

    void display(){
        node* temp = head;

        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main(){
    list ll;

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.insert_at_middle(4,2);

    cout<<ll.search(3)<<endl;

    ll.display();

}