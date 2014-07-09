#include <iostream>
#include <string>
using namespace std;

//http://blog.csdn.net/zhouworld16/article/details/14121477
class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows <= 1 || s.size() == 0)
            return s;

        string res;
        int len = s.size();
        for(int i = 0; i < len && i < nRows; ++i){
            int idx = i;
            res += s[idx];//i < nRows means the first column, assign to all of them
            for(int k = 1; idx < len; ++k){//we start from the second column
                //first line and the last line
                if(i == 0 || i == nRows - 1)
                    idx += 2 * nRows - 2;
                else{// inner rows
                    if(k & 0x1)
                        idx += 2 * (nRows - i -1);
                    else
                        idx += 2 * i;
                }

                if(idx < len)
                    res += s[idx];
            }//end for for
        }//end for for
        return res;
    }
};

int main()
{
    string s("PAYPALISHIRING");
    Solution sln;
    cout<<sln.convert(s, 3)<<endl;
    return 0;
}
