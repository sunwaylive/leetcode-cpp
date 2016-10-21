#include <iostream>
#include <string>
#include <stack>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> num;
        stack<string> ops;
        string res = "";

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '[') {
                ops.push(string(1, s[i]));
            } else if (s[i] == ']') {
                string repeat_str = "";
                while (!ops.empty()) {
                    if (ops.top().size() > 1 || ops.top() != "[") {
                        repeat_str.insert(0, ops.top().c_str()); // insert(pos, num, char)
                        ops.pop();
                    } else {
                        // top is '['
                        ops.pop();
                        break;
                    }
                }
                // cout << "****" << endl;
                // cout << repeat_str << endl;

                int repeat_cnt = 0;
                if (!num.empty()) {
                    repeat_cnt = num.top();
                    num.pop();
                }
                // cout << repeat_cnt << endl;
                // cout << "****" << endl;

                string tmp = "";
                while(repeat_cnt-- > 0) {
                    tmp += repeat_str;
                }

                ops.push(tmp);
            } else if (s[i] >= '0' && s[i] <= '9'){
                // "33"
                int start = i, end = start + 1;
                while (s[end] >= '0' && s[end] <= '9') {
                    end++;
                }
                end = end - 1;
                string cnt_str = s.substr(i, end - start + 1);
                // cout << "cnt_str: " << cnt_str << endl;
                int tmp = strtol(cnt_str.c_str(), NULL, 10);
                // cout << "tmp: "  << tmp << endl;
                num.push(tmp);

                // for loop will add 1
                i = end;
            } else {
                ops.push(string(1, s[i]));
            }
        }

        while (!ops.empty()) {
            res.insert(0, ops.top().c_str());
            ops.pop();
        }

        return res;
    }
};

int main() {
    string str1("3[a2[c]]");
    string str2("2[abc]3[cd]ef");
    Solution sln;
    cout << sln.decodeString(str1) << endl;
    cout << sln.decodeString(str2) << endl;
    return 0;
}
