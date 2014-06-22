#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//no extra space needed
void setZeroes2(vector<vector<int> > &matrix)
{
    if(matrix.empty()) return;

    int m = matrix.size();
    int n = matrix[0].size();
    bool row_has_zero = false;
    bool col_has_zero = false;

    //check whether the first row has zero
    for(int j = 0; j < n; ++j){
        if(matrix[0][j] == 0){
            row_has_zero = true;
            break;
        }
    }

    //check whether the second row has zero
    for(int i = 0; i < m; ++i){
        if(matrix[i][0] == 0){
            col_has_zero = true;
            break;
        }
    }

    //map others to the first row and first col
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    //change all rows except the first row
    for(int i = 1; i < m; ++i){
        if(matrix[i][0] != 0)
            continue;

        for(int j = 0; j < n; ++j)
            matrix[i][j] = 0;
    }

    //change all columns except the first column
    for(int j = 1; j < n; ++j){
        if(matrix[0][j] != 0)
            continue;

        for(int i = 0; i < m; ++i){
            matrix[i][j] = 0;
        }
    }

    //at last change the first row
    if(row_has_zero){
        for(int j = 0; j < n; ++j)
            matrix[0][j] = 0;
    }

    //at last change the first column
    if(col_has_zero){
        for(int i = 0; i < m; ++i)
            matrix[i][0] = 0;
    }
}

//O(m+n) space complexity
void setZeroes(vector<vector<int> > &matrix) {
    if(matrix.empty())
        return;

    int m = matrix.size();
    int n = matrix[0].size();
    vector<bool> row(m, false);
    vector<bool> col(n, false);
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(matrix[i][j] == 0){
                row[i] = true;
                col[j] = true;
            }
        }
    }

    //set affected row to 0
    for(int i = 0; i < m; ++i){
        if(!row[i]) continue;

        for(int j = 0; j < n; ++j){
            matrix[i][j] = 0;
        }
    }

    for(int j = 0; j < n; ++j){
        if(!col[j]) continue;

        for(int i = 0; i < m; ++i){
            matrix[i][j] = 0;
        }
    }
}

vector<vector<int> > generateMatrix(int n)
{
    vector<vector<int> > image;

    for(int i = 0; i < n; ++i){
        vector<int> row(n);
        for(int j = 0; j < n; ++j)
            row[i] = rand() % 100;

        image.push_back(row);
    }

    return image;
}

void printVector(const vector<int> &A)
{
    for(int i = 0; i < A.size(); ++i){
        cout<< A[i] << " ";
    }
    cout<<endl;
}

int main()
{
    int n = 4;
    vector<vector<int> > matrix;
    matrix = generateMatrix(n);
    for(int i = 0; i < matrix.size(); ++i){
        printVector(matrix[i]);
    }

    matrix[n/2][n/2] = 0;

    setZeroes2(matrix);
    for(int i = 0; i < matrix.size(); ++i){
        printVector(matrix[i]);
    }

    return 0;
}
