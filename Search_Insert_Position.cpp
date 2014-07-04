#include <iostream>

using namespace std;

int findPos(int A[], int n, int begin, int end, int target)
{
    if(begin > end) return begin;//actually the next position

    int mid = begin + (end - begin) / 2;
    if(target > A[mid]){
        return findPos(A, n, mid + 1, end, target);
    }else if(target < A[mid]){
        return findPos(A, n, begin, mid - 1, target);
    }else{
        return mid;
    }
}

int searchInsert(int A[], int n, int target) {
    return findPos(A, n, 0, n - 1, target);
}


//http://blog.csdn.net/maqingli87/article/details/8009281

int main()
{
    int A[] = {1, 3, 5, 6};
    cout<<searchInsert(A, sizeof(A) / sizeof(A[0]), 3)<<endl;
    return 0;
}
