#include <iostream>

using namespace std;

int removeDuplicates(int A[], int n)
{
    for(int i = n-1; i > 0; --i){
        if(A[i] == A[i-1]){
            //move forward
            for(int j = i; j < n - 1; j++)
                A[j] = A[j+1];
            n--;
        }
    }
    return n;
}

void generateArray(int *A, const int n)
{
    for(int i = 0; i < n; i += 2){
        A[i] = i;
        A[i+1] = i;
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

    return 0;
}
