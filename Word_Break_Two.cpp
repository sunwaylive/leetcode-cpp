#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> path;
        vector<string> allPaths;
        unordered_set<string> unmatchedMap;
        wordBreakUtil(s, dict, path, allPaths, unmatchedMap);
        return allPaths;
    }

    void wordBreakUtil(string s, unordered_set<string> &dict, vector<string> &path,
                       vector<string> &allPaths, unordered_set<string> &unmatchedMap){
        if(unmatchedMap.find(s) != unmatchedMap.end())//pruning
            return ;

        if(s.size() == 0 && path.size() != 0){
            string onePath;
            for(int i = 0; i < path.size(); ++i){
                onePath += (i == 0) ? path[i] : (" " + path[i]);
            }
            allPaths.push_back(onePath);
            return;
        }

        for(int i = 0; i < s.size(); ++i){
            string newWord = s.substr(0, i + 1);
            if(dict.find(newWord) != dict.end()){
                size_t oldSize = allPaths.size();
                path.push_back(newWord);
                string remainStr = s.substr(i + 1);
                wordBreakUtil(remainStr, dict, path, allPaths, unmatchedMap);
                path.pop_back();
                if(oldSize == allPaths.size())//this means cut at i-th pos in s, is unqualified
                    unmatchedMap.insert(remainStr);
            }
        }

    }
};

int main()
{
    Solution sln;
    string s("catsanddogs");
    unordered_set<string> dict;
    dict.insert("cats");
    dict.insert("and");
    dict.insert("dogs");
    dict.insert("sand");
    dict.insert("cat");

    vector<string> ret;
    ret = sln.wordBreak(s, dict);
    cout<<ret.size() <<endl;
    for(int i = 0; i < ret.size(); ++i)
        cout<<ret[i]<<endl;

    return 0;
}
