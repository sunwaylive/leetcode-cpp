#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int ASCII_MAX = 1000;
        int last[ASCII_MAX];
        fill(last, last + ASCII_MAX, -1);

        int start = 0;
        int max_len = 0;
        for(int i = 0; i < s.size(); ++i){
            //example: q p x r j x k l z y p
            if(last[s[i]] >= start){//here must be start, we should skip those duplicate letter before start;
                max_len = max(max_len, i - start);
                start = last[s[i]] + 1;
            }
            last[s[i]] = i;
        }

        return max(max_len, (int)s.size() - start);
    }
};

int main()
{
    Solution sln;
    string s("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco");
    cout<<sln.lengthOfLongestSubstring(s)<<endl;
    return 0;
}
