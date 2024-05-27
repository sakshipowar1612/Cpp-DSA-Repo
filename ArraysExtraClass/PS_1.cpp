// Sort negative and positive elements.
#include <iostream>
using namespace std;

void sortNegPos(int arr[], int size)
{
    int i = 0;
    for (int j = 0; j < size; j++)
    {
        if (arr[i] >= 0 && arr[j] < 0)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    } 
}
void printArray(int arr[], int size)
{
    for (int j = 0; j < size; j++)
    {
        cout << arr[j] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {23, -7, 0, -10, -11, 40};   //{-7, -10, -11, 23, 0, 40}
    int size = 6;
    printArray(arr, size);
    sortNegPos(arr, 6);
    printArray(arr, size);
    return 0;
}