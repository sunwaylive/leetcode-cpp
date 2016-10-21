#include <iostream>
#include <vector>
using namespace std;

class SolutionOld {
public:
    int jump(int A[], int n) {
        int result = 0;
        int last = 0, cur = 0;
        for(int i = 0; i < n; ++i){
            if(i > last){
                last = cur;
                ++result;
            }
            cur = max(cur, i + A[i]);
        }
        return result;
    }
};

/* 2016 Second Time Just do it */
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.empty()) return 0;

        int n = nums.size();
        const int INF = 1000000;
        vector<int> dp(n, INF);
        dp[0] = 0;
        for (int i = 1; i < n; ++i) {
            // 从前往后，从后往前一个样
            // for (int j = i-1; j >= 0; --j)
            for (int j = 0; j < i; ++j) {
                if (dp[j] != INF && nums[j] >= i - j) {
                    dp[i] = min(dp[i], dp[j] + 1);
                } // end if
            } // end for j
        } // end for i

        // You can assume that you can always reach the last index.
        return dp[n-1];
    }
};

int main()
{
    vector<int> w({2, 1, 2, 0, 4});
    Solution sln;
    cout << sln.jump(w) << endl;
    return 0;
}
