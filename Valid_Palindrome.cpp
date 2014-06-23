#include <iostream>
#include <string>
#include <ctype.h>
#include <algorithm>

using namespace std;

bool isPalindrome(string s) {
    if(s.empty()) return true;

    transform(s.begin(), s.end(), s.begin(), ::tolower);
    int low = 0, high = s.size() - 1;
    while(low < high){
        if(!isalnum(s[low]))
            low++;
        else if(!isalnum(s[high]))
            high--;
        else if(s[low] != s[high])
            return false;
        else{
            low++; high--;
        }
    }
    return true;
}

bool isPalindrome2(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    string::iterator left = s.begin(), right = prev(s.end());
    cout<<"left: "<<*left <<"right: "<< *right <<endl;
    while(left < right){
        if(!isalnum(*left)) left++;
        else if(!isalnum(*right)) right--;
        else if(*left != *right)
            return false;
        else { left++, right--; }
    }
    return true;
}


int main()
{
    string s("A man, a plan, a canasl: Panama");
    cout<< isPalindrome2(s) <<endl;
    return 0;
}
