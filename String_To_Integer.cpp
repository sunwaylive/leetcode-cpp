#include <iostream>

using namespace std;

int atoi(const char *str) {
    const int n = strlen(str);
    int number = 0;
    int sign = 1;
    int i = 0;

    while(i < n && str[i] == ' ' ) i++;// hidden bug

    if(i < n){
        if(str[i] == '+') i++;
        else if(str[i] == '-') { sign = -1; i++; }
    }else {
        return number * sign;
    }

    for(; i < n; ++i){
        if(str[i] < '0' || str[i] > '9') break;
        //number overflow check
        if(number > INT_MAX / 10 ||
           ((number == INT_MAX / 10 ) && (str[i] - '0' > INT_MAX % 10)) ){
            return sign == -1 ? INT_MIN : INT_MAX;
        }
        //cout<<"str[i]: " << str[i] <<endl;
        number = number * 10 + str[i] - '0';
    }

    return number * sign;
}

int atoi2(const char *str)
{
    const int n = strlen(str);
    int sign = 1;
    int num = 0;

    int i = 0;
    while(str[i] == ' ' && i < n) {  cout<<i<<" "; i++; }
    cout<<"i: "<<i <<" n: "<<n <<endl;
    cout<<"visit str[n]: "<< str[n] <<endl;
    if(str[i] == '+') i++;
    if(str[i] == '-'){
        sign = -1;
        i++;
    }

    for(; i < n; i++){
        if(str[i] < '0' || str[i] > '9') break;

        if(num > INT_MAX / 10 ||
           ((num == INT_MAX / 10) && (num > INT_MAX % 10))){
            return sign == -1 ? INT_MIN : INT_MAX;
        }
        num = num * 10 + str[i] - '0';
    }
    return num * sign;
}

int main()
{
    char *a = "-2147483647";
    cout<<"atoi: "<< atoi(a) <<endl;
    //cout<<"atoi2: "<<atoi2(a) <<endl;
    return 0;
}
