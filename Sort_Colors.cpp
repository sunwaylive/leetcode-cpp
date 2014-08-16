#include <iostream>
using namespace std;

void printArray(int A[], int n)
{
    for(int i = 0; i < n; ++i)
        cout<<A[i] <<" ";
    cout<<endl;
}

void countingSort(int A[], int n, int k)
{
    int *count = (int*) malloc(sizeof(int) * (k+1));//attention k+1
    for(int i = 0; i < k+1; ++i)
        count[i] = 0;

    for(int i = 0; i < n; ++i)
        count[A[i]]++;

    printArray(count, k+1);
    for(int i = 1; i < k+1; ++i)
        count[i] += count[i-1];

    printArray(count, k+1);

    int *B = (int*) malloc(sizeof(int) * n);
    //sort, reverse traversal for stability
    for(int i = n-1; i >= 0; --i){
        B[count[A[i]] - 1] = A[i];//attention count[A[i]] - 1: real position index
        count[A[i]]--;
    }

    for(int i = 0; i < n; ++i)
        A[i] = B[i];

    free(B);
    free(count);
}

void sortColors(int A[], int n) {
    countingSort(A, n, 2);
    printArray(A, n);
}


//one circle
void sortColors2(int A[], int n)
{
    int red = 0, blue = n - 1;
    for(int i = 0; i < blue + 1;){ //blue is always changing
        if(A[i] == 0)
            swap(A[i++], A[red++]);
        else if(A[i] == 2)
            swap(A[i], A[blue--]);
        else i++;
    }
}

int main()
{
    int A[] = {0, 1, 2, 2, 1, 0, 1, 2};
    sortColors2(A, sizeof(A) / sizeof(A[0]));
    printArray(A, 8);
    return 0;
}
