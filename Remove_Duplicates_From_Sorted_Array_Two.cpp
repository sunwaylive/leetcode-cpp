#include <iostream>

using namespace std;

int removeDuplicates(int A[], int n)
{

}

void generateArray(int *A, const int n)
{
    for(int i = 0; i < n; i += 3){
        A[i] = i;
        A[i+1] = i;
        A[i+2] = i;
    }
}

void printArray(int *A, const int n)
{
    for(int i = 0; i < n; ++i){
        cout<< A[i] << " ";
    }
    cout<<endl;
}

int main(){
    const int size = 20;
    int B[size];
    generateArray(B, size);
    printArray(B, size);

    int new_length = removeDuplicates(B, size);
    printArray(B, new_length);

    int C[3] = {1, 1, 1};
    int c_l = removeDuplicates(C, 3);
    printArray(C, c_l);

    return 0;
}
