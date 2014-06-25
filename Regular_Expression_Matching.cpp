#include <iostream>
using namespace std;

bool isMatch(const char *s, const char *p) {
    if(*p == '\0') return *s == '\0';
    //if p's next char isn't *
    if(*(p+1) != '*'){
        if(*p == *s || (*p == '.' && *s != '\0'))
            return isMatch(s+1, p+1);
        else return false;
    }else {//if next is '*'
        while(*p == *s || (*p == '.' && *s != '\0')){
            if(isMatch(s, p+2)) return true;
            s++;
        }
        return isMatch(s, p+2);
    }
}

int main()
{
    cout<<isMatch("abeffd", "?b*d")<<endl;
    return 0;
}
