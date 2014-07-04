#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        set<vector<int> > result;
        const int n = S.size();
        vector<int> curSubset;

        for(int i = 0; i < (1 << n); ++i){
            for(int j = 0; j < n; ++j){
                if(i & (1 << j)) curSubset.push_back(S[j]);
            }
            result.insert(curSubset);
            curSubset.clear();
        }

        vector<vector<int> > ret;
        copy(result.begin(), result.end(), back_inserter(ret));
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
    int A[] = {4, 1, 0};
    vector<int> S(A, A + sizeof(A) / sizeof(A[0]));
    vector<vector<int> > ret;
    Solution sln;
    ret = sln.subsetsWithDup(S);
    printSubset(ret);
    return 0;
}
