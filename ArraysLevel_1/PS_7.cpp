#include<iostream>
using namespace std;

void printExtreme(int arr[], int size){
    int j = size-1;
    int i = 0;
    while (i<=j)
    {
        if (i == j)
        {
            cout << arr[i];
            return;
        }
        
        cout << arr[i] << " " << arr[j] << " ";
        i++;
        j--;
    }
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int size = 9;
    printExtreme(arr, size);
    return 0;
}