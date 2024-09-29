#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;


int getKthSmallest(int *arr, int n, int k){
    priority_queue<int>pq;
    for(int i=0; i<k; i++){
        pq.push(arr[i]);
    }
    for(int i=k; i<n; i++){
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}

int getKthGreatest(int *arr, int n, int k){
    priority_queue<int, vector<int>, greater<int>>pq;
    for(int i=0; i<k; i++){
        pq.push(arr[i]);
    }
    for(int i=k; i<n; i++){
        if(arr[i]>pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}


int main(){
    int arr[] = {5, 7, 8, 12, 2, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    cout << getKthSmallest(arr, n, k)<<endl;
    cout << getKthGreatest(arr, n, 2)<<endl;
}