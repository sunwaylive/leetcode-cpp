#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> result;
        const int n = words.size();
        int begin = 0, len = 0;
        //iterate words vector
        for(int i = 0; i < n; ++i){
            if(len + words[i].size() + (i - begin) > L){
                result.push_back(connect(words, begin, i - 1, len, L, false));
                begin = i;
                len = 0;
            }
            len += words[i].size();// letter length
        }

        result.push_back(connect(words, begin, n - 1, len, L, true));
        return result;
    }

    //len: words[begin, end], add up length, exclude the extra spaces between them
    //L: given line length
    string connect(vector<string> &words, int begin, int end, int len, int L, bool is_last){
        string s;
        int n = end - begin + 1;
        for(int i = 0; i < n; ++i){
            s += words[begin + i];
            addSpaces(s, i, n - 1, L - len, is_last); //L - len: means total spaces number
        }
        if(s.size() < L) s.append(L - s.size(), ' ');//add remain spaces
        return s;
    }

    //s: current line string, incremental
    //i: i-th gap
    //n: total gap number
    //sp_num: total extra spaces number
    //is_last:
    void addSpaces(string &s, int i, int n, int sp_num, bool is_last){
        if(n < 1 || i > n - 1) return;
        int spaces = is_last ? 1 : (sp_num / n + (i < (sp_num % n) ? 1 : 0));// % means: from begin to end, allocate as many as possible to the space gap
        s.append(spaces, ' ');
    }
};

int main()
{
    vector<string> words;
    words.push_back(string("This"));
    words.push_back(string("is"));
    words.push_back(string("an"));
    words.push_back(string("example"));
    words.push_back(string("of"));
    words.push_back(string("text"));
    words.push_back(string("justification"));

    Solution sln;
    vector<string> result;
    result = sln.fullJustify(words, 16);
    for(int i = 0; i < result.size(); ++i)
        cout<<result[i]<<endl;
    cout<<endl;
    return 0;
}
