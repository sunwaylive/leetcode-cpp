#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<int> path;
        int sum = 0;
        dfs(0, num, target, sum, path);
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }

    void dfs(int start, vector<int> &candidates, int &target, int &sum, vector<int> &path){
        if(sum > target){
            return;
        }else if(sum == target){
            result.push_back(path);
        }else{
            for(int i = start; i < candidates.size(); ++i){
                sum += candidates[i];
                path.push_back(candidates[i]);
                dfs(i + 1, candidates, target, sum, path);
                sum -= candidates[i];
                path.pop_back();
            }
        }
    }
private:
    vector<vector<int> > result;
};

int main()
{
    int A[] = {1};
    vector<int> num(A, A + sizeof(A) / sizeof(A[0]));
    Solution sln;
    vector<vector<int> > ret = sln.combinationSum2(num, 1);
    cout<<ret.size() <<endl;
    return 0;
}
