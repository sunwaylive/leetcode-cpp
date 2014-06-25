#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs) {
    if(strs.empty()) return "";

    const int n = strs.size();
    int m = strs[0].size();
    for(int j = 0; j < m; ++j){
        for(int i = 1; i < n; ++i){
            if(strs[0][j] != strs[i][j])
                return strs[0].substr(0, j);
        }
    }
    return strs[0];
}

int main()
{

    return 0;
}
