#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        int sum = 0;
        dfs(0, candidates, target, sum, path);
        return result;
    }

    //iterative and recursive paradigm
    void dfs(int start, vector<int> &candidates, int &target, int &sum, vector<int> &path){
        if(sum > target || start >= candidates.size()) return;

        if(sum == target){
            result.push_back(path);
        }else{
            for(int i = start; i < candidates.size(); ++i){
                sum += candidates[i];
                path.push_back(candidates[i]);
                dfs(i, candidates, target, sum, path);
                path.pop_back();
                sum -= candidates[i];
            }
        }
    }

private:
    vector<vector<int> > result;
};

int main()
{
    int A[] = {2, 3, 6, 7};

    vector<int> candidates(A, A + sizeof(A) / sizeof(A[0]));
    Solution sln;
    vector<vector<int> > ret = sln.combinationSum(candidates, 7);
    for(int i = 0; i < ret.size(); ++i){
        for(int j = 0; j < ret[i].size(); ++j){
            cout<<ret[i][j] <<" ";
        }
        cout<<endl;
    }
    cout<<ret.size() <<endl;
    return 0;
}
