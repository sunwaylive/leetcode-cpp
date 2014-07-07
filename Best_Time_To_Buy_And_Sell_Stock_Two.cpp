#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.empty()) return 0;

        int profit = 0;
        for(int i = 1; i < prices.size(); ++i){
            if(prices[i] > prices[i-1])
                profit += (prices[i] - prices[i-1]);
        }
        return profit;
    }
};

int main()
{
    Solution sln;
    vector<int> A({3, 8, 1, 0, 4});

    cout<<sln.maxProfit(A) <<endl;
    return 0;
}
