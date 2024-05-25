// shift arrays elemnt by 1.
#include <iostream>
using namespace std;

void shiftByOne(int arr[], int size)
{
    int last = arr[size - 1];
    for (int i = size - 2; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = last;
}

void printArray(int arr[], int size)
{
    for (int j = 0; j < size; j++)
    {
        cout << arr[j] << " ";
    }
    cout << endl;
}

void shiftbyK(int arr[], int size, int k)
{
    int j = k;
    while (j)
    {
        int last = arr[size - 1];
        for (int i = size - 2; i >= 0; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[0] = last;
        j--;
    }
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60};
    int size = 6;
    printArray(arr, size);
    shiftByOne(arr, size);
    printArray(arr, size);
    shiftbyK(arr, size, 3);
    printArray(arr, size);
    return 0;
}