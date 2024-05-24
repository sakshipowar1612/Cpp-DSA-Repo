//Print all posible pairs.
#include<iostream>
using namespace std;

void printPairs(int arr[], int size){
    cout << "{ ";
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            cout << "(" << arr[i] << " ," << arr[j] << ") ";
        }
    }
    cout << "}" << endl;
}

int main(){
    int arr[] = {10, 20, 30};
    printPairs(arr, 3);
    return 0;
}