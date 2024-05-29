#include<iostream>
#include<string>
using namespace std;

void reverseArray(int arr[], int size){
    int i = 0;
    int j = size-1;
    int ele;
    while (i < j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

void printArray(int arr[], int size){
    for (int j = 0; j < size; j++)
    {
        cout << arr[j] << " ";
    } 
    cout << endl;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr)/sizeof(int);
    cout << "Array : " << endl;
    printArray(arr, size);
    reverseArray(arr, size);
    cout << "Reversed Array : " << endl;
    printArray(arr, size);
}