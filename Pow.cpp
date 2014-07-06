#include <iostream>

using namespace std;

class Solution {
public:
    double pow(double x, int n) {
        if(n < 0){
            return 1.0 / power(x, -n);
        }else{
            return power(x, n);
        }
    }

    double power(double x, int n){
        if(n == 0) return 1.0f;

        double h = power(x , n / 2);
        if(n & 0x1){//n is odd
            return h * h * x;
        }else{
            return h * h;
        }
    }
};

int main()
{
    Solution sln;
    cout<<sln.pow(34.00515, -3)<<endl;
    return 0;
}
