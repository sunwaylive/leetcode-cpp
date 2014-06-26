#include <iostream>
#include <stack>
using namespace std;

int longestValidParentheses(string s) {
    stack<int> lefts;
    int longest = 0;
    int last = -1;
    for(int i = 0; i < s.length(); ++i){
        if(s[i] == '(') lefts.push(i);
        else{//')'
            if(lefts.empty()) last = i;//only used when we can't access lefts.top()
            else{//find a match
                lefts.pop();
                if(lefts.empty()) longest = max(longest, i - last);// lefts.top() doesn't exist
                else longest = max(longest, i - lefts.top());
            }
        }
    }
    return longest;
}

int main()
{
    string p = ")()())";
    cout<< longestValidParentheses(p)<<endl;
    return 0;
}
