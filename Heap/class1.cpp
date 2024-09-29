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
        this->arr = new int[_size];
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

        int index = usedSize;
        arr[index] = val;
        usedSize++;

        // take the vale to int's correct position
        while (index > 0)
        {
            int parentIndex = (index - 1) / 2;
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
        if (usedSize == 0)
        {
            cout << "Heap Underflow" << endl;
            return -1; // Or any other error handling
        }

        int answer = arr[0]; // Root element of the heap

        arr[0] = arr[usedSize - 1]; // Replace root with last element
        usedSize--;                 // Reduce size of the heap

        // Heapify the root to restore heap property
        int index = 0;
        while (index < usedSize)
        {
            int leftIndex = 2 * index + 1;
            int rightIndex = 2 * index + 2;
            int largestIndex = index;

            // Compare with the left child
            if (leftIndex < usedSize && arr[largestIndex] < arr[leftIndex])
            {
                largestIndex = leftIndex;
            }

            // Compare with the right child
            if (rightIndex < usedSize && arr[largestIndex] < arr[rightIndex])
            {
                largestIndex = rightIndex;
            }

            // If the largest is still the current node, the heap is valid
            if (largestIndex == index)
            {
                break;
            }

            // Swap with the largest child and continue heapifying
            swap(arr[index], arr[largestIndex]);
            index = largestIndex;
        }

        return answer; // Return the root that was deleted
    }

    void print()
    {
        for (int i = 0; i < usedSize; i++)
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

void heapSort(int arr[], int n)
{
    while (n != 1)
    {
        swap(arr[0], arr[n - 1]);
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