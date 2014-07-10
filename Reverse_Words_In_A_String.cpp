#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    void reverseWords(string &s)
    {
        if(s.size() == 0 || s.size() == 1) return;
        stack<string> strStack;
        string::iterator it = s.begin();
        // remove the space before the word begins
        string word;
        for(; it != s.end(); )
        {
            while(*it == ' ') it++;
            while( it != s.end() && *it != ' ')
                word += *it++;
            if(!word.empty())
                strStack.push(word);
            word.clear();
        }
        s.clear();
        while(!strStack.empty())
        {
            s += strStack.top() + ' ';
            strStack.pop();
        }
        s = s.substr(0, s.size() - 1);
    }
};

int main(void)
{
    Solution s;
    string  test = "   the sky is    blue  ";
    s.reverseWords(test);
    cout<<test<<endl;
    return 0;
}
