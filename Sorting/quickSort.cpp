#include<iostream>
using namespace std;

int findPivotIndex(int arr[], int low, int high){
    int pivotIndex = low;
    int i = low;
    int j = high;
    while (i<j)
    {
        while (arr[i]<= arr[pivotIndex] && i<=high-1)
        {
           i++;
        }
        while (arr[j] > arr[pivotIndex] && j>=low-1)
        {
           j--;
        }
        if(i<j){
            swap(arr[i], arr[j]);
        }
        
    }
    swap(arr[pivotIndex], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high){
    if (low>=high)
    {
        return;
    }
    int pivotIndex = findPivotIndex(arr, low, high);
    quickSort(arr, low, pivotIndex-1);
    quickSort(arr, pivotIndex+1, high);
}

int main(){
    int arr[] = {13, 46, 24, 52, 20, 9};
    for(int i: arr){
        cout << i << " ";
    }
    cout << endl;
    quickSort(arr, 0, 5);
    for(int i: arr){
        cout << i << " ";
    }
    cout << endl;
}