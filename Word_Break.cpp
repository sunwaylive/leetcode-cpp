#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

//dp[i]  表示源串的前i个字符可以满足分割，那么 dp[ j ] 满足分割的条件是存在k 使得 dp [k] && substr[k,j]在字典里。
//http://blog.csdn.net/sunbaigui/article/details/16843549
class SolutionOld {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        const int n = s.size();
        vector<bool> f(n + 1, false);
        f[0] = true;

        for(int i = 1; i <= n; ++i){
            for(int k = 0; k < i; ++k){
                f[i] = f[k] && dict.find(s.substr(k, i - k)) != dict.end();
                if(f[i]) break;//we can't return here, f[i] is true only means that s[0...i-1] is qualified
            }
        }
        return f[n];
    }
};

/* 2016 Second Time Just do it */
class Solution {
public:
    /*
     *DP solution: "leetcode" -> "$leetcode", 插入一个dummy char，方便dp[i]含义的定义和理解
     * State: dp[i]:表示截止i-th字符(包含)的时候 能否被完美切分, 1:true, 0:false
     * Func: dp[i] = OR{dp[j] && str[j+1,i] in Dict, 其中 0 <= j < i}
     * Init: dp[0] = 1
     * Ans: dp[n-1]
     * */
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        s.insert(0, "$");
        const int n = s.size();

        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] != 0 && wordDict.find(s.substr(j+1, i-j)) != wordDict.end()) {
                    dp[i] = 1;
                    break;
                }
            }
        }

        return dp[n-1] != 0;
    }
};

int main()
{
    string s("leeatcode");
    unordered_set<string> dict;
    dict.insert("leet");
    dict.insert("code");

    Solution sln;
    cout<<sln.wordBreak(s, dict)<<endl;
    return 0;
}
