#include<iostream>
using namespace std;

class queue{
    int* arr;
    int capacity;
    int front;
    int rear;

    public:
        queue(int size){
            capacity = size;
            arr = new int[capacity];
            front = -1;
            rear = -1;
        }

        void enqueue(int val){
            if(rear == capacity - 1){
                cout<<"Queue overflow"<<endl;
                return;
            }

            if(front == -1){
                front = 0;
            }

            rear++;
            arr[rear] = val;
        }

        void dequeue(){
            if(front == -1 || front > rear){
                cout<<"Queue underflow"<<endl;
                return;
            }

            front++;
        }

        int peek(){
            if(front == -1 || front > rear){
                cout<<"Queue empty"<<endl;
                return -1;
            }

            return arr[front];
        }

        void display(){
            if(front == -1 || front > rear){
                cout<<"Queue empty"<<endl;
                return ;
            }

            for(int i = front; i <= rear; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

       ~queue(){
        delete[] arr;
       }
};

int main(){
    int size;

    cout<<"Enter the size of queue : "<<endl;
    cin>>size;

    queue q(size);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    cout << "Front: " << q.peek() << endl;

    q.dequeue();

    q.display();

    cout << "Front: " << q.peek() << endl;

    return 0;
}