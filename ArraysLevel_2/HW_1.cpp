//Pair sum or Two Sum

#include<iostream>
using namespace std;

void printPairSum(int arr[], int size){
    cout << "{ ";
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            cout << arr[i] + arr[j] << " ";
        }
    }
    cout << "}" << endl;
}

int main(){
    int arr[] = {10, 20, 30};
    printPairSum(arr, 3);
    return 0;
}