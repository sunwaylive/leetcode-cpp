#include <iostream>
#include <vector>
#include <string>
using namespace std;

//http://www.cnblogs.com/lihaozy/archive/2012/12/31/2840152.html
class Solution {
public:
    int minDistance(string word1, string word2) {
        const int row = word1.size() + 1;
        const int col = word2.size() + 1;

        vector<vector<int> > f(row, vector<int>(col, 0));
        for(int i = 0; i < row; ++i)
            f[i][0] = i;

        for(int j = 0; j < col; ++j)
            f[0][j] = j;

        //f[0][0] = 0; f[1][1] 存放的是 word1 和 word2 都是一个字母的时候的编辑距离
        //所以求f[1][1]的时候应该比较word1[0], word2[0]. f[i][j]的时候比较word[i-1][j-1]
        for(int i = 1; i < row; ++i){
            for(int j = 1; j < col; ++j){
                if(word1[i - 1] == word2[j - 1])  f[i][j] = f[i - 1][j - 1];
                else f[i][j] = f[i - 1][j - 1] + 1;

                f[i][j] = min(f[i][j], min(f[i - 1][j] + 1, f[i][j - 1] + 1));
            }
        }

        return f[row - 1][col - 1];//word1 和 word2 都完整大小的时候
    }
};

int main()
{
    Solution sln;
    string w1("aabs");
    string w2("aacs");
    cout<<sln.minDistance(w1, w2)<<endl;
    return 0;
}
