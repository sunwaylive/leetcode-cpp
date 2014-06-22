#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> &digits) {
    int length = digits.size();
    int carry = 1;
    for(int i = length-1; i >= 0; --i){
        int sum = digits[i] + carry;
        carry = sum / 10;
        digits[i] = sum % 10;
    }
    if(carry > 0)
        digits.insert(digits.begin(), carry);

    return digits;
}

int main()
{
    int A[] = {1, 0, 2, 3};
    vector<int> B(A, A + sizeof(A) / sizeof(A[0]));
    vector<int> result;
    result = plusOne(B);
    for(int i = 0; i < B.size(); i++)
        cout<< B[i] <<" ";
    cout<<endl;
    return 0;
}
