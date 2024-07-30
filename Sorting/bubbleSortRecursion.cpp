#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    if (n == 1)
    {
        return;
    }

    bool didSwap = false;
    for (int j = 0; j < n - 1; j++)
    {
        if (arr[j] > arr[j + 1])
        {
            swap(arr[j], arr[j + 1]);
            didSwap = true;
        }
    }
    bubbleSort(arr, n - 1);
    if (didSwap == false)
    {
        return;
    }
}

int main()
{
    int arr[] = {1, 9, 15, 12, 6, 8, 13};
    cout << "Without Sorting: " << endl;
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    // selectionSort(arr, 6);
    bubbleSort(arr, 6);

    cout << "With Sorting: " << endl;
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}