#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    //http://www.cnblogs.com/remlostime/archive/2012/10/30/2746791.html
    int getF(int index){
        if(index < 0) return 1;
        else return f[index];
    }

    int numDecodings2(string s){
        if(s.empty()) return 0;

        f.resize(s.size());
        for(int i = 0; i < s.size(); ++i){
            f[i] = 0;
            if(i >= 1){
                string a(s, i - 1, 2);
                if("10" <= a && a <= "26")
                    f[i] += getF(i - 2);
                if(s[i] >= '1' && s[i] <= '9')
                    f[i] += getF(i - 1);
            }else{
                if(s[i] >= '1' && s[i] <= '9')
                    f[i] = 1;
            }//end else
        }//end for
        return f[f.size() - 1];
    }

private:
    vector<int> f;
};

int main()
{
    string s("12");
    Solution sln;
    cout<<sln.numDecodings2(s)<<endl;
    return 0;
}
