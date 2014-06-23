#include <iostream>

using namespace std;

string addBinary(string a, string b) {
    int na = a.size();
    int nb = b.size();
    int i = na-1, j = nb-1;
    string ret;
    int carry = 0;
    int sum = 0;

    while(i >= 0 && j >= 0){
        sum = (a[i] - '0') + (b[j] - '0') + carry;
        carry = sum / 2;
        ret.insert(ret.begin(), sum % 2 + '0');
        //cout<<ret<<endl;
        i--, j--;
    }

    while(i >= 0){
        sum = a[i] - '0' + carry;
        carry = sum / 2;
        ret.insert(ret.begin(), sum % 2 + '0');
        i--;
    }

    while(j >= 0){
        sum = b[j] - '0' + carry;
        carry = sum / 2;
        ret.insert(ret.begin(), sum % 2 + '0');
        j--;
    }

    if(carry > 0)
        ret.insert(ret.begin(), carry+ '0');

    return ret;
}

int main()
{
    string a("11"), b("10");
    cout<<addBinary(a, b) <<endl;
    return 0;
}
