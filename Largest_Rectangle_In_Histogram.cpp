#include <iostream>
#include <vector>
#include <stack>
using namespace std;

using namespace std;

//http://blog.csdn.net/doc_sgl/article/details/11805519
//栈中留存的元素都是目前为止比较小的元素,栈中只保留递增序列, 且是直方图的index
//O(n) solution
int largestRectangleArea(vector<int> &height) {
    stack<int> stk;
    height.push_back(0); //manually add a zero for termination
    int maxArea = 0;
    for(int i = 0; i < height.size();){
        if(stk.empty() || height[i] > height[stk.top()]){
            stk.push(i);
            i++;
        }else{
            int tmp = stk.top();
            stk.pop();
            maxArea = max(maxArea, height[tmp] * (stk.empty() ? i : (i - stk.top() - 1)));
        }
    }
    return maxArea;
}

//O(n^2) solution
int largestRectangleArea2(vector<int> &height){
    if(height.empty()) return 0;

    height.insert(height.begin(), -1);
    height.push_back(-1);

    const int n = height.size();
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    for(int i = 0; i < n; ++i)
        left[i] = right[i] = i;

    //update left boundary
    for(int i = 1; i <= n - 3; ++i)
        while(height[i] <= height[left[i] - 1])//extend until the unqualified height
            left[i] = left[left[i] - 1];

    //update right boundary
    for(int i = n - 3; i >= 1; --i)
        while(height[i] <= height[right[i] + 1])
            right[i] = right[right[i] + 1];

    //calculate the max area
    int area = 0;
    for(int i = 1; i < n - 2; ++i){
        area = max(area, height[i] * (right[i] - left[i] + 1));
    }
    return area;
}

int main()
{
    int A[] = {2,1,3,4,2,3};
    vector<int> height(A, A + 6);
    cout<<largestRectangleArea2(height)<<endl;
    return 0;

}
