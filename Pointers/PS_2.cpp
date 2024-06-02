#include<iostream>
using namespace std;

int main(){
    int arr[] = {10, 20, 30, 40, 50};
    // arr = arr + 1; - wrong
    int *p = arr;
    //int *p = &arr; - wrong
    int *q = arr + 1;

    cout << arr << endl;
    cout << &arr << endl;
    cout << arr[0] << endl;
    cout << &arr[0] << endl;
    cout << p << endl;
    cout << &p << endl;
    cout << *p << endl;
    cout << q << endl;
    cout << &q << endl;
    cout << *q << endl;
    cout << *p + 1 << endl;
    cout << *p + 2 << endl;
    cout << *q + 2 << endl;
    cout << *(q+4) << endl;
    



}