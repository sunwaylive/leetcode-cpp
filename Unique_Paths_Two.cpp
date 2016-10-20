#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

class SolutionOld {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0].empty()) return -1;

        const int m = obstacleGrid.size();
        const int n = obstacleGrid[0].size();

        this->m_hash = vector<vector<int> >(m + 1, vector<int>(n + 1, -1));
        return dfs(m, n, obstacleGrid);
    }

    int dfs(int m, int n, vector<vector<int> > &obstacleGrid){
        if(m < 1 || n < 1) return 0;
        if(obstacleGrid[m - 1][n - 1]) return 0;//when thinking, move the obstacleGrid rightward and downward to the m_hash grid;

        return getOrUpdate(m - 1, n, obstacleGrid) + getOrUpdate(m, n - 1, obstacleGrid);
    }

    int getOrUpdate(int m, int n, vector<vector<int> > &obstacleGrid){
        if(m_hash[m][n] == -1)
            return m_hash[m][n] = dfs(m, n, obstacleGrid);
        else
            return m_hash[m][n];
    }

private:
    vector<vector<int> > m_hash;
};

/* 2016 Second Time Just do it */
class Solution {
public:
    // dp solution
    // state: dp[i][j]: 从起点到当前点的路径数
    // Function: dp[i][j] = dp[i-1][j] + dp[i][j-1] (有障碍则为0，单独处理第一行和第一列)
    // Init: dp[0][0] = 0;
    // ans: dp[m-1][n-1]
    int uniquePathsWithObstacles2(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        m_hash = vector<vector<int> >(m, vector<int>(n, 0));

        // init first row
        for (int j = 0; j < n; ++j)
            if (obstacleGrid[0][j] != 1)
                m_hash[0][j] = 1;

        // init first column
        for (int i = 0; i < m; ++i)
            if (obstacleGrid[i][0] != 1)
                m_hash[i][0] = 1;

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                int left = 0, top = 0;
                if (obstacleGrid[i][j-1] != 1) left = m_hash[i][j-1];
                if (obstacleGrid[i-1][j] != 1) top = m_hash[i-1][j];
                m_hash[i][j] = left + top;
            }
        }

        return m_hash[m-1][n-1];
    }

    int DFS(vector<vector<int> > &obstacleGrid, int r, int c) {
        // printf("r:%d, c:%d\n", r, c);
        // base case: 越界
        if (r >= obstacleGrid.size() || c >= obstacleGrid[0].size())
            return 0;

        // calculated,剪枝
        if (m_hash[r][c] != -1)
            return m_hash[r][c];

        // base case: 障碍
        if(obstacleGrid[r][c] == 1)
            return m_hash[r][c] = 0;
        // base case: 到达终点
        // cout << obstacleGrid.size() << " " << obstacleGrid[0].size() << endl;
        if (r == obstacleGrid.size() - 1 && c == obstacleGrid[0].size() - 1)
            return m_hash[r][c] = 1;

        // recursive case
        return m_hash[r][c] = DFS(obstacleGrid, r, c+1) + DFS(obstacleGrid, r+1, c);
    }

    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        m_hash = vector<vector<int> >(m, vector<int>(n, -1));

        DFS(obstacleGrid, 0, 0);
        return m_hash[0][0];
    }

private:
    vector<vector<int> > m_hash;
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
    vector<vector<int> > board = createBoard(1, 2);// vector<vector<int> >(1, vector<int>(1, 1));
    board[0][0] = 0;
    printBoard(board);
    Solution sln;
    //cout<< sln.uniquePathsWithObstacles(board) <<endl;
    cout<< sln.uniquePathsWithObstacles(board) <<endl;
    return 0;
}
