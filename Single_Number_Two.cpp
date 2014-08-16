#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


//some number occurs k times, except one occurs l times, n stand for the length of A;

// int singleNumber(int A[],int n, int k, int l) {
//     if (A == NULL) return 0;
//     int t;
//     int *x = new int[k];
//     x[0] = ~0;
//     for (int i = 0; i < n; i++) {
//         t = x[k-1];
//         for (int j = k-1; j > 0; j--) {
//             x[j] = (x[j-1] & A[i]) | (x[j] & ~A[i]);
//         }
//         x[0] = (t & A[i]) | (x[0] & ~A[i]);
//     }
//     return x[l];
// }

// int main()
// {
//     int A[] = {2,2,2,3,3,3,1,1};
//     cout<<singleNumber(A, 8, 3, 2)<<endl;
//     return 0;
// }

int singleNumber(int A[], int n) {
    const int w = sizeof(int) * 8;
    int count[w];
    fill_n(count, w, 0);

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < w; ++j){
            count[j] += (A[i] >> j) & 0x1;//get the first bit
            count[j] %= 3;
        }

    int result = 0;
    for(int i = 0; i < w; ++i)
        result += (count[i]<<i);

    return result;
}

int main()
{
    int c[] = {1, 1, 1, 3};
    cout<<singleNumber(c, 4)<<endl;
    return 0;
}
