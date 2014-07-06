#include <iostream>
#include <vector>
#include <string>
using namespace std;


//http://blog.csdn.net/u011095253/article/details/9177451
class Solution {
public:
    vector<vector<string> > partition(string s) {
        vector<vector<bool> > table = dp(s);
        vector<string> tmp;
        result.clear();
        dfs(s, 0, table, tmp);
        return result;
    }

    void dfs(string &s, int pos, vector<vector<bool> > &table, vector<string> &tmp){
        if(pos == s.size()) result.push_back(tmp);// we have partitioned till the end of the string
        for(int i = pos; i < s.size(); ++i){
            if(table[pos][i]){
                tmp.push_back(s.substr(pos, i - pos + 1));
                dfs(s, i + 1, table, tmp);
                tmp.pop_back();
            }
        }
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

private:
    vector<vector<string> > result;
};

int main()
{
    vector<vector<string> > ret;
    Solution sln;
    string s("aab");
    ret = sln.partition(s);
    for(int i = 0; i < ret.size(); ++i){
        for(int j = 0; j < ret[i].size(); ++j){
            cout<<ret[i][j] <<" ";
        }
        cout<<endl;
    }
    cout<<sln.isPalindrome(s)<<endl;
    return 0;
}
