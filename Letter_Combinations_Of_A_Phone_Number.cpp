#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
private:
    vector<string> ret;
    map<char, vector<char> > dict;
public:
    void dfs(int curDep, int maxDep, string &digits, string ans){
        if(curDep == maxDep){
            ret.push_back(ans);
        }else{
            for(int i = 0; i < dict[digits[curDep]].size(); ++i)
                dfs(curDep + 1, maxDep, digits, ans + dict[digits[curDep]][i]);
        }
    }

    vector<string> letterCombinations(string digits) {
        ret.clear();
        createDict();
        dfs(0, digits.size(), digits, "");
        return ret;
    }

    void createDict()
     {
         dict.clear();
         dict['2'].push_back('a');
         dict['2'].push_back('b');
         dict['2'].push_back('c');
         dict['3'].push_back('d');
         dict['3'].push_back('e');
         dict['3'].push_back('f');
         dict['4'].push_back('g');
         dict['4'].push_back('h');
         dict['4'].push_back('i');
         dict['5'].push_back('j');
         dict['5'].push_back('k');
         dict['5'].push_back('l');
         dict['6'].push_back('m');
         dict['6'].push_back('n');
         dict['6'].push_back('o');
         dict['7'].push_back('p');
         dict['7'].push_back('q');
         dict['7'].push_back('r');
         dict['7'].push_back('s');
         dict['8'].push_back('t');
         dict['8'].push_back('u');
         dict['8'].push_back('v');
         dict['9'].push_back('w');
         dict['9'].push_back('x');
         dict['9'].push_back('y');
         dict['9'].push_back('z');
     }
};

int main()
{
    string digits("23");
    Solution sln;

    vector<string> result;
    result = sln.letterCombinations(digits);
    for(int i = 0; i < result.size(); ++i){
        cout<<result[i] <<endl;
    }
    return 0;
}
