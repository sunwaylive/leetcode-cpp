#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n == 0) return 0;

        int result = A[0];
        for(int i = 1; i < n; ++i){
            A[i] = max(A[i], A[i] + A[i - 1]);
            result = max(result, A[i]);
        }
        return result;
    }

    int maxSubArray2(int A[], int n){
        return maxSum(A, 0, n - 1);
    }

    int maxSum(int A[], const int begin, const int end){
        int mid = 0;
        int lmax = 0, rmax = 0;
        int tmpSum = 0;
        if(begin == end) return A[mid];

        mid = (begin + end) / 2;
        for(int i = mid; i >= begin; --i){
            tmpSum += A[i];
            lmax = max(tmpSum, lmax);
        }

        tmpSum = 0;
        for(int i = mid + 1; i <= end; ++i){
            tmpSum += A[i];
            rmax = max(tmpSum, rmax);
        }

        return max(lmax + rmax, max(maxSum(A, begin, mid), maxSum(A, mid + 1, end)));
    }
};

int main()
{
    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution sln;
    cout<<sln.maxSubArray(A, sizeof(A)/ sizeof(A[0]))<<endl;
    return 0;
}
