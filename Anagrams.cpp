#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> anagrams(vector<string> &strs) {
    unordered_map<string, vector<string> > hash;
    typedef unordered_map<string, vector<string> >::iterator UMI;
    const int n = strs.size();
    for(int i = 0; i < n; ++i){
        string key = strs[i];
        sort(key.begin(), key.end());
        hash[key].push_back(strs[i]);
    }

    vector<string> result;
    for(UMI iter = hash.begin(); iter != hash.end(); ++iter){
        if(iter->second.size() > 1){
            result.insert(result.end(), iter->second.begin(), iter->second.end());
        }
    }
    return result;
}

int main()
{
    vector<string> strs;
    strs.push_back(string("dirtyroom"));
    strs.push_back(string("idrtyroom"));
    vector<string> result;
    result = anagrams(strs);
    cout<<result.size() <<endl;
    return 0;
}
