#include<iostream>
using namespace std;
//Check whether the given array is sorted or not.

bool issorted(int arr[], int size, int index){
    if (index >= size-1)
    {
       return true;
    }
    if (arr[index] > arr[index+1])
    {
        return false;
    }
    issorted(arr, size, index+1);
    
}

bool checkSorted(int arr[], int size, int index){
    if (index >= size)
    {
        return true;
    }
    if (arr[index] > arr[index-1])
    {
        bool ans = checkSorted(arr, size, index+1);
        return ans;
    }
    else{
        return false;
    }
    
    
}

int main(){
    int arr[] = {10, 20, 30, 40, 50};
    cout << issorted(arr, 5, 0)<< endl;
    cout << checkSorted(arr, 5, 1) << endl;
}