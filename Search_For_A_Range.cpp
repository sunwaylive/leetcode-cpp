#include <iostream>
#include <vector>

using namespace std;

int findPos(int A[], int begin, int end, int target, bool findLeft)
{
    if(begin > end) return -1;

    int mid = (begin + end) / 2;
    if(target > A[mid]){
        return findPos(A, mid + 1, end, target, findLeft);
    }else if(target < A[mid]){
        return findPos(A, begin, mid - 1, target, findLeft);
    }else{
        int pos = findLeft ? findPos(A, begin, mid - 1, target, findLeft) :
            findPos(A, mid + 1, end, target, findLeft);
        return pos == -1 ? mid : pos;
    }
}

vector<int> searchRange(int A[], int n, int target) {
    int leftPos = findPos(A, 0, n - 1, target, true);
    int rightPos = findPos(A, 0, n - 1, target, false);

    vector<int> ret;
    ret.push_back(leftPos);
    ret.push_back(rightPos);
    return ret;
}

//recursive binary search
int binarySearch(int A[], int n, int begin, int end, int target)
{
    if(begin > end) return -1;
    int mid = (begin + end) / 2;
    if(target > A[mid]){
        return binarySearch(A, n, mid + 1, end, target);
    }else if(target < A[mid]){
        return binarySearch(A, n, begin, mid - 1, target);
    }else{
        return mid;
    }
}

int main()
{
    vector<int> result;
    int A[] = {1, 2, 4, 5, 7, 8, 8, 8};
    result = searchRange(A, sizeof(A) / sizeof(A[0]), 1);
    cout<<result[0]<<endl;
    cout<<result[1]<<endl;

    int n = 8;
    cout<<"search: "<<binarySearch(A, n, 0, n - 1, 4)<<endl;
    return 0;
}
