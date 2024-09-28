#include <iostream>
#include <algorithm>
using namespace std;

class Heap
{
public:
    int *arr;
    int usedSize;
    int size;

    Heap(int _size)
    {
        this->arr = new int[_size + 1];
        this->usedSize = 0;
        this->size = _size;
    }

    void insert(int val)
    {
        if (usedSize == size)
        {
            cout << "Heap Overflow" << endl;
            return;
        }
        // usedsize increase kar jaenga
        usedSize++;
        int index = usedSize;
        arr[index] = val;

        // take the vale to int's correct position
        while (index > 1)
        {
            int parentIndex = index / 2;
            if (arr[parentIndex] < arr[index])
            {
                swap(arr[parentIndex], arr[index]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    int deleteFromHeap()
    {
        int answer = arr[1];
        arr[1] = arr[usedSize];
        usedSize--;
        int index = 1;
        while (index < usedSize)
        {
            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;
            int largestIndex = index;
            if (leftIndex <= size && arr[largestIndex] < arr[leftIndex])
            {
                largestIndex = leftIndex;
            }
            if (rightIndex <= size && arr[largestIndex] < arr[rightIndex])
            {
                largestIndex = rightIndex;
            }
            if (largestIndex == index)
            {
                break;
            }
            swap(arr[index], arr[largestIndex]);
            index = largestIndex;
        }
        return answer;
    }

    void print()
    {
        for (int i = 1; i <= usedSize; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int *arr, int n, int index)
{
    int leftIndex = index * 2 + 1;
    int rightIndex = 2 * index + 2;
    int largestIndex = index;
    if (leftIndex < n && arr[largestIndex] < arr[leftIndex])
    {
        largestIndex = leftIndex;
    }
    if (rightIndex < n && arr[largestIndex] < arr[rightIndex])
    {
        largestIndex = rightIndex;
    }
    if (largestIndex != index)
    {
        swap(arr[index], arr[largestIndex]);
        heapify(arr, n, largestIndex);
    }
}

void buildHeap(int *arr, int n)
{
    // Start from the last non-leaf node and move upwards
    for (int i = (n / 2 - 1); i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}


void heapSort(int arr[], int n){
    while(n != 1){
        swap(arr[0], arr[n-1]);
        n--;
        heapify(arr, n, 0);
    }
}

int main()
{
    Heap h(5);
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(11);
    h.insert(6);
    h.print();
    cout << h.deleteFromHeap() << endl;
    h.print();
    int arr[] = {45, 50, 60, 40, 30, 20};
    heapify(arr,6,0);
    for(int i: arr){
        cout << i << " ";
    }
    cout << endl;
    int arr1[] = {5, 10, 15, 20, 25, 12};
    buildHeap(arr1, 6);

    for(int i=0; i<6; i++){
        cout << arr1[i] << " ";
    }
    cout << endl;
    int arr2[] = {25, 20, 15, 5, 10, 12};
    heapSort(arr1, 6);
    for(int i=0; i<6; i++){
        cout << arr1[i] << " ";
    }
    cout << endl;

}