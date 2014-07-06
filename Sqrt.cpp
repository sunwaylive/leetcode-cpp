#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    //牛顿迭代法
    int sqrt(int x) {
        double ans = 1;
        while(abs(ans * ans - x) > 1e-4){
            ans = (ans + x / ans) / 2;
        }
        return ans;
    }
};

int main()
{
    Solution sln;
    cout<<sln.sqrt(4)<<endl;
    return 0;
}
