#include <iostream>

using namespace std;

//O(n^2) solution
string extend(string s, int l, int r)
{
    const int n = s.length();
    while(l >= 0 && r < n && s[l] == s[r]) { l--; r++; }
    return s.substr(l + 1, r - l - 1);
}

string longestPalindrome2(string s)
{
    const int n = s.length();
    if(n == 0) return "";
    string longest = s.substr(0, 1);
    for(int i = 0; i < n - 1; ++i){
        string p1 = extend(s, i, i);
        if(p1.length() > longest.length())
            longest = p1;

        string p2 = extend(s, i, i+1);
        if(p2.length() > longest.length())
            longest = p2;
    }
    return longest;
}

//O(n) solution
string preProcess(string s)
{
    int n = s.length();
    //add special char to make the comparison absolute fail
    if(n == 0) return "^$";

    string ret = "^";
    for(int i = 0; i < n; ++i)
        ret += "#" + s.substr(i, 1);

    ret += "#$";
    return ret;
}

//example: ^ # a # b # a # $
//         0 1 2 3 4 5 6 7 n-1
//explanation
//http://www.felix021.com/blog/read.php?2040
// C-i-R for easy memorization
string longestPalindrome(string s) {
    string T = preProcess(s);

    const int n = T.length();
    int P[n];
    memset(P, 0, n);
    int C = 0, R = 0;
    for(int i = 1; i < n - 1; ++i){
        P[i] = i < R  ? min(R - i, P[2*C - i]) : 1;

        //x - i + 1 = p[i] ---> x = i + p[i] - 1; so next is "i + p[i]"
        while(T[i + P[i]] == T[i - P[i]]) P[i]++;  // extend
        //update the R and C
        if(i + P[i] > R){
            R = i + P[i];
            C = i;
        }
    }

    int max_len = 0;
    int center_index = 0;

    for(int i = 1; i < n-1; ++i){
        if(P[i] > max_len){
            max_len = P[i];
            center_index = i;
        }
    }

    //p[i] - 1 : stores the longest palindrome substring
    return s.substr((center_index - max_len) / 2, max_len - 1);
}

int main()
{
    string s("12212321222567");
    cout<< longestPalindrome2(s) <<endl;
    return 0;
}
