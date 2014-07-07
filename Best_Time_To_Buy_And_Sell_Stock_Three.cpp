#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.empty()) return 0;

        const int n = prices.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);

        //compute left(first) transaction
        int valley = prices[0];
        for(int i = 1; i < n; ++i){
            valley = min(valley, prices[i]);
            left[i] = max(prices[i] - valley, left[i - 1]);
        }

        //compute right(second) transaction
        int peak = prices[n - 1];
        for(int i = n - 2; i >= 0; --i){
            peak = max(peak, prices[i]);
            right[i] = max(peak - prices[i], right[i]);
        }

        int profit = 0;
        for(int i = 0; i < n; ++i){
            profit = max(profit, left[i] + right[i]);
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
