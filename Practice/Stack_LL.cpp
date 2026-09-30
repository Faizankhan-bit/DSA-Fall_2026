#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

        node(int val){
            data = val;
            next = NULL;
        }
};

class stack{
    node* top;

    public:
        stack(){
            top = NULL;
        }

        void push(int val){
            node* newNode = new node(val);

            newNode->next = top;
            top = newNode;
        }

        void pop(){
            if(top == NULL){
                cout << "Stack Underflow" << endl;
            return;
            }

            node* temp = top;
            top = top->next;

            delete temp;
        }

        int peek(){
            if(top == NULL){
            cout << "Stack is empty" << endl;
            return -1;
        }

        return top->data;

    } 

    void display(){
         if(top == NULL){
            cout << "Stack is empty" << endl;
            return ;
        }

         node* temp = top;
         while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
         }
         cout<<endl;
    }

   
    
    
};

int main(){
    stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    s.display();

    cout << "Top: " << s.peek() << endl;

    s.pop();

    s.display();

    cout << "Top: " << s.peek() << endl;

    return 0;
}