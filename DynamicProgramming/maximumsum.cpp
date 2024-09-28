#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// int solve(vector<int>& nums, int index, vector<int>& dp) {
//     if (index == 0) {
//         return nums[0];
//     }
//     if (index < 0) {
//         return 0;
//     }
//     if (dp[index] != -1) {
//         return dp[index];
//     }
//     int left = solve(nums, index - 2, dp) + nums[index];
//     int right = solve(nums, index - 1, dp);
//     return dp[index] = max(left, right);
// }

// int maximumNonAdjacentSum(vector<int>& nums) {
//     vector<int> dp(nums.size(), -1);
//     return solve(nums, nums.size() - 1, dp);
// }


//Tabulation
int solve(vector<int>& nums, int n) {
    int prev1 = nums[0];
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int take = nums[i];
        if(i>1){
            take += prev2;
        }
        int notTake = 0+prev1;
        int curr = max(take, notTake);
        prev2 = prev1;
        prev1 = curr; 
    }
    return prev1;
}

int maximumNonAdjacentSum(vector<int>& nums) {
    return solve(nums, nums.size());
}

int main() {
    vector<int> nums = {3, 2, 5, 10, 7}; // Example input
    cout << "Maximum non-adjacent sum: " << maximumNonAdjacentSum(nums) << endl;
    return 0;
}
