#include<iostream>
using namespace std;

int main(){
    int arr[] = {10, 20, 30, 40, 50};
    cout << arr << endl; //Base Address
    cout << arr[0] << endl;
    cout << &arr[0] << endl;//Base Address
    cout << &arr << endl; //Base address of whole array 
}