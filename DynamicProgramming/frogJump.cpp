#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

// int f(vector<int>&heights, int ind){
//     if (ind==0)
//     {
//         return 0;
//     }
//     int oneStep = f(heights, ind-1)+abs(heights[ind]-heights[ind-1]);
//     int twoStep = INT_MAX;
//     if (ind>1)
//     {
//         twoStep = f(heights, ind-2)+abs(heights[ind]-heights[ind-2]);
//     }

//     return min(oneStep, twoStep);
// }

// int frogJump(vector<int> &heights, int step)
// {
//     return f(heights, step - 1);
// }

// Memoization
//  int f(vector<int> &heights, vector<int> &dp, int index)
//  {
//      if (index == 0)
//      {
//          return dp[0] = 0;
//      }
//      if (dp[index] != -1)
//      {
//          return dp[index];
//      }
//      int oneStep = f(heights, dp, index-1) + abs(heights[index] - heights[index - 1]);
//      int twoStep = INT_MAX;
//      if (index > 1)
//      {
//          twoStep = f(heights, dp, index - 2) + abs(heights[index] - heights[index - 2]);
//      }

//     return dp[index]=min(oneStep, twoStep);
// }

// int frogJump(vector<int> &heights, int step)
// {
//     vector<int> dp(step, -1);
//     return f(heights, dp, step - 1);
// }

// tabulation
int frogJump(vector<int> &heights, int step)
{
    int prev1 = 0;
    int prev2 = 0;
    for (int i = 1; i < step; i++)
    {
        int oneStep = prev1 + abs(heights[i] - heights[i - 1]);
        int twoStep = INT_MAX;
        if (i > 1)
        {
            twoStep = prev2 + abs(heights[i] - heights[i - 2]);
        }
        int curr = min(oneStep, twoStep);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}



int main()
{
    vector<int> height = {30, 10, 60, 10, 60, 50};
    cout << frogJump(height, 6);
}