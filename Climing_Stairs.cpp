#include <iostream>

using namespace std;

int climbStairs(int n) {
    if(n == 1) return 1;
    if(n == 2) return 2;

    int a = 1, b = 2, c;
    for(int i = 3; i <= n; ++i){
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}

int main()
{
    cout<<climbStairs(3) <<endl;
    return 0;
}
