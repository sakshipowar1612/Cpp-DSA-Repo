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

int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    cout << "Without Sorting: "<< endl;
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    selectionSort(arr, 6);
    cout << "With Sorting: "<< endl;
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    
}