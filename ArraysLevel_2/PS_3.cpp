//Print all triplets {1, 2, 3, 4}
#include<iostream>
using namespace std;

void printTriplets(int arr[], int size){
    cout << "{ ";
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            for (int k = i; k < size; k++)
            {
                cout << "(" << arr[i] << " ," << arr[j] << " ," << arr[k] << ") ";
            }
            
        }
    }
    cout << "}" << endl;
}

int main(){
    int arr[] = {1, 2, 3, 4};
    printTriplets(arr, 4);
    return 0;
}