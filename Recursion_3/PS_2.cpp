#include<iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int target){
    
    if (start > end)
    {
        return -1;
    }

    int mid = start + (end-start) / 2;
    if (arr[mid] == target)
    {
        return mid;
    }
    if (arr[mid] < target)
    {
        int ans =  binarySearch(arr, mid+1, end, target);
        return ans;
    }
    else 
    {
        int ans =  binarySearch(arr, start, mid-1, target);
        return ans;
    }
    
}



int main(){
    int arr[] = {2, 34, 56, 79, 90};
    int start = 0;
    int end = sizeof(arr)/sizeof(arr[0])-1;
    cout << binarySearch(arr, start, end, 78);
}