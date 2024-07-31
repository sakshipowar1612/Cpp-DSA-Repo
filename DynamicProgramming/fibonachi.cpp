#include<iostream>
#include<vector>
using namespace std;

int function(int n, vector<int>&dp){
    if (n<=1)
    {
        return n;
    }
    if(dp[n]!=-1)
        return dp[n];
    return dp[n]=function(n-1, dp)+function(n-2, dp);
}

int main(){
    int n;
    cout << "Enter n = " << endl;
    cin >> n;
    vector<int>vec(n+1, -1);
    cout << function(n, vec)<< endl;
    int prev2 = 0;
    int prev1 = 1;
    int ans;
    for (int i = 2; i <= n; i++)
    {
        ans = prev1+prev2;
        prev2 = prev1;
        prev1 = ans;
    }
    cout << ans << endl;
    
}