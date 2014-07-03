#include <iostream>

using namespace std;

void bucket_sort(int A[], int n);
void printArray(int A[], int n);

int firstMissingPositive(int A[], int n) {
    bucket_sort(A, n);
    printArray(A, n);
    for(int i = 0; i < n; ++i){
        if(A[i] != (i + 1))
            return i+1;
    }
    return n+1;
}

void bucket_sort(int A[], int n)
{
    for(int i = 0; i < n; ++i){
        while(A[i] != i + 1){
            if(A[i] <= 0 || A[i] >= n || A[i] == A[A[i] - 1]) break;
            swap(A[i], A[A[i] - 1]);
        }
    }
}

void printArray(int A[], int n)
{
    for(int i = 0; i < n; ++i){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}


int main()
{
    int A[] = {1, 4, 3, 2};
    cout<<firstMissingPositive(A, 4)<<endl;
    return 0;
}
