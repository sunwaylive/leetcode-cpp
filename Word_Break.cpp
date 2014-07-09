#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

//dp[i]  表示源串的前i个字符可以满足分割，那么 dp[ j ] 满足分割的条件是存在k 使得 dp [k] && substr[k,j]在字典里。
//http://blog.csdn.net/sunbaigui/article/details/16843549
class Solution {
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

int main()
{
    string s("leetcode");
    unordered_set<string> dict;
    dict.insert("leet");
    dict.insert("code");

    Solution sln;
    cout<<sln.wordBreak(s, dict)<<endl;
    return 0;
}
