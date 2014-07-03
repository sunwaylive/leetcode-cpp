#include <iostream>
using namespace std;

void merge(int A[], int m, int B[], int n) {
    int ai = m - 1, bi = n - 1, cur = m + n - 1;
    while(ai >= 0 && bi >= 0)
        A[cur--] = A[ai] > B[bi] ? A[ai--] : B[bi--];

    while(bi >= 0)
        A[cur--] = B[bi--];
}

void printArray(int A[], int n)
{
    for(int i = 0; i < n; ++i)
        cout<<A[i] <<" ";

    cout<<endl;
}

int main()
{
    int A[20] = {2, 3, 5};
    int B[] = {1, 4, 7};
    merge(A, 3, B, 3);
    printArray(A, 6);
    return 0;
}
