#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        if(matrix.empty()) return result;

        int beginX = 0, endX = matrix[0].size() - 1;
        int beginY = 0, endY = matrix.size() - 1;
        while(true){
            //top
            for(int j = beginX; j <= endX; ++j) result.push_back(matrix[beginY][j]);
            if(++beginY > endY) break;
            //right
            for(int i = beginY; i <= endY; ++i) result.push_back(matrix[i][endX]);
            if(--endX < beginX) break;
            //bottom
            for(int j = endX; j >= beginX; --j) result.push_back(matrix[endY][j]);
            if(--endY < beginY) break;
            //left
            for(int i = endY; i >= beginY; --i) result.push_back(matrix[i][beginX]);
            if(++beginX > endX) break;
        }
        return result;
    }
};

int main()
{
    vector<int > ret;
    Solution sln;

    vector<vector<int> > m;
    m.push_back(vector<int>({1, 2, 3}));
    m.push_back(vector<int>({4, 5, 6}));
    m.push_back(vector<int>({7, 8, 9}));
    ret = sln.spiralOrder(m);
    for(int i = 0; i < ret.size(); ++i)
        cout<<ret[i]<<" ";

    return 0;
}
