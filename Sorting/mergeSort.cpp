#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[], int low, int mid, int high){
    vector<int>vec;
    int left = low;
    int right = mid+1;
    while (left<=mid && right<=high)
    {
        if (arr[left]<=arr[right])
        {
            vec.push_back(arr[left]);
            left++;
        }
        else{
            vec.push_back(arr[right]);
            right++;
        }
        
    }
    while (left<=mid)
    {
        vec.push_back(arr[left]);
        left++;
    }
    while (right<=high)
    {
        vec.push_back(arr[right]);
        right++;
    }
    
    for (int i = low; i <= high; i++)
    {
        arr[i] = vec[i-low];
    } 
}


void mergeSort(int arr[], int low, int high){
    if (low==high)
    {
        return;
    }
    int mid = (low+high)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

int main(){
    int arr[] = {13, 46, 24, 52, 20, 9};
    for(int i: arr){
        cout << i << " ";
    }
    cout << endl;
    mergeSort(arr, 0, 5);
    for(int i: arr){
        cout << i << " ";
    }
    cout << endl;
}