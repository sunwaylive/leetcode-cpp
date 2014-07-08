#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        queue<int> digits;
        int sign = 1;
        if(x < 0){
            sign = -1;
            x = -x;
        }

        while(x > 0){
            digits.push(x % 10);
            x /= 10;
        }

        int ret = 0;
        while(!digits.empty()){
            int d = digits.front();
            digits.pop();

            //overflow check
            if(ret > INT_MAX / 10
               || (ret == INT_MAX / 10 &&
                   ((sign == 1 && d > INT_MAX % 10) || (sign == -1 && d > INT_MAX % 10 + 1)))){
                       return 0;
            }

            ret = ret * 10 + d;
        }
        return ret;
    }

    int reverse2(int x){
        int r = 0;
        for(; x; x /= 10){
            r = r * 10 + x % 10;
        }
        return r;
    }
};

int main()
{
    cout<<INT_MAX % 10<<" "<<INT_MIN % 10<<endl;
    int a = 2147483649;
    cout<<a<<endl;
    Solution sln;
    cout<<sln.reverse(a)<<endl;
    return 0;
}
