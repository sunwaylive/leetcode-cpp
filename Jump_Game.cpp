#include <iostream>
#include <vector>
using namespace std;

class SolutionOld {
public:
    //http://www.cnblogs.com/remlostime/archive/2012/11/12/2765894.html
    bool canJump2(int A[], int n){
        if(n == 0) return false;

        int step  = A[0];
        for(int i = 1; i < n; ++i){
            if(step > 0){
                step--;// move to A[i]
                step = max(step, A[i]);
            }else{
                return false;
            }
        }
        return true;
    }

    //Time Exceed Limit solution
    bool canJump(int A[], int n) {
        dfs(0, n - 1, A);
        return this->can;
    }

    void dfs(int start, int end, int A[]){
        if(start >= end)
            can = true;
        else{
            for(int i = 1; i <= A[start]; ++i){
                dfs(start + i, end, A);
            }
        }
    }
private:
    bool can;
};

/* 2016 Second Time Just do it */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty()) return false;

        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0 ; ++j) {
                // 如果从j点能够到达i点，那么dp[i]就是可达的
                if (dp[j] != 0 && nums[j] >= i-j) {
                    dp[i] = 1;
                    break;
                } // end if
            } // end for j
        } // end for i

        return dp[n-1] == 1;
    }
};

int main()
{
    vector<int> w({3,2,1,0,4});
    Solution sln;
    cout << sln.canJump(w) << endl;
    return 0;
}
