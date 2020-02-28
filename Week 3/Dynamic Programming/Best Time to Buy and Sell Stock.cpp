#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int profit=0, buy=prices[0], sell=prices[0], i=0;
        for(i=1; i<prices.size(); i++){
            if(prices[i]>sell) {
                sell = prices[i];
            } else if (prices[i]<buy) {
                if(profit < sell-buy) profit = sell-buy;
                buy = prices[i];
                sell = prices[i];
            }
        }
        if(profit < sell-buy) profit = sell-buy;
        return profit;
    }
};
