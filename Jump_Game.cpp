#include <iostream>
using namespace std;

class Solution {
public:
    //http://www.cnblogs.com/remlostime/archive/2012/11/12/2765894.html
    bool canJump2(int A[], int n){
        if(n == 0) return false;

        int step  = A[0];
        for(int i = 1; i < n; ++i){
            if(step > 0){
                step--;// move to A[i]
                step = max(step, A[i]);
            }else{
                return false;
            }
        }
        return true;
    }

    //Time Exceed Limit solution
    bool canJump(int A[], int n) {
        dfs(0, n - 1, A);
        return this->can;
    }

    void dfs(int start, int end, int A[]){
        if(start >= end)
            can = true;
        else{
            for(int i = 1; i <= A[start]; ++i){
                dfs(start + i, end, A);
            }
        }
    }
private:
    bool can;
};

int main()
{
    int A[] = {2, 3, 1, 1, 4};
    Solution sln;
    cout<<sln.canJump2(A,sizeof(A) / sizeof(A[0]))<<endl;
    return 0;
}
