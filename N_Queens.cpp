#include <iostream>
#include <vector>
using namespace std;

//http://www.cnblogs.com/jillzhang/archive/2007/10/21/922830.html
class Solution {
public:

    vector<vector<string> > solveNQueens(int n) {
        vector<int> queenList(n, 0);
        dfs(queenList, result, 0);
        return result;
    }

    bool isSafe(int row, int col, vector<int> queenList){
        //only check the former rows
        for(int i = 0; i < row; ++i){
            int queenCol = queenList[i];
            if(row == i || col == queenCol ||abs(col - queenList[i]) == abs(row - i))
                return false;
        }
        return true;
    }

    //common paradigm: iteration and recursive
    void dfs(vector<int> &queenList, vector<vector<string> > &result, int row){
        const int N = queenList.size();
        if(row == N){
            vector<string> one;
            for(int i = 0; i < N; ++i){
                string s(N, '.');
                s[queenList[i]] = 'Q';
                one.push_back(s);
            }
            result.push_back(one);
        }else{
            //try col by col
            for(int j = 0; j < N; ++j){
                if(!isSafe(row, j, queenList)) continue;

                queenList[row] = j;
                dfs(queenList, result, row + 1);
                //undo
                queenList[row] = 0;
            }
        }
    }
private:
    vector<vector<string> > result;
};

int main()
{
    Solution sln;
    vector<vector<string> > ret = sln.solveNQueens(8);
    cout<<ret.size() <<endl;
    return 0;
}
