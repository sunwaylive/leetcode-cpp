#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n) {
    if(n == 1) return 1;
    if(n == 2) return 2;

    int a = 1, b = 2, c;
    for(int i = 3; i <= n; ++i){
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}

/* 2016 Second Time Just do it */
class Solution {
public:
    // state: dp[i]: 表示到达当前点的路径的数量
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        vector<int> dp(n + 1, 0);
        dp[1] = 1, dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};

int main()
{
    Solution sln;
    cout<<sln.climbStairs(4) <<endl;
    return 0;
}
