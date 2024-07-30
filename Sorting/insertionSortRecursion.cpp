#include <iostream>
using namespace std;

void insertionSort(int arr[], int n, int i)
{
    if (i==n)
    {
        return;
    }
    
    int j = i;
    while (j > 0 && arr[j - 1] > arr[j])
    {
        swap(arr[j - 1], arr[j]);
        j--;
    }
    insertionSort(arr, n, i+1);
}

int main()
{
    int arr[] = {4, 9, 15, 12, 6, 8, 13};
    cout << "Without Sorting: " << endl;
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    // selectionSort(arr, 6);
    // bubbleSort(arr, 6);
    insertionSort(arr, 7, 0);
    cout << "With Sorting: " << endl;
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}