#include<iostream>
using namespace std;

void takeInput(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }  
}

void printArray(int arr[], int size){
    for (int j = 0; j < size; j++)
    {
        cout << arr[j] << " ";
    } 
    cout << endl;
}

int printSum(int arr[], int size){
    int sum = 0;
    for (int k = 0; k < size; k++)
    {
        sum += arr[k];
    }
    return sum;
}

int main(){
    int arr[5];
    int size = 5;
    cout << "take input : " << endl;
    takeInput(arr,size);
    cout << "printing array : " << endl;
    printArray(arr, size);
    int sumofelemnts = printSum(arr, size);
    cout << "Sum of elements of array = " << sumofelemnts << endl;
    return 0;
}