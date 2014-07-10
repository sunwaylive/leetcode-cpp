#include <iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = dividend < 0 ? -(long long)dividend : dividend;
        long long b = divisor < 0 ? -(long long)divisor : divisor;

        long long result = 0;
        while(a >= b){
            long long c = b;//reset c to b
            for(int i = 0; a >= c; ++i, c <<= 1){ // double c, increase i;
                a -= c;
                result += (1 << i);
            }
        }
        //decide the sign, xor and then get the highest bit
        return (dividend ^ divisor) >> 31 ? -result : result;
    }
};

int main()
{
    int a = INT_MIN, b = 1;
    Solution sln;

    cout<<sln.divide(a, b)<<endl;
    return 0;
}
