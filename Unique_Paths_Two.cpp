#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0].empty()) return -1;

        const int m = obstacleGrid.size();
        const int n = obstacleGrid[0].size();

        this->memorial = vector<vector<int> >(m + 1, vector<int>(n + 1, -1));
        return dfs(m, n, obstacleGrid);
    }

    int dfs(int m, int n, vector<vector<int> > &obstacleGrid){
        if(m < 1 || n < 1) return 0;
        if(obstacleGrid[m - 1][n - 1]) return 0;//when thinking, move the obstacleGrid rightward and downward to the memorial grid;

        return getOrUpdate(m - 1, n, obstacleGrid) + getOrUpdate(m, n - 1, obstacleGrid);
    }

    int getOrUpdate(int m, int n, vector<vector<int> > &obstacleGrid){
        if(memorial[m][n] == -1)
            return memorial[m][n] = dfs(m, n, obstacleGrid);
        else
            return memorial[m][n];
    }

private:
    vector<vector<int> > memorial;
};


vector<vector<int> > createBoard(int m, int n)
{
    vector<vector<int> > board;
    for(int i = 0; i < m; ++i){
        vector<int> row;
        for(int j = 0; j < n; ++j){
            int tmp = (rand() % 2) == 1 ? 0 : 1;
            row.push_back(0);
        }
        board.push_back(row);
    }
    return board;
}

void printBoard(const vector<vector<int> > &board)
{
    for(int i = 0; i < board.size(); ++i){
        for(int j = 0; j < board[i].size(); ++j){
            cout<<board[i][j] <<" ";
        }
        cout<<endl;
    }
}

int main()
{
    vector<vector<int> > board = createBoard(3, 3);// vector<vector<int> >(1, vector<int>(1, 1));
    board[1][1] = 1;
    printBoard(board);
    Solution sln;
    cout<< sln.uniquePathsWithObstacles(board) <<endl;
    return 0;
}
