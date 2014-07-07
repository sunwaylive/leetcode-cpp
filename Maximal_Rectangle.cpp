#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        for(int i = 0; i < matrix.size(); ++i)
            f[i][0] = (matrix[i][0] == '0') ? 0 : 1;

        for(int i = 0; i < matrix.size(); ++i)
            for(int j = 1; j < matrix[i].size(); ++j)
                f[i][j] = (matrix[i][j] == '1') ? (f[i][j - 1] + 1) : 0;

        int ret = 0;
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[i].size(); ++j){
                int k = i;
                int width = INT_MAX;
                while(k >= 0){
                    if(f[k][j] == 0) break;

                    width = min(f[k][j], width);
                    ret = max(ret, width * (i - k + 1));
                    k--;
                }
            }
        }

        return ret;
    }

private:
    int f[1000][1000];
};

int main()
{
    vector<char> row1({'0', '0', '1', '1'});
    vector<char> row2({'0', '0', '0', '1'});
    vector<char> row3({'0', '1', '1', '1'});
    vector<char> row4({'0', '0', '1', '1'});

    vector<vector<char> > matrix;
    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);
    matrix.push_back(row4);

    Solution sln;
    cout<<sln.maximalRectangle(matrix) <<endl;
    return 0;
}
