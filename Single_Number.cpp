#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int singleNumber(int A[], int n) {
    int ret = 0;
    for(int i = 0; i < n; ++i)
        ret ^= A[i];

    return ret;
}

int main()
{
    int c[] = {1, 1, 3};
    cout<<singleNumber(c, 4)<<endl;
    return 0;
}
