#include <iostream>
#include <vector>
using namespace std;

int findRow(vector<vector<int> > &matrix, int target)
{
    return 0;
}

bool searchMatrix(vector<vector<int> > &matrix, int target) {
    int begin = 0, end = matrix.size() - 1;
    while(begin <= end){
        int mid = begin + (end - begin) / 2;
        cout<<matrix[mid][0]<<endl;
        if(target == matrix[mid][0]){
            return true;
        }else if(target > matrix[mid][0]){
            begin = mid + 1;
        }else{
            end = mid - 1;
        }
    }

    int row = begin - 1; //now the target is in the row;
    if(row < 0 || row > matrix.size() - 1) return false;

    begin = 0, end = matrix[0].size() - 1;
    while(begin <= end){
        int mid = begin + (end - begin) / 2;
        if(target == matrix[row][mid]){
            return true;
        }else if(target > matrix[row][mid]){
            begin = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return false;
}

vector<vector<int> > generateMatrix(int m, int n)
{
    vector<vector<int> > matrix;
    for(int i = 0; i < m; ++i){
        vector<int> row;
        for(int j = 0; j < n; ++j){
            row.push_back(i * n + j + 1);
        }
        matrix.push_back(row);
    }
    return matrix;
}

void printMatrix(const vector<vector<int> > &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();// matrix not empty
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
    vector<vector<int> > matrix;
    matrix = generateMatrix(1, 1);
    printMatrix(matrix);
    cout<<searchMatrix(matrix, 1)<<endl;
    return 0;
}
