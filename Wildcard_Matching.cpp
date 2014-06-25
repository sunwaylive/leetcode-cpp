#include <iostream>
using namespace std;

//* can represent any char, they those char don't have to be the same;
bool isMatch2(const char *s, const char *p) {
    const char* star=NULL;
    const char* ss=s;
    while (*s){
        if ( (*p=='?') || (*p==*s)){ s++; p++; continue; }
        if (*p=='*'){ star = p++; ss = s; continue; }
        if (star){ p = star + 1; s = ++ss; continue; }
        return false;
    }
    while (*p=='*'){ p++; }
    return !*p;
}

int main()
{
    cout<<isMatch2("abeffd", "?b*d")<<endl;
    return 0;
}
