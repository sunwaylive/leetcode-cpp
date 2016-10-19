#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //bottom up
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.empty()) return 0;
        const int n = triangle.size();

        for(int i = n - 2; i >= 0; --i){
            for(int j = 0; j < i + 1; ++j){
                triangle[i][j] = min(triangle[i + 1][j], triangle[i + 1][j + 1]) + triangle[i][j];
            }
        }
        return triangle[0][0];
    }

    //top down
    int minimumTotal2(vector<vector<int> > &triangle){
        if(triangle.empty()) return 0;
        const int n = triangle.size();

        for(int i = 1; i < n; ++i){
            for(int j = 0; j < i + 1; ++j){
                if(j == 0){//the first element
                    triangle[i][0] = triangle[i - 1][0] + triangle[i][0];
                }else if(j == i){//the last element
                    triangle[i][j] = triangle[i - 1][j - 1] + triangle[i][j];
                }else{
                    triangle[i][j] = min(triangle[i - 1][j], triangle[i - 1][j - 1]) + triangle[i][j];
                }
            }
        }

        int result = triangle[n - 1][0];
        for(int i = 0; i < n; ++i){
            result = min(result, triangle[n - 1][i]);
        }
        return result;
    }

    /* 2016 Second Time Just do it */
    int MinPathTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        vector<int> dp(n + 1, 0);
        vector<int> next(n + 1, 0);

        dp[0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == 0) next[j] = dp[j] + triangle[i][j];        // no prev one
                else if (j == i) next[j] = dp[j-1] + triangle[i][j]; // no current one
                else next[j] = min(dp[j-1] + triangle[i][j], dp[j] + triangle[i][j]); // if have both, get the minimum
            }

            swap(dp, next);
        }

        int res = dp[0];
        for (int i = 0; i < n; ++i) {
            res = min(res, dp[i]);
        }

        return res;
    }
};

int main()
{
    vector<int> row1({2});
    vector<int> row2({3, 4});
    vector<int> row3({1, 5, 7});
    vector<int> row4({4, 1, 8, 3});

    vector<vector<int> > triangle;
    triangle.push_back(row1);
    triangle.push_back(row2);
    triangle.push_back(row3);
    triangle.push_back(row4);
    Solution sln;
    //cout<<sln.minimumTotal2(triangle)<<endl;
    cout << sln.MinPathTotal(triangle) << endl;
    return 0;
}
