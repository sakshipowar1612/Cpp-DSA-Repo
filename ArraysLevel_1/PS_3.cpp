#include<iostream>
using namespace std;

int searchTarget(int arr[], int size, int target){
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==target)
        {
            return i;
        }
        
    }
    return -1;
}

int main(){
    int arr[6] = {2,4,6,8,10,12};
    int size = sizeof(arr)/sizeof(int);
    int target = 8;
    int isfound = searchTarget(arr, size, target);
    if (isfound == -1)
    {
        cout << target << " is not found in an array." << endl;
    }
    else{
        cout << target << " is found in an array at insex " << isfound << endl;
    }
    return 0;
}