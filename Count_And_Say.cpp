#include <iostream>

using namespace std;

string revolution(string s)
{
    const int n = s.length();
    char pre = s[0];
    string ret;
    int count = 1;

    for(int i = 1; i < n; ++i){
        if(s[i] == pre) count++;
        else {
            char temp = count + '0';
            ret = ret + temp + pre;
            //reset the pre and count for next char
            pre = s[i];
            count = 1;
        }
    }
    char temp = count + '0';
    ret = ret + temp + pre;
    return ret;
}


//not perfect code
string revolution2(string s)
{
    const int n = s.length();
    char pre = s[0];
    string ret;
    int count = 1;
    for(int i = 1; i < n; ){
        //bad habit to modify loop variable inside for loop
        while(i < n && s[i] == pre){
            count++;
            i++;
        }
        //if i == n, then out of range
        if(i >= n) break;

        char temp = count + '0';
        ret = ret + temp + pre;
        pre = s[i];
        count = 1;
    }

    char temp = count + '0';
    ret = ret + temp + pre;
    return ret;
}

string countAndSay(int n) {
    string ret = "1";
    while(--n){
        ret = revolution(ret);
    }
    return ret;
}

int main()
{
    int n = 3;
    cout<<"countAndsay: "<<countAndSay(n) <<endl;
    return 0;
}
