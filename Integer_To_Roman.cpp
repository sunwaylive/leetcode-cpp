#include <iostream>
using namespace std;

string intToRoman(int num) {
    const int radix[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL",
                              "X", "IX", "V", "IV", "I"};
    string rom;
    for(int i = 0; num > 0; ++i){
        int count = num / radix[i];
        num %= radix[i];
        for(; count > 0; --count) rom += symbols[i];
    }
    return rom;
}

int main()
{
    int num = 485;
    cout<<intToRoman(num)<<endl;
    return 0;
}
