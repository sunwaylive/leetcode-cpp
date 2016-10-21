#include <iostream>
#include <vector>
using namespace std;

/* 2016 Second Time Just do it */
class Solution {
public:
    /*
     * DP, 定义的时候 dp[i]必须定义为以nums[i]为结尾的LIS的长度
     *
     * State:  dp[i]: 表示以第i个元素结尾的LIS的长度，只有这样才能保证下面的Func能够正确递推
     *         错误的dp[i]的定义：前i个元素中最长的LIS的长度，Wrong!
     * Func: dp[i] = max{dp[j]+1, 其中：0<=j<i && nums[i] > nums[j]}
     * Init: dp[0] = 1;
     * Ans: max{dp[0...n-1]}
     * */
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        const int n = nums.size();
        vector<int> dp(n, 1);
        // dp[0] = 1;
        int max_len = dp[0];
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] = max(dp[i], nums[i] > nums[j] ? dp[j]+1 : 1);
            }
            max_len = max(max_len, dp[i]);
        }

        return max_len;
    }
};

int main() {
    vector<int> nums({11, 12, 13, 1, 2, 3, 4});
    Solution sln;
    cout << sln.lengthOfLIS(nums) << endl;
    return 0;
}
