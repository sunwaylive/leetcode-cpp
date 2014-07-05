#include <iostream>
#include <queue>
#include <unordered_set>
#include <string>
using namespace std;


//http://blog.csdn.net/zxzxy1988/article/details/8591890
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(start.empty() || end.empty()) return 1;
        if(dict.empty()) return 0;

        int distance = 1;
        queue<string> current, next;
        current.push(start);
        while(!current.empty()){
            while(!current.empty()){
                string str(current.front());
                current.pop();

                for(int i = 0; i < str.size(); ++i){//for each letter in the str
                    for(char j = 'a'; j <= 'z'; ++j){
                        if(j == str[i]) continue;
                        string tmp = str;
                        str[i] = j;
                        if(str == end)
                            return distance + 1;
                        //check if new string exist in the dict
                        if(dict.count(str) > 0){
                            next.push(str);
                            dict.erase(str);
                        }
                        str = tmp;
                    }
                }
            }
            swap(next, current);//current is empty(),so after swap next is sure to be empty
            distance ++;
        }
        return 0;
    }
};

int main()
{
    string start("hot");
    string end("dog");
    unordered_set<string> dict;
    dict.insert("hot");
    //dict.insert("dot");
    dict.insert("dog");
    //dict.insert("lot");
    //dict.insert("log");

    Solution sln;
    cout<<sln.ladderLength(start, end, dict) <<endl;
    return 0;
}
