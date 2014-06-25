#include <iostream>
using namespace std;

inline int map(const char c)
{
    switch(c){
    case 'M': return 1000;
    case 'D': return 500;
    case 'C': return 100;
    case 'L': return 50;
    case 'X': return 10;
    case 'V': return 5;
    case 'I': return 1;
    default: return 0;
    }
}

//O(n) solution
int romanToInt(string s) {
    int result = 0;
    for(size_t i = 0; i < s.size(); ++i){
        if(i > 0 && map(s[i]) > map(s[i - 1]))
            //only two inverse successive letters at most
            result += (map(s[i]) - 2 * map(s[i-1]));//because we should minus what we have already added previous
        else
            result += map(s[i]);
    }
    return result;
}

int main()
{
    string roman("CD");
    cout<< romanToInt(roman) <<endl;
    return 0;
}
