#include <iostream>
#include <vector>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = arr[i];
        for (int j = i; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void bubbleSort(int arr[], int n){
    for (int i = n-1; i > 0; i--)
    {
        bool swaped = false;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                swaped = true;
            }
            
        }
        if (swaped==false)
        {
           break;
        }
        
        
    }
    
}

void insertionSort(int arr[], int n){
    for(int i=0; i<n; i++){
        int j=i;
        while (j>0 && arr[j-1]>arr[j])
        {
            swap(arr[j], arr[j-1]);
            j--;
        }
        
    }
}

int main()
{
    int arr[] = {14, 9, 15, 12, 6, 8, 13};
    cout << "Without Sorting: "<< endl;
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    // selectionSort(arr, 6);
    // bubbleSort(arr, 6);
    insertionSort(arr, 7);
    cout << "With Sorting: "<< endl;
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    
}