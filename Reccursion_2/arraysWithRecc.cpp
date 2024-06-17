#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

void printArray(int arr[], int n)
{
    if (n == 0)
    {
        return;
    }
    cout << *arr << " ";
    printArray(arr + 1, n - 1);
}

void takeEle(int arr[], int n)
{
    if (n == 0)
    {
        return;
    }
    cin >> *arr;
    takeEle(arr + 1, n - 1);
}

void print(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

bool searchInArray(int arr[], int size, int data, int index)
{
    if (index >= size)
    {
        return false;
    }
    if (arr[index] == data)
    {
        cout << data << " found at index " << index << endl;
        return true;
    }
    index++;
    return searchInArray(arr, size, data, index);
}

void findMin(int arr[], int size, int index, int &min)
{
    if (index >= size)
    {
        return;
    }
    if (arr[index] <= min)
    {
        min = arr[index];
    }
    findMin(arr, size, index + 1, min);
}

void findMax(int arr[], int size, int index, int &max)
{
    if (index >= size)
    {
        return;
    }
    if (arr[index] >= max)
    {
        max = arr[index];
    }
    findMax(arr, size, index + 1, max);
    return;
}

void even(int arr[], int size, int index, vector<int> &vec)
{

    if (index >= size)
    {
        return;
    }
    if (arr[index] % 2 == 0)
    {
        vec.push_back(arr[index]);
    }
    even(arr, size, index + 1, vec);
}

void doubleElements(int arr[], int size, int index)
{
    if (index >= size)
    {
        return;
    }
    arr[index] = arr[index] * 2;
    doubleElements(arr, size, ++index);
    return;
}

int findInArray(int arr[], int index, int size, int target)
{
    if (index >= size)
    {
        return -1;
    }
    if (arr[index] == target)
    {
        return index;
    }
    int ans = findInArray(arr, ++index, size, target);
    return ans;
}

void printIndexOfOccu(int arr[], int size, int index, int target)
{
    if (index >= size)
    {
        return;
    }
    if (arr[index] == target)
    {
        cout << index << " ";
    }
    printIndexOfOccu(arr, size, ++index, target);
    return;
}

void vecIndexOfOccu(int arr[], int size, int index, int target, vector<int> &vec)
{
    if (index >= size)
    {
        return;
    }
    if (arr[index] == target)
    {
       
        vec.push_back(index);
    }
    vecIndexOfOccu(arr, size, ++index, target, vec);
    return;
}

void splitNum(long int n, vector<int>&vec){
    if (n==0)
    {
        return;
    }
    int a = n%10; 
    n = n/10;
    splitNum(n, vec);
    vec.push_back(a);
    return; 
}

int main()
{
    // int size;
    // cout << "Enter size of array: ";
    // cin >> size;
    // int *arr = new int(size);
    // takeEle(arr, size);
    // cout << "Printing an array: ";
    // printArray(arr, size);
    // cout << endl;
    // cout << searchInArray(arr, size, 4, 0);
    // int mini = INT_MAX;
    // findMin(arr, size, 0,mini);
    // cout << mini << endl;

    int arr[] = {10, 2, 4, 10, 10, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    // vector<int> v;
    // even(arr, size, 0, v);
    // for (int num : v)
    // {
    //     cout << num << " ";
    // }
    // cout << endl;

    // doubleElements(arr, size, 0);
    // printArray(arr, size);
    // cout << endl;
    // int max = INT_MIN;
    // findMax(arr, size, 0, max);
    // cout << max << endl;
    // cout << findInArray(arr, 0, size, 10) << endl;
    // printIndexOfOccu(arr, size, 0, 10);
    // cout << endl;
    vector<int>vec;
    vecIndexOfOccu(arr, size, 0, 10, vec);
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    long int a = 4125;
    vector<int>ve;
    splitNum(a, ve);
    for (int i = 0; i < ve.size(); i++)
    {
        cout << ve[i] << " ";
    }
    cout << endl;
    
}