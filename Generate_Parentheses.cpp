#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string paren;
        dfs(0, 2 * n, 0, 0, paren);
        return this->result;
    }

    void dfs(int curDep, int maxDep, int l, int r, string &paren){
        if(curDep == maxDep){
            result.push_back(paren);
        }else if(l >= maxDep / 2){
            paren += ")";
            dfs(curDep + 1, maxDep, l, r + 1, paren);
            paren.pop_back();
        }else if(r >= l){
            paren += "(";
            dfs(curDep + 1, maxDep, l + 1, r, paren);
            paren.pop_back();
        }else{
            paren += ")";
            dfs(curDep + 1, maxDep, l, r + 1, paren);
            paren.pop_back();

            paren += "(";
            dfs(curDep + 1, maxDep, l + 1, r, paren);
            paren.pop_back();
        }
    }

private:
    vector<string> result;
};

int main()
{
    Solution sln;
    vector<string> ret;
    ret = sln.generateParenthesis(3);
    for(int i = 0; i < ret.size(); ++i){
        cout<<ret[i] <<endl;
    }
    cout<<ret.size() <<endl;
    return 0;
}
