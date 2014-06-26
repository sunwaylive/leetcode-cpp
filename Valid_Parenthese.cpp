#include <iostream>
#include <stack>
using namespace std;

char map(char ch)
{
    switch(ch){
    case ')': return '(';
    case '}': return '{';
    case ']': return '[';
    default :return '\0';
    }
}

bool isValid(string s) {
    stack<char> stk;
    for(size_t i = 0; i < s.size(); ++i){
        if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
            if(!stk.empty()){
                if(stk.top() == map(s[i])) stk.pop();
            }else{
                return false;
            }
        }else stk.push(s[i]);
    }

    return stk.empty() ? true : false;
}

int main()
{
    string p = "([)]";
    cout<<isValid(p) <<endl;
    return 0;
}
