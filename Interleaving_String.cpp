#include <iostream>
#include <string>
using namespace std;

//http://www.cnblogs.com/remlostime/archive/2012/11/25/2787297.html
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() != s1.length() + s2.length()) return false;

        f[0][0] = true;
        for(int i = 1; i <= s1.size(); ++i)
            f[i][0] = f[i-1][0] && (s3[i-1] == s1[i-1]);

        for(int j = 1; j <= s2.size(); ++j)
            f[0][j] = f[0][j-1] && (s3[j-1] == s2[j-1]);

        for(int i = 1; i <= s1.size(); ++i)
            for(int j = 1; j <= s2.size(); ++j)
                f[i][j] = (f[i-1][j] && (s3[i+j-1] == s1[i-1]))
                    || (f[i][j-1] && (s3[i+j-1] == s2[j-1]));

        return f[s1.size()][s2.size()];
    }

private:
    bool f[1000][1000];
};

int main()
{
    string s1("aabcc");
    string s2("dbbca");
    string s3("aadbbcbcac");
    Solution sln;
    cout<<sln.isInterleave(s1, s2, s3)<<endl;
    return 0;
}
