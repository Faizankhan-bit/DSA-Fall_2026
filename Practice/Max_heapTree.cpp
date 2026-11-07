#include<iostream>
#include<algorithm>
using namespace std;

class MaxHeap{
    int arr[100];
    int size;

    public:
        MaxHeap(){
            size = 0;
        }

        void insert(int val){
            arr[size] = val;

            int index = size;
            size++;


            while(index > 0){
                int parent = (index - 1) / 2;

                if(arr[parent] < arr[index]){
                    swap(arr[parent], arr[index]);
                    index = parent;
                }
                else{
                    break;
                }
            }
        }

        void deleteRoot(){
            if(size == 0){
                cout<<"Tree is empty"<<endl;
                return;
        }

            arr[0] = arr[size - 1];
            size--;

            int index = 0;

            while(true){

                int right = 2 * index + 2;
                int left = 2 * index + 1;

                int largest = index;

                if(left < size && arr[left] > arr[largest]){
                    largest = left;
                }

                if(right < size && arr[right] > arr[largest]){
                    largest = right;
                }

                if(largest != index){
                    swap(arr[index], arr[largest]);
                    index = largest;
                }
                else{
                    break;
                }
            }
        }

        void display(){
            for(int i = 0; i<size; i++){
                cout<<arr[i]<<" ";
            }
        }
};

int main(){
    MaxHeap m;

    m.insert(50);
    m.insert(30);
    m.insert(40);
    m.insert(10);
    m.insert(20);
    m.insert(60);

    m.deleteRoot();

    m.display();
}