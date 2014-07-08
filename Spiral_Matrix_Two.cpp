#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int>(n, 0));
        int begin = 0, end = n - 1;
        int num = 1;
        while(begin < end){
            for(int j = begin; j < end; ++j) { matrix[begin][j] = num++; }
            for(int i = begin; i < end; ++i) { matrix[i][end] = num++; }
            for(int j = end; j > begin; --j) { matrix[end][j] = num++; }
            for(int i = end; i > begin; --i) { matrix[i][begin] = num++; }
            begin++;
            end--;
        }

        if(begin == end) matrix[begin][end] = num;
        return matrix;
    }
};

int main()
{
    Solution sln;
    vector<vector<int> > matrix = sln.generateMatrix(5);
    for(int i = 0; i < matrix.size(); ++i){
        for(int j = 0; j < matrix[i].size(); ++j){
            cout<<matrix[i][j] <<" ";
        }
        cout<<endl;
    }
    return 0;
}
