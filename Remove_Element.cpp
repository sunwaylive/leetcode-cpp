#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int removeElement(int A[], int n, int elem) {

}

void generateArray(int *A, const int n)
{
    for(int i = 0; i < n; i ++){
        A[i] = i;
    }
}

void printArray(int *A, const int n)
{
    for(int i = 0; i < n; ++i){
        cout<< A[i] << " ";
    }
    cout<<endl;
}

void printVector(const vector<int> &v)
{
    for(vector<int>::const_iterator iter = v.begin();
        iter != v.end(); ++iter){
        cout<<*iter <<" ";
    }
    cout<<endl;
}


int main(){
    int B[2] = {3, 3};

    printArray(B, removeElement(B, 2, 3));
    return 0;
}
