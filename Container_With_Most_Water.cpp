#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        if(height.size() <= 1) return 0;

        const int n = height.size();
        int capacity = 0;
        int left = 0, right = n - 1;
        while(left < right){
            capacity = max(capacity, (right - left) * min(height[left], height[right]));
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return capacity;
    }
};

int main()
{
    vector<int> A({0, 2, 3, 1});
    Solution sln;
    cout<<sln.maxArea(A)<<endl;
    return 0;
}
