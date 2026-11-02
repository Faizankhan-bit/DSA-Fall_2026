#include<iostream>
using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int n){
    int stack[100];
    int top = -1;

    stack[++top] = 0;
    stack[++top] = n - 1;

    while(top >= 0){
        int high = stack[top--];
        int low = stack[top--];

        int p = partition(arr, low, high);

        if(p - 1 > low){
            stack[++top] = low;
            stack[++top] = p - 1;
        }

        if(p + 1 < high){
        stack[++top] = p + 1;
        stack[++top] = high;
    }

    }

}

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}


int main(){
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);


    cout<<"Unsorted Array"<<endl;
    printArray(arr, n);

    quickSort(arr, n);


    cout<<"Sorted Array"<<endl;
    printArray(arr, n);
}
