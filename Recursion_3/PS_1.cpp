#include<iostream>
using namespace std;

bool isSorted(int arr[], int size, int index){
    if (index >= size-1){
        return true;
    }
    if (arr[index]> arr[index+1])
    {
        return false;
    }
    bool ans = isSorted(arr, size, ++index);
    return ans;
}

int main(){
    int arr[] = {9, 2, 6, 4, 5};
    cout << isSorted(arr, 5, 0)<<endl;
}