#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.empty()) return 0;

        int profit = 0;
        int minPrice = prices[0];
        for(int i = 0; i < prices.size(); ++i){
            profit = max(profit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return profit;
    }
};

int main()
{
    Solution sln;
    vector<int> A({3, 2, 1, 0, 4});

    cout<<sln.maxProfit(A) <<endl;
    return 0;
}
