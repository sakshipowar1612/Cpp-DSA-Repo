//Sort 0's and 1's
#include<iostream>
using namespace std;

void sortZeroesOnes(int arr[], int size){
    int countZeroes = 0;
    int countOnes = 0;
    for (int i = 0; i < size; i++)
    {
       if (arr[i]==0)
       {
            countZeroes += 1;
       }
       else if (arr[i]==1)
       {
            countOnes += 1;
       }
    }
    for (int j = 0; j < size; j++)
    {
        if (j<countZeroes)
        {
            arr[j] = 0;
        }
        else{
            arr[j] = 1;
        }
        
    }
}

void printArray(int arr[], int size){
    for (int j = 0; j < size; j++)
    {
        cout << arr[j] << " ";
    } 
    cout << endl;
}


//Using two pointer approach.
void getSortedArray(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (arr[i]==1 && arr[j]==0)
            {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
                break;
            }   
        }   
    }
}

int main(){
    int arr[] = {0, 1, 1, 0, 1, 0, 0, 0, 1};
    int size = sizeof(arr)/sizeof(int);
    printArray(arr, size);
    // sortZeroesOnes(arr, size);
    getSortedArray(arr, size);
    printArray(arr, size);
    return 0;
}