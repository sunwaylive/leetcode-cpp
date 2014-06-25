#include <iostream>
using namespace std;

bool isNumber(const char *s) {
    char *endptr;
    strtod(s, &endptr)
    if(s == endptr) return false;

    for(; *endptr; endptr++){
        if(*endptr != ' ')
            return false;
    }
    return true;
}

int main()
{
    char num[] = "2e10  ";
    cout<< isNumber(num) <<endl;
    return 0;
}
