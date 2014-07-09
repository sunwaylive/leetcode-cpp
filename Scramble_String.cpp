#include <iostream>
#include <vector>
#include <string>
using namespace std;


//http://blog.csdn.net/pickless/article/details/11501443
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        const int length = s1.size();
        //bool f[length][length][length];
        //memset(f, false, sizeof(bool) * length * length * length);
        vector<vector<vector<bool> > > f(length, vector<vector<bool> >(length, vector<bool>(length, false)));
        for(int k = 1; k <= length; ++k){//f[i][j][k]记录的是S1从i开始k个字符与S2从j开始k个字符是否为Scramble String。
            for(int i = 0; i <= length - k; ++i){
                for(int j = 0; j <= length - k; ++j){
                    if(k == 1)
                        f[i][j][k] = (s1[i] == s2[j]);
                    else{
                        for(int m = 1; m < k; ++m){
                            //当K为更大的数时，同递归算法一样，我们需要枚举分割点，假设左边长度为m，即S[i..i+m-1]，右边长度为k-m，即S[i+m..i+k-1]。同样存在两种情况，S1左 = S2左 && S1右 = S2右 或者 S1左 = S2右 && S1右 = S2左。
                            if((f[i][j][m] && f[i + m][j + m][k - m])//s1左 == s2左 && s1右 == s2右
                               || (f[i][j + k - m][m] && f[i + m][j][k - m])){// s1左 == s2右 && s1右 == s2左
                                f[i][j][k] = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return f[0][0][length];
    }
};

int main()
{
    Solution sln;
    string s1("abcdd");
    string s2("dbdac");
    cout<<sln.isScramble(s1, s2)<<endl;
    return 0;
}
