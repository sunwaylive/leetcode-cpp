#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        dfs(0, 4, s, 0);
        return result;
    }

    void dfs(int curDep, int maxDep, string &s, int start){
        if(curDep == maxDep){
            if(start == s.size()){
                string addr;
                int begin = 0;
                for(int i = 0; i < maxDep; ++i){
                    string ip(s, begin, pos[i] - begin + 1);
                    begin = pos[i] + 1;
                    addr += (i == 0) ? ip : ("." + ip);
                }
                result.push_back(addr);
            }
        }else{
            for(int i = start; i < s.size(); ++i){
                if(check(s, start, i)){
                    pos[curDep] = i;
                    dfs(curDep + 1, maxDep, s, i + 1);
                }
            }
        }

    }

    bool check(string &s, int begin, int end){
        string ip(s, begin, end - begin + 1);
        if(ip.size() == 1){
            return ip >= "0" && ip <= "9";
        }else if(ip.size() == 2){
            return ip >= "10" && ip <= "99";
        }else if(ip.size() == 3){
            return ip >= "100" && ip <= "255";
        }else
            return false;
    }

private:
    int pos[4];
    vector<string> result;
};

int main()
{
    Solution sln;
    string s("25525511135");
    vector<string> ret = sln.restoreIpAddresses(s);
    cout<<ret.size() <<endl;
    return 0;
}
