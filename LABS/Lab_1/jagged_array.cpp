#include<iostream>
using namespace std;

int main(){
    int rows;
    int i , j;

    cout<<"Enter number of rows : "<<endl;
    cin>>rows;

    int* arr[rows];
    int size[rows];

    for(i = 0; i < rows; i++){
        cout<<"Enter size of row" <<i + 1 << " : "<<endl;
        cin>>size[i];

         arr[i] = new int[size[i]];
    }

    for(i = 0; i < rows; i++){
        cout<<"Enter elements of rows"<< i+1<<" : "<<endl;

        for(j = 0; j < size[i]; j++){
            cin>>arr[i][j];
        }
    }

    cout<<"Jagged array"<<endl;

    for(i = 0; i < rows; i++){
        for(j = 0; j < size[i]; j++){
            cout<<arr[i][j]<<" ";
        }

        cout<<endl;
    }

    for(i = 0 ; i < rows; i++){
        delete arr[i];
    }

    return 0; 
}