#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //method 1: dfs
    int uniquePaths(int m, int n) {
        this->memorize = vector<vector<int> >(m + 1, vector<int>(n + 1, 0));//initialize to zero
        return dfs(m, n);
    }

    int dfs(int m, int n){
        if(m <= 0 || n <= 0) return 0;
        if(m == 1 && n == 1) return 1;

        return getOrUpdate(m - 1, n) + getOrUpdate(m, n - 1);
    }

    int getOrUpdate(int m, int n){
        if(memorize[m][n] == 0){
            return memorize[m][n] = dfs(m, n);//assign and return
        }else{
            return memorize[m][n];
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
    vector<vector<int> > memorize;
};

int main()
{
    Solution sln;
    cout<< sln.uniquePaths2(1, 1) <<endl;
    return 0;
}
