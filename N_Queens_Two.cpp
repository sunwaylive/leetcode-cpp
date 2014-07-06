#include <iostream>
#include <vector>
using namespace std;

//http://www.cnblogs.com/jillzhang/archive/2007/10/21/922830.html
class Solution {
public:

    int solveNQueens(int n) {
        vector<int> queenList(n, 0);
        dfs(queenList, 0);
        return this->count;
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
    void dfs(vector<int> &queenList, int row){
        const int N = queenList.size();
        if(row == N){
            this->count++;
        }else{
            //try col by col
            for(int j = 0; j < N; ++j){
                if(!isSafe(row, j, queenList)) continue;

                queenList[row] = j;
                dfs(queenList, row + 1);
                //undo
                queenList[row] = 0;
            }
        }
    }
private:
    int count;
};

int main()
{
    Solution sln;
    cout<<sln.solveNQueens(8) <<endl;

    return 0;
}
