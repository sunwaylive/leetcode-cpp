#include <iostream>
#include <vector>
using namespace std;

class Solution {
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
