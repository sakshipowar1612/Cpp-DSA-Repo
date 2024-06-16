// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps
// Example 2:

// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step
#include<iostream>
using namespace std;

// int fib(int n){
//     if (n==0 || n==1)
//     {
//         return n;
//     }
//     return fib(n-1)+fib(n-2);
    
// }

// int climbstairs(int n){
//     return fib(n+1);
// }

int climbstairs(int n){
    if (n==0)
    {
        return 1;
    }
    if (n==1)
    {
        return 1;
    }
    
    return climbstairs(n-1)+climbstairs(n-2);
}

//without reccursion


// int climbStairs(int n) {
//         int prev1 = 0;
//         int prev2 = 1;
//         int ans = 0;
//         for(int i = 1; i <= n; i++){
//             ans = prev1 + prev2;
//             prev1 = prev2;
//             prev2 = ans;
//         }
//         return ans;
//     }

int main(){
    int n;
    cout << "Enter no. of stairs: ";
    cin >> n;
    cout << "No. ways to climb " << n << " stairs = " << climbstairs(n) << endl;
}
