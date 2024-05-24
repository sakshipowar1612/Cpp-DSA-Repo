#include<iostream>
#include<limits.h>
using namespace std;

int getSmallestelement(int arr[], int size){
    int smallestElement = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < smallestElement)
        {
            smallestElement = arr[i];
        }
        
    }
    return smallestElement;
}

int main(){
    int arr[] = {20, 4, 15, 2, 6, 8, 11};
    int size = sizeof(arr)/sizeof(int);
    cout << "samllest elemnt in an array = " << getSmallestelement(arr, size) << endl;
    return 0;
}