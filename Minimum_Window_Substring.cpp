#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string minWindow(string S, string T){
        if(S.empty()|| S.size() < T.size())  return "";
        const int ASCII_MAX = 256;
        int appeared_count[ASCII_MAX];
        int expected_count[ASCII_MAX];
        fill(appeared_count, appeared_count + ASCII_MAX, 0);
        fill(expected_count, expected_count + ASCII_MAX, 0);

        for(int i = 0; i < T.size(); ++i)
            expected_count[T[i]]++;

        int minWidth = INT_MAX, min_start = 0;
        int wnd_start = 0, wnd_end = 0;
        int appeared = 0;
        //move the end point backward
        for(wnd_end = 0; wnd_end < S.size(); ++wnd_end){
            if(expected_count[S[wnd_end]] > 0){//if the char is part of T
                appeared_count[S[wnd_end]]++; //record the number of the char
                if(appeared_count[S[wnd_end]] <= expected_count[S[wnd_end]])//after the add up, if the appeared_count is larger than expected counts, then we shouldn't count it any more
                    appeared++;
            }

            if(appeared == T.size()){//if we have gotten the target string in this iteration
                //S[wnd_start] appear more or is not expected
                //shrink the start position
                while(appeared_count[S[wnd_start]] > expected_count[S[wnd_start]]
                      || expected_count[S[wnd_start]] == 0){
                    appeared_count[S[wnd_start]]--; //decrease the count of the char
                    wnd_start++;
                }//end while
                if(minWidth > (wnd_end - wnd_start + 1)){
                    minWidth = wnd_end - wnd_start + 1;
                    min_start = wnd_start;
                }
            }//end if
        }//end for

        if(minWidth == INT_MAX) return "";
        else return S.substr(min_start, minWidth);
    }
};

int main()
{
    string s("ADOBECODEBANC");
    string t("ABC");
    Solution sln;
    cout<<s<<endl;
    cout<<t<<endl;
    cout<<sln.minWindow(s, t)<<endl;
    return 0;
}
