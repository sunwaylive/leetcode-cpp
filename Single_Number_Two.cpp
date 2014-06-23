#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

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
