#include <iostream>
#include <vector>

using namespace std;

class SolutionOld {
public:
    //method 1: dfs
    int uniquePaths(int m, int n) {
        this->hash_ = vector<vector<int> >(m + 1, vector<int>(n + 1, 0));//initialize to zero
        return dfs(m, n);
    }

    int dfs(int m, int n){
        if(m <= 0 || n <= 0) return 0;
        if(m == 1 && n == 1) return 1;

        return getOrUpdate(m - 1, n) + getOrUpdate(m, n - 1);
    }

    int getOrUpdate(int m, int n){
        if(hash_[m][n] == 0){
            return hash_[m][n] = dfs(m, n);//assign and return
        }else{
            return hash_[m][n];
        }
    }

    //method 2: dp
    int uniquePaths2(int m, int n){
        vector<vector<int> > dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i)
            dp[i][0] = 1; // from (0, 0) to (i, 0) only one path
        for(int j = 0; j < n; ++j)
            dp[0][j] = 1;

        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }

private:
    vector<vector<int> > hash_;
    int m_,n_;
};


/* 2016 Second Time Just do it */
class Solution{
public:
    //sum up:
    // dp方法和dfs方法不同的地方:
    // dp的思想是最优子结构，那么dp[i][j]表示:从起点到当前点的路径数目，它可以用子问题：起点到当前点 前面点的 路径数目 求解. 最终结果在dp[m-1][n-1].
    // dfs的思想是，我要知道当前点到终点的路径数，可以用离终点更近的点的路径数相加获得，那么dfs(i, j)表示：从当前点到终点的路径数.最终结果在hash[0][0]中.
    //
    // dp: 起点到当前点
    // dfs:当前点到终点

    // state: dp[i][j]: 从起点到达该点的路径数目
    // Function: dp[i][j] = dp[i-1][j] + dp[i][j-1] (单独处理第一行和第一列)
    // Init: dp[0][0] = 0;
    // ans: dp[m-1][n-1]
    int UniquePath(int m, int n) {
        vector<vector<int> > dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        // 先初始化第一行
        for (int j = 0; j < n; ++j)
            dp[0][j] = 1;

        // 初始化第一列
        for (int i = 0; i < m; ++i)
            dp[i][0] = 1;

        // 上面两个for为了方便，这样不用在下面的循环中处理越界的case
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }

        return dp[m-1][n-1];
    }


    /* 2016 Second Time Just do it */
    // DFS(r, c): 从(r,c)到达终点的路径数目
    int DFS(int r, int c) {
        // base case: 越界
        if (r >= m_ || c >= n_)
            return 0;

        // 剪枝
        if (hash_[r][c] != -1)
            return hash_[r][c];

        // base case: 终点
        if (r == m_ - 1 && c == n_-1)
            return hash_[r][c] = 1;

        return hash_[r][c] = DFS(r+1, c) + DFS(r, c+1);
    }

    int UniquePath2(int m, int n) {
        m_ = m, n_ = n;
        hash_ = vector<vector<int> >(m, vector<int>(n, -1));
        DFS(0, 0);
        return hash_[0][0];
    }

private:
    vector<vector<int> > hash_;
    int m_,n_;
};

int main()
{
    Solution sln;
    //cout<< sln.uniquePaths2(1, 1) <<endl;
    cout << sln.UniquePath(2, 2) << endl;
    cout << sln.UniquePath2(2, 2) << endl;
    return 0;
}
