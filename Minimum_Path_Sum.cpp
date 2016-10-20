#include <iostream>
#include <vector>
using namespace std;

class SolutionOld {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if(grid.empty()) return 0;
        const int m = grid.size();
        const int n = grid[0].size();

        //initialize the first row
        for(int j = 1; j < n; ++j){
            grid[0][j] = grid[0][j - 1] + grid[0][j];
        }
        //initialize the first col
        for(int i = 1; i < m; ++i){
            grid[i][0] = grid[i][0] + grid[i - 1][0];
        }

        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                grid[i][j] =  min(grid[i][j - 1], grid[i - 1][j]) + grid[i][j];
            }
        }

        return grid[m - 1][n - 1];
    }
};


/* 2016 Second Time Just do it */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int m = grid.size(), n = grid[0].size();
        vector<vector<int> > dp(m, vector<int>(n, -1));
        dp[0][0] = grid[0][0];

        for (int j = 1; j < n; ++j)
            dp[0][j] = dp[0][j-1] + grid[0][j];

        for (int i = 1; i < m; ++i)
            dp[i][0] = dp[i-1][0] + grid[i][0];

        // 上面两个循环为了方便
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i][j];
            }
        }

        return dp[m-1][n-1];
    }
};

int main()
{
    vector<int> row1({2, 2, 1});
    vector<int> row2({1, 0, 1});
    vector<vector<int> > grid;
    grid.push_back(row1);
    grid.push_back(row2);
    Solution sln;
    cout<<sln.minPathSum(grid)<<endl;
    return 0;
}
