#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//please google: 格雷码
//binary code ---> gray code:
//g[0] = b[0]; g[i] = b[i] ^ b[i-1]

//gray code ---> binary code:
//b[0] = g[0]; b[i] = g[i] ^ b[i-1]

vector<int> grayCode(int n) {
    vector<int> result;
    int a = pow(2, n);
    for(int i = 0; i < a; ++i)
        result.push_back(i ^ (i / 2));
    return result;
}

int main()
{
    //double n = 1;
    vector<int> result;
    int n = 2;
    result = grayCode(n);
    for(int i = 0; i < result.size(); ++i)
        cout<<result[i]<<" ";
    cout<<endl;
    return 0;
}
