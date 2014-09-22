#include <iostream>
#include <stack>
#include <sstream>
#include <stack>
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

//************************************************************
void printWord(const char *s, int start, int end){
    for(int i = start; i <= end; ++i){
        cout<<s[i];
    }
}

void reverse(const char *s){
    const int len = strlen(s);
    int i = len - 1, j;
    while(i >= 0){
        //skip the spaces at the end
        while(s[i] == ' ') i--;
        if(i < 0) return ;
        //find the beginning of a word
        j = i;
        while(j >= 0 && s[j] != ' '){
            j--;
        }
        //print the word
        if(j < 0) {
            printWord(s, 0, i);
            return;
        }
        else{
            printWord(s, j + 1, i);
            cout<<" ";
            i = j;
        }
    }
}

//************************************************************
void reverse2(string &s){
    stringstream ss;
    ss<<s;

    stack<string> stk;
    string word;
    while(ss>>word){
        stk.push(word);
    }
    while(!stk.empty()){
        string tmp = stk.top();
        stk.pop();
        cout<<tmp<<" ";
    }
    cout<<endl;
    return ;
}

int main(void)
{
    string s("   the sky is    blue   ");
    reverse2(s);
    return 0;
}
