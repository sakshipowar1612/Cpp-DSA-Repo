#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int size = nums.size();
        for(int x = 0; x <= size; x++){
            int gandequal = 0;
            cout << x << endl;
            for (int i = 0; i < size; i++)
            {
                if (nums[i] >= x)
                {
                    gandequal += 1;
                }
            }
            cout << gandequal << endl;
            if (gandequal == x){
                return x;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 5};
    int result = solution.specialArray(nums);
    cout << "The special value is: " << result << endl;
    return 0;
}
