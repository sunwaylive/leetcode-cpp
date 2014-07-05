#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        unordered_set<string> current, next, visited;
        unordered_map<string, vector<string> > father;
        bool found = false;

        //define two functions
        auto state_is_target = [&](const string &s){ return s == end; };
        auto state_extend = [&](const string &s){
            unordered_set<string> result;
            for(int i = 0; i < s.size(); ++i){
                string new_word(s);
                for(char c = 'a'; c <= 'z'; ++c){
                    if(c == new_word[i]) continue;//skip duplicate letter

                    swap(new_word[i], c);
                    if(dict.count(new_word) > 0 && visited.count(new_word) == 0)
                        result.insert(new_word);
                    if(new_word == end && visited.count(new_word) == 0)//end may not in the dict
                        result.insert(new_word);
                    swap(c, new_word[i]);
                }
            }
            return result;
        };

        current.insert(start);
        while(!current.empty() && !found){
            //avoid state transition on the same level
            for(const auto &word : current)
                visited.insert(word);

            for(const auto &word : current){
                const auto new_states = state_extend(word);//get the all next words
                for(const auto &state : new_states){
                    if(state_is_target(state)) found = true;
                    next.insert(state);
                    father[state].push_back(word);//store the father node
                }
            }
            current.clear();
            swap(current, next);
        }//end while

        vector<vector<string> > result;
        if(found){
            vector<string> path;
            gen_path(father, path, start, end, result);
        }
        return result;
    }

    void gen_path(unordered_map<string, vector<string> > &father, vector<string> &path,
                  const string &start, const string &end, vector<vector<string> > &result){
        path.push_back(end);
        //cout<<end<<endl;
        if(end == start){
            result.push_back(path);
            reverse(result.back().begin(), result.back().end());
        }else{
            for(const auto &f : father[end]){
                gen_path(father, path, start, f, result);
            }
        }
        path.pop_back();
    }
};


int main()
{
    string start("hit") ,end("cog");
    unordered_set<string> dict;
    dict.insert(string("hot"));
    dict.insert(string("dot"));
    dict.insert(string("dog"));
    dict.insert(string("lot"));
    dict.insert(string("log"));

    Solution sln;
    vector<vector<string> > result;
    result = sln.findLadders(start, end, dict);
    for(int i = 0; i < result.size(); ++i){
        for(int j = 0; j < result[i].size(); ++j){
            cout<<result[i][j] <<" ";
        }
        cout<<endl;
    }
    return 0;
}
