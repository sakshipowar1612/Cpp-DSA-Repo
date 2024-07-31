#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

int f(vector<int>&heights, int ind){
    if (ind==0)
    {
        return 0;
    }
    int oneStep = f(heights, ind-1)+abs(heights[ind]-heights[ind-1]);
    int twoStep = INT_MAX;
    if (ind>1)
    {
        twoStep = f(heights, ind-2)+abs(heights[ind]-heights[ind-2]);
    }
    
    return min(oneStep, twoStep);
}

int frogJump(vector<int>&heights, int step){
    return f(heights, step-1);
}


int main(){
    vector<int>height={30, 10, 60, 10, 60, 50};
    cout << frogJump(height, 6);
}