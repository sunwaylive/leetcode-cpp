#include <iostream>
#include <vector>

using namespace std;

void printVector(const vector<int> &);

//out of place
void rotate(vector<vector<int> > &matrix) {
    vector<vector<int> > result = matrix;
    int n = matrix.size();
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            result[j][n-1-i] = matrix[i][j];
        }
    }
    matrix = result;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

//in place
void rotate2(vector<vector<int> > &matrix)
{
    int n = matrix.size();

    //flip again counter-diagonal
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n-i; ++j){
            cout<<"i: "<<i <<" j: "<<j <<" matrix[i][j]: "<<matrix[i][j] <<endl;
            swap(matrix[i][j], matrix[n-1-j][n-1-i]);
        }
    }

    for(int i = 0; i < n; ++i){
        printVector(matrix[i]);
    }
    //flip again horizontal line
    for(int i = 0; i < n / 2; ++i){
        for(int j = 0; j < n; ++j){
            swap(matrix[i][j], matrix[n-1-i][j]);
        }
    }
}

vector<vector<int> > generateImage(int n)
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
    int n = 3;
    vector<vector<int> > image = generateImage(n);
    for(int i = 0; i < n; ++i)
        printVector(image[i]);

    rotate2(image);
    for(int i = 0; i < n; ++i)
        printVector(image[i]);

    return 0;
}
