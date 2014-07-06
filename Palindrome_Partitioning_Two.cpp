#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
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

int main()
{
    vector<vector<string> > ret;
    Solution sln;
    string s("aab");
    cout<<sln.minCut(s)<<endl;
    return 0;
}
