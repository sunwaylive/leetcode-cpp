#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    //first time
    string multiply(string num1, string num2) {
        if(num1.size() == 0 || num2.size() == 0) return "";

        string ans(num1.size() + num2.size() + 1, '0'); //length of ans can't be longer
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for(int idx2 = 0; idx2 < num2.size(); ++idx2){//simulate multiply, so num2
            int digit2 = num2[idx2] - '0';
            int carry = 0;
            for(int idx1 = 0; idx1 < num1.size(); ++idx1){
                int digit1 = num1[idx1] - '0';
                int tmp = ans[idx1 + idx2] - '0';
                int sum_cur = carry + digit1 * digit2 + tmp;
                ans[idx1 + idx2] = sum_cur % 10 + '0';//key point, target pos in ans
                carry = sum_cur / 10;
            }//end for
            ans[idx2 + num1.size()] = carry + '0';// possible extra bit because of carry;
        }//end for
        reverse(ans.begin(), ans.end());

        int posStart = ans.find_first_not_of('0');
        if(posStart < 0 || posStart >= ans.size())
            posStart = ans.size() - 1;

        int len = ans.size() - posStart;
        return ans.substr(posStart, len);
    }

    //second time
    string multiply2(string num1, string num2){
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int carry = 0;
        string result;
        for(int len = 0; ; ++len){
            int sum = 0;
            bool flag = false;
            for(int i = 0; i < num1.size(); ++i){
                int j = len - i;
                if(j < 0 || j >= num2.size()) continue;

                sum += (num1[i] - '0') * (num2[j] - '0');
                flag = true;
            }//end for

            if(!flag) break;
            sum += carry;
            result.push_back(sum % 10 + '0');
            carry = sum / 10;
        }//end for

        while(carry > 0){
            result.push_back(carry % 10 + '0');
            carry /= 10;
        }

        reverse(result.begin(), result.end());
        if(result.find_first_not_of('0') == string::npos) return "0";
        else result.substr(result.find_first_not_of('0'), result.size() - result.find_first_not_of('0'));
    }
};

int main()
{
    return 0;
}
