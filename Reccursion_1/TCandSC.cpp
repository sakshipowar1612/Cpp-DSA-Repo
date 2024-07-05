#include<iostream>
using namespace std;

void printArray(int arr[],int n){
    if (n==0)
    {
        return;
    }
    cout << *arr <<" ";
    printArray(arr+1, n-1);
}

//Sapce complexity = depth of reccursion tree.

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printArray(arr, 10);
}