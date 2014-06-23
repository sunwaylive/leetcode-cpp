#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(int x) {
    vector<int> w;
    if(x < 0) return false;

    while(x > 0){
        w.push_back(x % 10);
        x = x / 10;
    }

    int low = 0, high = w.size() - 1;
    while(low < high){
        if(w[low] != w[high])
            return false;
        else low++, high--;
    }
    return true;
}

int main()
{
    int a = -2147483648;
    cout<<isPalindrome(a)<<endl;
    return 0;
}
