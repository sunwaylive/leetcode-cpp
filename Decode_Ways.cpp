#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

class SolutionOld {
public:
    //http://www.cnblogs.com/remlostime/archive/2012/10/30/2746791.html
    int getF(int index){
        if(index < 0) return 1;
        else return f[index];
    }

    int numDecodings2(string s){
        if(s.empty()) return 0;

        f.resize(s.size());
        for(int i = 0; i < s.size(); ++i){
            f[i] = 0;
            if(i >= 1){
                string a(s, i - 1, 2);
                if("10" <= a && a <= "26")
                    f[i] += getF(i - 2);
                if(s[i] >= '1' && s[i] <= '9')
                    f[i] += getF(i - 1);
            }else{
                if(s[i] >= '1' && s[i] <= '9')
                    f[i] = 1;
            }//end else
        }//end for
        return f[f.size() - 1];
    }

private:
    vector<int> f;
};

/* 2016 Second Time Just do it */
class Solution {
public:
    /*
     *DP
     * S(tate): dp[i]:前i个字符的解码方式总数
     * F(unction): dp[i] = sum{dp[j]}, 其中：j满足条件：0 <= j < i && CanDecode(j+1, i)
     * I(init): dp[0] = 1
     * A(nswer): dp[n-1]
     * */
    int numDecodings(string s) {
        if (s.empty()) return 0;

        s.insert(0, "$");
        const int n = s.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (i - j > 2)
                    continue; // 超过26

                if (dp[j] > 0 && CanDecode(s, j+1, i))
                    dp[i] += dp[j]; // dp[j]种切分方式，剩下的一段可切分
            }
            // cout << dp[i] << " ";
        }
        // cout << endl;

        return dp[n-1];
    }

    // 3位数及以上的都被屏蔽了
    bool CanDecode(string &s, int start, int end) {
        string sub_str = s.substr(start, end - start + 1);
        // 处理这种 "01", "02"...
        if (sub_str[0] == '0')
            return false;

        int num = strtol(sub_str.c_str(), NULL, 10);
        // cout << num << endl;

        return num >= 1 && num <= 26;
    }
};

int main()
{
    string s("423");
    Solution sln;
    cout << sln.numDecodings(s) << endl;
    return 0;
}
