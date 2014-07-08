#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;

        if(numRows <= 0) return result;

        vector<int> first({1});
        result.push_back(first);
        for(int i = 1; i < numRows; ++i){
            vector<int> row(i + 1, -1);
            for(int j = 0; j < i + 1; ++j){
                if(j == 0){
                    row[0] = result[i - 1][0];
                }else if(j == i){
                    row[j] = result[i - 1][i - 1];
                }else{
                    row[j] = result[i - 1][j] + result[i - 1][j - 1];
                }
            }
            result.push_back(row);
        }
        return result;
    }
};

int main()
{
    vector<vector<int> > result;
    Solution sln;
    result = sln.generate(4);
    for(int i = 0; i < result.size(); ++i){
        for(int j = 0; j < result[i].size(); ++j){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
