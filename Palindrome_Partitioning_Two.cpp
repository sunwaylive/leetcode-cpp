#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SolutionOld {
public:
    int minCut(string s){
        if(s.empty()) return -1;

        vector<vector<bool> > table = dp(s);
        const int len = s.size();
        int *cut = (int*) malloc(sizeof(int) * (len + 1));
        cut[len] = 0;
        for(int i = len - 1; i >=0; --i){
            cut[i] = len - i;
            for(int j = i; j < len; ++j){
                if(table[i][j])
                    cut[i] = min(cut[i], cut[j+1] + 1);
            }
        }
        return cut[0] - 1;
    }

    vector<vector<bool> > dp(string &s){
        const int n = s.size();
        vector<vector<bool> > table(n, vector<bool>(n, false));
        if(s.empty()) return table;

        for(int i = 0; i < n; ++i)
            table[i][i] = true;

        for(int i = 0; i < n; ++i){
            int l, r;
            //check for odd
            l = i - 1;
            r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r]){
                table[l][r] = true;
                l--, r++;
            }

            //check for even
            l = i - 1;
            r = i;
            while(l >= 0 && r < n && s[l] == s[r]){
                table[l][r] = true;
                l--, r++;
            }
        }
        return table;
    }

    //judge palindrome
    bool isPalindrome(const string &s){
        int l = 0, r = s.size() - 1;
        while(s[l] == s[r])//can not combine the following code in this line
            l++, r--;

        return l >= r;
    }

public:
    int minCutNum;
};

/* 2016 Second Time Just do it */
class Solution {
public:
    /*DP solution: TLE Wrong, 掌握思想
     * "aab" -> "$aab"
     * dp[i]:表示截止i-th字符，需要的最少的cut次数
     * dp[i] = dp[j] + 1, 对于满足这个条件的j:  0 <= j < i, 并且str[j+1, i]是回文
     * dp[0] = -1; 这样能保证 对于原来的"aab"，首号位置的cut值为0
     * ans: dp[n-1], 最后一个元素
     * */
    int minCut(string s) {
        s.insert(0, "$");
        int n = s.size();
        const int INF = 10000000;
        vector<int> dp(n, INF);
        dp[0] = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (isPa(s, j+1, i)) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n-1];
    }

    bool isPa(string &s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<string> > ret;
    Solution sln;
    string s("aab");
    cout<<sln.minCut(s)<<endl;
    return 0;
}
