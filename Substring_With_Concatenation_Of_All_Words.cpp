#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

//http://www.myexception.cn/program/1673583.html
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        map<string, int> words, cur;
        int wordNum = L.size();
        for(int i = 0; i < wordNum; ++i)
            words[L[i]]++;

        int wordLen = L[0].size(); // all words have the same length
        vector<int> res;
        for(int i = 0; i <= (int)(S.size() - wordLen * wordNum); ++i){ // pruning
            cur.clear();
            int j;
            for(j = 0; j < wordNum; ++j){
                string word = S.substr(i + j * wordLen, wordLen);
                if(words.find(word) == words.end())
                    break;

                cur[word]++;

                if(cur[word] > words[word])
                    break;
            }
            if(j == wordNum)
                res.push_back(i);
        }
        return res;
    }
};

int main()
{
    string s("barfoothefoobarman");
    vector<string> l;
    l.push_back(string("bar"));
    l.push_back(string("foo"));
    Solution sln;
    vector<int> ret = sln.findSubstring(s, l);
    for(int i = 0; i < ret.size(); ++i)
        cout<<ret[i]<<" ";
    cout<<endl;
    return 0;
}
