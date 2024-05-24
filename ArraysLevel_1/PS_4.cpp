#include<iostream>
using namespace std;

int countZero(int arr[], int size){
    int countZero = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==0)
        {
            countZero += 1;
        }
        
    }
    return countZero;
}

int countOne(int arr[], int size){
    int countOne = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==1)
        {
            countOne += 1;
        }
        
    }
    return countOne;
}

int main(){
    int arr[] = {0, 1, 1, 1, 0, 0, 1};
    int size = sizeof(arr)/sizeof(int);
    cout << "no. of zeros in given array = " << countZero(arr, size) << " and no. of ones in given array = " << countOne(arr, size) << endl;
    return 0;
}
