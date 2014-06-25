#include <iostream>
using namespace std;

int lengthOfLastWord(const char *s) {
    const int n = strlen(s);
    int length = 0;

    for(int i = 0; i < n; ++i){
        if(s[i] != ' ') length++;
        else if(i+1 < n && s[i+1] != ' ') length = 0;
    }
    return length;
}

int main()
{
    char s[] = "hello world";
    cout<<lengthOfLastWord(s) <<endl;
    return 0;
}
