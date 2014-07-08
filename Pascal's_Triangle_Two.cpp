#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        rowIndex = rowIndex + 1; //start from zero
        vector<int> row(rowIndex, 1);
        for(int i = 0; i < rowIndex; ++i){
            for(int j = i - 1; j >= 1; --j){
                row[j] = row[j] + row[j - 1];//from end to start, change your sequence
            }
        }
        return row;
    }
};

int main()
{
    vector<int> result;
    Solution sln;
    result = sln.getRow(3);
    for(int i = 0; i < result.size(); ++i)
        cout<<result[i] <<endl;
    return 0;
}
