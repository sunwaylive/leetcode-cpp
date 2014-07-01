#include <iostream>
#include <vector>
#include <stack>
using namespace std;

using namespace std;

//http://blog.csdn.net/doc_sgl/article/details/11805519
//栈中留存的元素都是目前为止比较小的元素
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

int main()
{
    int A[] = {2,1,3,4,2,3};
    vector<int> height(A, A + 6);
    cout<<largestRectangleArea(height)<<endl;
    return 0;

}
