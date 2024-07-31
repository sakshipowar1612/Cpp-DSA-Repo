#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

// Memoization array
vector<int> dp;

int f(vector<int>& heights, int ind, int k) {
    if (ind == 0) {
        return 0;
    }

    if (dp[ind] != -1) {
        return dp[ind];
    }

    int ans = INT_MAX;

    for (int i = 1; i <= k; i++) {
        if (ind >= i) {
            int iStep = f(heights, ind - i, k) + abs(heights[ind] - heights[ind - i]);
            ans = min(ans, iStep);
        }
    }

    dp[ind] = ans;
    return ans;
}

int frogJump(vector<int>& heights, int k) {
    int n = heights.size();
    dp.resize(n, -1);
    return f(heights, n - 1, k);
}

int main() {
    vector<int> height = {40, 10, 20, 70, 80, 10, 20, 70, 80, 60};
    cout << frogJump(height, 4);
    return 0;
}
