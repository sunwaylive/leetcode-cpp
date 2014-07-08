#include <iostream>
#include <string>
#include <vector>

using namespace std;

//http://www.cnblogs.com/remlostime/archive/2012/11/06/2757687.html
class Solution {
public:
    int numDistinct(string S, string T) {
        vector<vector<int> > f(S.size() + 1, vector<int>(T.size() + 1));
        f[0][0] = 1;
        for(int i = 1; i <= S.size(); ++i){
            f[i][0] = 0;
        }

        for(int j = 1; j <= T.size(); ++j){
            f[0][j] = 0;
        }

        for(int i = 1; i <= S.size(); ++i){
            for(int j = 1; j <= T.size(); ++j){
                if(S[i - 1] == T[j - 1]){
                    f[i][j] = 0;
                    for(int k = 0; k < i; ++k)
                        f[i][j] += f[k][j - 1];
                }else
                    f[i][j] = 0;
            }
        }

        int sum = 0;
        for(int i = 0; i <= S.size(); ++i)
            sum += f[i][T.size()];
        return sum;
    }
};

int main()
{
    Solution sln;
    string s("rabbbit");
    string t("rabbit");
    cout<<sln.numDistinct(s, t)<<endl;
    return 0;
}
