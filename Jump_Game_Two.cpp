#include <iostream>
using namespace std;

class Solution {
public:
    int jump(int A[], int n) {
        int result = 0;
        int last = 0, cur = 0;
        for(int i = 0; i < n; ++i){
            if(i > last){
                last = cur;
                ++result;
            }
            cur = max(cur, i + A[i]);
        }
        return result;
    }
};

int main()
{
    int A[] = {2, 3, 1, 1, 4};
    Solution sln;
    cout<<sln.jump(A,sizeof(A) / sizeof(A[0]))<<endl;
    return 0;
}
