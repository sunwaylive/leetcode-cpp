#include <iostream>

using namespace std;

void printArray(int A[], int n);

void countingSort(int A[], int n, int k)
{
    //initialize counting array
    int *count = (int*) malloc(sizeof(int) * (k+1));
    for(int i = 0; i < k+1; ++i)
        count[i] = 0;

    //count elements in A
    for(int i = 0; i < n; ++i)
        count[A[i]]++;

    //add up
    for(int i = 1; i < k+1; ++i)
        count[i] = count[i] + count[i-1];

    printArray(count, k+1);
    //rearrange array
    int *B = (int*)malloc(sizeof(int) * (n+1));//why n+1??
    for(int i = n-1; i >=0; --i){
        B[count[A[i]] - 1] = A[i];//count[A[i]] - 1 is the real position index
        count[A[i]]--;
    }

    printArray(B, n);
    for(int i = 0; i < n; ++i)
        A[i] = B[i];
    printArray(A, n);
}

void printArray(int A[], int n)
{
    for(int i = 0; i < n; ++i)
        cout<<A[i] <<" ";
    cout<<endl;
}

int main()
{
    int A[] = {1, 0, 5, 2, 4};
    countingSort(A, sizeof(A) / sizeof(A[0]), 5);
    return 0;
}
