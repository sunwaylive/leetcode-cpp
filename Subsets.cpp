#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int> > ret;

public:
    void dfs(int curDep, int maxDep, vector<int> &set, vector<int> subset, int start){
        ret.push_back(subset);

        if(curDep > maxDep) return;
        for(int i = start; i < set.size(); ++i){
            vector<int> tmp(subset);
            tmp.push_back(set[i]);
            dfs(curDep + 1, maxDep, set, tmp, i + 1);
        }
    }

    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        ret.clear();
        vector<int> curSubset;
        dfs(0, S.size(), S, curSubset, 0);
        return ret;
    }

    //method 2
    vector<vector<int> > subsets2(vector<int> &S){
        sort(S.begin(), S.end());
        vector<bool> selected(S.size(), false);
        subsets3(S, selected, 0);
        return ret;
    }

    void subsets3(const vector<int> &S, vector<bool> &selected, int step){
        if(step == S.size()){
            vector<int> subset;
            for(int i = 0; i < selected.size(); ++i){
                if(selected[i]) subset.push_back(S[i]);
            }
            ret.push_back(subset);
            return;
        }else{
            selected[step] = false;
            subsets3(S, selected, step + 1);
            selected[step] = true;
            subsets3(S, selected, step + 1);
        }
    }

    //method 3, 二进制法
    vector<vector<int> > subsets4(vector<int> &S){
        const int n = S.size();
        vector<int> curSubset;
        for(int i = 0; i < (1 << n); ++i){
            for(int j = 0; j < n; ++j){
                if(i & (1 << j)) curSubset.push_back(S[j]);
            }
            ret.push_back(curSubset);
            curSubset.clear();
        }
        return ret;
    }
};

void printSubset(const vector<vector<int> > &s)
{
    for(int i = 0; i < s.size(); ++i){
        for(int j = 0; j < s[i].size(); ++j){
            cout<<s[i][j] <<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int A[] = {1, 2, 3};
    vector<int> S(A, A + sizeof(A) / sizeof(A[0]));
    vector<vector<int> > ret;
    Solution sln;
    ret = sln.subsets4(S);
    printSubset(ret);
    return 0;
}
