#include<iostream>
using namespace std;

void doubles(int arr[], int size){
    for (int j = 0; j < size; j++)
    {
        arr[j] = arr[j]*2;
    }
}

void prints(int arr[], int size){
    for (int k = 0; k < size; k++)
    {
        cout << arr[k] << endl;
    }
    
}

int main(){
    int arr[10];
    int size = 10;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "printing the values of array : " << endl;
    prints(arr, size);
    doubles(arr, size);
    cout << "printing the doubled values of array : " << endl;
    prints(arr, size);
    return 0;

}