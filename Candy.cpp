#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

//O(n) solution
int candy(vector<int> &ratings)
{
    const int n = ratings.size();
    vector<int> increment(n, 0);

    for(int i = 1, inc = 0; i < n; ++i){
        if(ratings[i] > ratings[i-1]) inc++;
        else inc = 0;

        increment[i] = max(increment[i], inc);
    }

    for(int i = n - 1, inc = 0; i > 0; --i){
        if(ratings[i-1] > ratings[i]) inc++;
        else inc = 0;

        increment[i-1] = max(increment[i-1], inc);
    }

    return accumulate(increment.begin(), increment.end(), n);
}

int main()
{
    int c[] = {1, 2, 3};
    vector<int> ratings(c, c + sizeof(c) / sizeof(c[0]));
    cout<< candy(ratings) <<endl;
    return 0;
}
